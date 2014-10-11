#! /bin/bash
#$Author$
#$Date$
#$Revision$
#$HeadUR$
#$Id$

sum=0
i=0 
if (($# != 1))
 then 
   echo "Usage: assign_grades.bash <roster file>"
   exit 1
fi

for k in $@
do
  if [[ ! -r $k ]]
  then
   echo "Error: $k is not a readable file." 
   exit 2
  fi

  if [[ -e $k.grades ]]
  then
   echo "Output file $k.grades already exists."
   exit 2
  fi
  
  if [[ ! -w . ]]
  then
   echo "Error: current directory is not writable."
   exit 2
  fi

  while read id a b c d e
  do
    if (( $d >= 90 ))
    then 
      echo 'A' >> $k.temp
      i=i+1
      sum+=$d  
    
    elif (( $d >= 80 ))
    then 
      echo 'B' >> $k.temp
      i=i+1
      sum+=$d   

    elif (( $d >= 70 ))
    then 
      echo 'C' >> $k.temp
      i=i+1
      sum+=$d   

    elif (( $d >= 60 ))
    then 
      echo 'D' >> $k.temp  
      i=i+1
      sum+=$d 

    elif (( $d < 60 ))
    then 
      echo 'F' >> $k.temp
      i=i+1
      sum+=$d   
    fi
   
  done < $1
done

((average=sum/i))
STATUS=$(paste roster roster.temp >> roster.grades)
echo "Class average: ${average}"
exit 0

