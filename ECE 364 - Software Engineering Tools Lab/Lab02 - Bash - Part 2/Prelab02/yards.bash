#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-08 23:30:37 -0400 (Mon, 08 Sep 2014) $
#$Revision: 68756 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab02/yards.bash $
#$Id: yards.bash 68756 2014-09-09 03:30:37Z ee364a11 $

i=-1
sum_line=0
variance=0
sum_var=0
max=0

if (($# != 1))
 then 
 echo "Usage: yards.bash <filename>"
 exit 1
fi

for k in $@
do
 
 if [[ ! -r $k ]]
  then
   echo "Error: $k is not a readable file." 
   exit 2
  fi

 while read line
 do
 String=($line)
    for item in ${String[*]}
    do
      ((sum_line+=item))
      ((i+=1))
    done
    ((average=sum_line/i))
    if ((average>=max))
    then 
      ((max=average))
    fi

    for item in ${String[*]}
    do
      if (((item-average) > -2000))
       then
      ((variance+=(item-average)*(item-average)))
       fi
    done
    ((variance/=i))

    echo "$String schools averaged $average yard receiving with a variance of $variance"
    sum_line=0
    i=-1
    variance=0
  done < $1
  echo "The largest average yardage was $max"
done