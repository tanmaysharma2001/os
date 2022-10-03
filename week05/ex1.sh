#!/bin/bash
gnome-terminal -e "bash -c 'gcc publisher.c -o publisher ; ./publisher; bash;'"

x=1
while [ $x -le $1 ]
do
    gnome-terminal -e "bash -c 'gcc subscriber.c -o subscriber ; ./subscriber; bash;'"
    x=$(( $x + 1 ))
done

clear