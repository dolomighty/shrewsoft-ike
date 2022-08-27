#!/bin/bash
$OUTERM && OUTERM=false exec xterm -e $0
cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=YES  -DETCDIR=/etc -DNATT=YES .
make

date +"%F %T fatto"
read
