#!/bin/bash
wget -P /tmp/ https://github.com/elhassanta/alx-low_level_programming/blob/master/0x18-dynamic_libraries/test1.so
export LD_PRELOAD=/$PWD/test1.so ./gm 9 8 10 24 75 9
