# GTCInterface
Graphical Terminal Control Interface for Linux  

This library aims to bring the majority of the normal Terminal controls  
to your CLI program plus a few extras that I felt were missing.  

Call `gtci::interface::getline()` to retrieve input from stdin (blocking).  

Call `gtci::interface::printLn()` to print to stdout. You can only print  
full lines at a time.  
Printing any other way may cause undefined behavior.  

Pressing tab will call the callback that was passed in the constructor.  

Most of the non-essential key combos are virtual functions, for easy  
customization. All modifiers (`SHIFT`, `ALT`, and `CTRL`) are handled  
from a single function, while no modifiers is a separate one.  

# Compiling the Demo
```
g++ -o demo demo.cpp -pthread
```
Header only library with no dependencies, just include `gtci.h`.  

It's that simple.

