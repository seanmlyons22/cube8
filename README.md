LED Cube
========

This readme explains how to setup the development environment for the LED cube. 
Furthermore, it explains how to build and deploy binaries for the LED cube.

Inspiration
-----------

This project is based on and inspired by `chr`'s
[LED Cube 8x8x8](https://www.instructables.com/Led-Cube-8x8x8/). I started this
project when I was a university student learning electronics. The intent was to
copy `chr`'s work verbatim as I did not yet fully understand all the concepts.

As a busy student, it took around 4 years to complete the build. This is 
because I really only worked on it during school holidays. I learned a lot from  this project. It flexed by my theoretical and practical knowledge of embedded programming and electronics. 

Now, I hope to give back to the project by coming up with some interesting 
modifications and sharing them with the community.


Environment
-----------

The development environment is listed below. While the instructions are written
for macOS, they should also easily be adaptable to Linux or (maybe) Windows.


 - OS: macOS 11.1 20C69 x86_64
 - Host: MacBookPro11,4
 - Kernel: 20.2.0
 - Shell: zsh 5.7.1
 - Terminal: iTerm2


Hardware Modifications
----------------------

Note that I have swapped out the `atmega32` for a `atmega324pa` since I already 
have one from a previous project.


Prerequisites
-------------

Since I am developing on a mac, I will use homebrew to install the dependencies
needed to compile the AVR firmware and load binaries. 

Two things are needed:

 - [avr-gcc](https://github.com/osx-cross/homebrew-avr)
 - [avrdude](https://formulae.brew.sh/formula/avrdude)


The AVR GCC compiler is used to compile the firmware and avrdude is used
as a flash programmer.

You should also have a working LED cube.


Compiling
---------

The cube firmware is built using make, there is a makefile in the root
directory. Some build goals are listed at the top of the file. Most common is:

        make all


To clean the generated object files:


        make clean


Flashing
--------

avrdude is responsible for flashing the device.
The ISP is the [usbtiny](https://www.sparkfun.com/products/9825) by sparkfun.

To program the board using the USB tiny, run the following command:

        avrdude -c usbtiny -p m324pa -B 1 -U flash:w:Main.hex


You can also run the make goal

        make program


Test Program
------------

There is a small program to test the LED cube in the `test` folder.
It can be built with make and is useful for debugging dead LEDs or broken 
connections within the cube.


