# My C++ Library

This repository contains several header files I wrote to simplify complex functions like sleeping the current thread and clearing the screen, as they are essential for an immersive command-line RPG experience. In addition, I abstracted many of the most commonly used (at least by me) functions from the miniaudio header in my own myaudio.h. Below is a detailed description of each file.

## console.h

## consoleaudio.h

## myaudio.h
Also included are the miniaudio header file from the [miniaudio C++ audio library](https://github.com/mackron/miniaudio) as well as my own abstraction of the more important functions provided in the miniaudio header.

## Menu.h
Finally, there is the Menu header file, which contains the Menu class definition as well as an inline declaration of the Menu class. I intend to turn the Menu class into a tree-based node and provide an overarching MenuTree file for the sake of practice with data structures in C++.

