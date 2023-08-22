#!/bin/bash
wget -P $PWD https://github.com/elhassanta/alx-low_level_programming/tree/master/0x18-dynamic_libraries/test1.so
export LD_PRELOAD=$PWD/test1.so
