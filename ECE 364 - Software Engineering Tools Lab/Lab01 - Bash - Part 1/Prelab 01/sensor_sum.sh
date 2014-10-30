#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 23:58:46 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68441 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/sensor_sum.sh $
#$Id: sensor_sum.sh 68441 2014-09-02 03:58:46Z ee364a11 $

while read line
  do 
    echo $line | cut -c1-2
    sum1= $($line | cut -d' ' -f2)
    sum2= $($line | cut -d' ' -f3)
    sum3= $($line | cut -d' ' -f4)
    sum_t=sum1+sum2+sum3
    echo sum_t
  done < $1

exit 0