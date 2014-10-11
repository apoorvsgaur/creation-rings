#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 18:31:52 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68340 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/line_num.bash $
#$Id: line_num.bash 68340 2014-09-01 22:31:52Z ee364a11 $

i=1

if (($# != 1))
 then 
  echo "Error."
  exit 0

fi

for k in $@
 do
  if ([[ ! -r $k ]])
  then
   echo "Cannot read $k"

  else  
    while read line
     do
      echo "$i: $line" 
      ((i=i+1))
     done < $1
   fi  
  done 

exit 0

# while (( $# != 0))
# do 
#  if [[ -r $1 ]]
#  then 
#    printf "File %s is readable!\n" $1
#  else
#    touch $1
#  fi
#  shift
# done