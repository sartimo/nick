
use std::env;
use std::fs;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("Usage: {} init <project_name> [--path <directory_path>]", args[0]);
        return;
    }

    let command = &args[1];
    let project_name = &args[2];

    match command.as_str() {
        "init" => {
            if args.contains(&String::from("--path")) {
                if let Some(path_index) = args.iter().position(|x| x == "--path") {
                    if let Some(custom_path) = args.get(path_index + 1) {
                        init_action_with_custom_path(project_name, custom_path);
                    } else {
                        println!("Invalid usage of --path flag");
                    }
                }
            } else {
                init_action(project_name);
            }
        }
        _ => {
            println!("Unknown command: {}", command);
        }
    }
}

fn init_action(project_name: &str) {
    if fs::create_dir(project_name).is_ok() {
        println!("Created directory: {}", project_name);
    } else {
        println!("Failed to create directory: {}", project_name);
    }
}

fn init_action_with_custom_path(project_name: &str, custom_path: &str) {
    let full_path = format!("{}/{}", custom_path, project_name);
    if fs::create_dir_all(&full_path).is_ok() {
        println!("Created directory: {}", full_path);
    } else {
        println!("Failed to create directory: {}", full_path);
    }
}

