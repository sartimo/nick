# Intercal-SDL
A fork of the C-Intercal compiler (v 0.30) that links with SDL. I just changed 3 lines in perpet.c

The SDL bindings I made are minimal (only enough to clear the screen and draw a line) so you will have to make your own. Then just:

`./ick -e (Your Intercal Source).i (Your SDL Bindings).c`

The SDL Bindings have to be C source, not object or assembly.
