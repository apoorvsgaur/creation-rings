#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 21:34:45 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68389 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/check_file.bash $
#$Id: check_file.bash 68389 2014-09-02 01:34:45Z ee364a11 $

for k in $@
do
  if [[ -e $k ]]
  then
    echo "$k exists."
  else  
    echo "$k does not exist."
  fi

  if [[ -d $k ]]
  then
    echo "$k is a directory."
  else  
    echo "$k is not a directory."
  fi

  if [[ -f $k ]]
  then
    echo "$k is an ordinary file."
  else  
    echo "$k is not an ordinary file."
  fi

  if [[ -r $k ]]
  then
    echo "$k is readable."
  else  
    echo "$k is not readable."
  fi

  if [[ -w $k ]]
  then
    echo "$k is writable."
  else  
    echo "$k is not writable."
  fi

  if [[ -x $k ]]
  then
    echo "$k is executable."
  else  
    echo "$k is not executable."
  fi
done  

exit 0