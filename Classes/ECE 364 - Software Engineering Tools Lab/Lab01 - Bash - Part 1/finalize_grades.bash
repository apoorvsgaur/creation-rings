#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-02 11:21:14 -0400 (Tue, 02 Sep 2014) $
#$Revision: 68470 $
#$HeadUR$
#$Id: finalize_grades.bash 68470 2014-09-02 15:21:14Z ee364a11 $

if (($# != 1))
 then 
   echo "Usage: finalize_grades.bash <roster file>"
   exit 1
 fi

for k in $@
do
  if [[ ! -r $k ]]
  then
   echo "Error: $k is not a readable file." 
   exit 2
  fi
  
  check=$(assign_grades.bash roster)
  if (( check != 0 ))
  then
    echo "Error: assign_grades.bash failed."
    exit 3
  fi

  if [[ -e $k.grades ]]
  then
   echo "Error: Output file $k.grades already exists."
   exit 2
  fi

  else 
done
