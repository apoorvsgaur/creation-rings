#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 17:06:46 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68286 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/sum.bash $
#$Id: sum.bash 68286 2014-09-01 21:06:46Z ee364a11 $

X=0
while (( $# != 0))
do 
  ((X=X+$1))
  shift
done

echo $X