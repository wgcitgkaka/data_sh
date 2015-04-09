#!/bin/bash
#author: wgc
#using deal with the data

x=0
cat $1 | egrep 'PREFIX|NEXT_HOP' > 3.txt
while read line
do
x=$(expr $x + 1)
test1=$(echo $line | grep 'PREFIX')
if [ "$test1" != "" ];then
b=$(echo $line | grep 'PREFIX:' | awk '{print $2}')
d=`ipcalc $b | grep "Network:" | awk '{print $3}' | sed -n 's/\.//gp'`
fi

test2=$(echo $line | grep 'NEXT_HOP')
if [ "$test2" != "" ];then
c=$(echo $line | grep 'NEXT_HOP:' | awk '{print $2}') 
fi

if [ "$b" != "" ] && [ "$c" != "" ] && [ $(expr $x % 2) -eq 0 ]; then
echo "$d $c" >> r00.data
x=0
fi
done < ./3.txt
exit 0
