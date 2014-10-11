#! /bin/bash
#$Author$
#$Date$
#$Revision$
#$HeadURL$
#$Id$

if (($# != 1))
 then 
 echo "Usage: process_temp.bash <filename>"
 exit 1
fi

for k in $@
do
 if [[ ! -r $k ]]
 then
   echo "Error: $k is not a readable file." 
   exit 2
 else
  while read line
  do
    String=($line)
    for (( i=1; i<5 ; i++ ))
    do
     ((sum_string+=${String[i]}))
    done
    ((average=sum_string/4))
    if ((average != 0))
    then
    echo "Average temperature for time $String was $average C."
    fi
    sum_string=0
  done < $1
 fi
  
done



