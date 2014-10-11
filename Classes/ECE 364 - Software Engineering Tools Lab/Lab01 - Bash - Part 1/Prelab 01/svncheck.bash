#! /bin/bash
#$Author: ee364a11 $
#$Date: 2014-09-01 23:24:32 -0400 (Mon, 01 Sep 2014) $
#$Revision: 68432 $
#$HeadURL: svn+ssh://ece364sv@ecegrid-thin1/home/ecegrid/a/ece364sv/svn/F14/students/ee364a11/Prelab01/svncheck.bash $
#$Id: svncheck.bash 68432 2014-09-02 03:24:32Z ee364a11 $

for k in $@
do
  check_svn=$(svn status $k)
  if [[ "$(${check_svn}|cut -c1)" = "?" ]]
  then 
    echo "Yes."
  else
    echo "No."
  fi
done

echo ${check_svn}|cut -c1
exit 0

