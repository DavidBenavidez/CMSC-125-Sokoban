#!/bin/bash
make clean
make uninstall
make
make install
cd ..
cd ..
make clean
make vmdex
make floppy
make boot-floppy