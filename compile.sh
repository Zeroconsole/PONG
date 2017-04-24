#!/bin/bash
git clone https://github.com/Hanavan99/PiGraphics
mv PiGraphics/*.c .
mv PiGraphics/*.h .
rm test.c
make
LD_LIBRARY_PATH=.
export LD_LIBRARY_PATH
./game
