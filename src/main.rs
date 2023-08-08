use clap::{App, Arg};
use std::fs;
use std::path::Path;

fn main() {
    let matches = App::new("Your CLI Tool")
        .about("A description of your CLI tool")
        .version("1.0")
        .author("Your Name")
        .subcommand(
            App::new("init")
                .about("Initialize a new project")
                .arg(
                    Arg::new("project_name")
                        .about("Name of the project")
                        .required(true),
                )
                .arg(
                    Arg::new("path")
                        .about("Custom path for the project")
                        .short('p')
                        .long("path")
                        .takes_value(true),
                ),
        )
        // Add more subcommands here
        .get_matches();

    if let Some(init_matches) = matches.subcommand_matches("init") {
        let project_name = init_matches.value_of("project_name").unwrap();
        let custom_path = init_matches.value_of("path").unwrap_or(".");

        init_action(project_name, custom_path);
    } else {
        // Handle other subcommands here
        println!("Unknown command. Use '--help' for available commands.");
    }
}

fn init_action(project_name: &str, custom_path: &str) {
    let full_path = format!("{}/{}", custom_path, project_name);

    if fs::create_dir(&full_path).is_ok() {
        println!("Created project directory: {}", full_path);

        let subdirs = ["src", "test"];

        for subdir in subdirs.iter() {
            let subdir_path = Path::new(&full_path).join(subdir);
            if fs::create_dir(&subdir_path).is_ok() {
                println!("Created subdirectory: {}", subdir_path.display());
            } else {
                println!("Failed to create subdirectory: {}", subdir_path.display());
            }
        }

        let circuit_file_path = Path::new(&full_path).join("src/circuit.circom");
        if fs::write(&circuit_file_path, "").is_ok() {
            println!("Created circuit file: {}", circuit_file_path.display());
        } else {
            println!("Failed to create circuit file: {}", circuit_file_path.display());
        }
    } else {
        println!("Failed to create project directory: {}", full_path);
    }
}
