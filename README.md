# Choose Your Own Adventure

This is the template for the CYOA project. There are two folders
and a C header file here.

## basic
Contains the text files for the states of the CYOA story. These
can be displayed as-is to the user.

## advanced
Contains the same text files as for the basic version, but the transitions
are embedded in the choices. Your program will need to parse (decode)
these lines to extract the transition information. The transitions
themselves are not shown to the user.

## ansi-colors.h

ANSI escape codes for adding color to your program.
Contains a new defintion for CLRSCR that will clear the terminal screen.
