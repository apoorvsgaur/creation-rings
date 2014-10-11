#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 17:34:10 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68293 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/exist.bash $
#$Id: exist.bash 68293 2014-09-01 21:34:10Z ee364a11 $

while (( $# != 0))
do 
 if [[ -r $1 ]]
 then 
   printf "File %s is readable!\n" $1
 else
   touch $1
 fi
 shift
done

exit 0