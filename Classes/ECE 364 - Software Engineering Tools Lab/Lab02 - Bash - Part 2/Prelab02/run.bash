#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-09 02:21:11 -0400 (Tue, 09 Sep 2014) $
#$Revision: 68765 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab02/run.bash $
#$Id: run.bash 68765 2014-09-09 06:21:11Z ee364a11 $

cache=0
widths=0
max=100000
FILE=$(gcc $1 -o quick_sim)
if [[ ! -z $FILE ]]
then 
  echo $FILE
  echo "error: quick_sim could not be compiled!"
  return 1
 elif [[ -e $2 ]]
 then 
  read -p "$2 exists. Would you like to delete it?" answer
  if [[ $answer = "n" ]]
  then
   read -p "Enter a new filename: " file_name
   for (( cache=1; cache <=32; cache=cache*2 ))
   do
     for (( widths=1; widths <=16; widths=widths*2 ))
     do
       STATUS=$(quick_sim $cache $widths "a"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "a"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "a"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       fi
       STATUS_TIME=$(quick_sim $cache $widths "i"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "i"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "i"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       fi
       echo $STATUS >> $file_name
       echo $STATUS_TIME >> $file_name
     done
   done
  else
   rm $2 >/dev/null
    for (( cache=1; cache <=32; cache=cache*2 ))
     do
     for (( widths=1; widths <=16; widths=widths*2 ))
      do
       STATUS=$(quick_sim $cache $widths "a"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "a"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "a"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       fi
       STATUS_TIME=$(quick_sim $cache $widths "i"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "i"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "i"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       fi
       echo $STATUS >> $2
       echo $STATUS_TIME >> $2
      done
     done
  fi
  else
    for (( cache=1; cache <=32; cache=cache*2 ))
     do
     for (( widths=1; widths <=16; widths=widths*2 ))
      do
       STATUS=$(quick_sim $cache $widths "a"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "a"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "a"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "a"| cut -d":" -f10)
       fi
       STATUS_TIME=$(quick_sim $cache $widths "i"| cut -d":" -f2,4,6,8,10)
       Time=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       if ((Time<max))
       then 
        Processor=$(quick_sim $cache $widths "i"| cut -d":" -f2)
        cache_high=$cache
        issue_width=$widths
        time_length=$(quick_sim $cache $widths "i"| cut -d":" -f10)
        max=$(quick_sim $cache $widths "i"| cut -d":" -f10)
       fi
       echo $STATUS >> $2
       echo $STATUS_TIME >> $2
      done
     done 
fi

echo "Fastest run time achieved by $Processor with cache size $cache_high and issue width $issue_width was $time_length" 
exit 0