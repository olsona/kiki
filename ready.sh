#!/bin/sh
cd bin
rm -r *
cmake ..
make -j 8
cd ..