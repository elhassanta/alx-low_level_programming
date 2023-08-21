#!/bin/bash
wget -P /tmp https://github.com/elhassanta/alx-low_level_programming/tree/master/0x18-dynamic_libraries/test1.so
export LD_PRELOAD=/tmp/test1.so
