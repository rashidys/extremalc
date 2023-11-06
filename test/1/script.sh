#!/bin/bash

INT=3
while [ true ]
do
    tail -n 15 $1
    sleep $INT

    echo; echo
done
