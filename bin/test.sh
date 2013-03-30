#!/bin/bash
./genererNombre 100 > nombre.txt
./genererNombre 100 >> nombre.txt
./calculatrice nombre.txt
gprof ./calculatrice gmon.out | grep --color Entier::operator
