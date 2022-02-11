#!/bin/bash
make clean
(
    find . -type f -name cmake_install.cmake
    find . -type f -name CMakeCache.txt
    find . -type f -name Makefile
    find . -type d -name "CMakeFiles"
    echo build
) | xargs rm -fR 

#cmake -Bbuild -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=NO -DETCDIR=/etc -DNATT=YES
#cmake .
#make

