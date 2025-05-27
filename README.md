# GBA-Furry-Harvest
The goal for this project is to make a C program that will run on a Game Boy Advance (GBA) emulator. This program demonstrates an understanding of low-level hardware programming in C. This program is similar to how one would write device drivers or parts of an operating system, which are often written in C. The GBA devices are accessed using memory-mapped I/O. Since GBA is a slow computer optimization trick (such as DMA) was used to prevent common issues (such as tearing). 
## Requirements 
-GBA emulator 
## Usage 
Once the program is successfully run, you will start on the initial start screen with an animation. When you click Start/Enter the game begins with a 45-second countdown. Using the Up/Down and Right/Left arrow keys you must navigate the bunny around the map to collect as many carrots as possible (There are at most 8 carrots on the screen at all times). Once your time is up it will take you to the final screen, where you will get a summary of your results. At any moment during the game clicking the Select/Backspace button will take you back to the home screen, this will reset stats and the entire program.
