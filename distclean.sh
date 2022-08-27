#!/bin/bash
make clean
(
    find . -type f -name cmake_install.cmake
    find . -type f -name CMakeCache.txt
    find . -type f -name Makefile
    find . -type d -name "CMakeFiles"
    echo build
    echo ike.zip
) | xargs rm -fR 

