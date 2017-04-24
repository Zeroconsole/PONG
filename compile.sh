#!/bin/bash
git clone https://github.com/Hanavan99/PiGraphics
mv PiGraphics/*.c .
mv PiGraphics/*.h .
rm test.c
make
make clean
