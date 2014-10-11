#! /bin/bash
#$Author$
#$Date$
#$Revision$
#$HeadUR$
#$Id$

t=0
f=0
if (($# != 3))
then 
  echo "usage: filter_expr.bash <input file> <min> <max>"
  exit 1
fi

if [[ ! -r $1 ]]
then 
  echo "error: $1 is not a readable file."
  exit 2
fi

if (( $2 > $3 ))
then 
  echo "error: min was greater than max."
  exit 2
fi

while read line
  do
    print_Array=()
    String=($line)
    for item in ${String[*]}
    do
     if (($item >=$2 && $item <=$3))
      then
      print_Array[t]=$item
      t+=1
     fi
     
    done
     if ((t > 0))
     then
      echo "$String ${print_Array[*]}" 
     fi
     t=0
  done < $1


exit 0