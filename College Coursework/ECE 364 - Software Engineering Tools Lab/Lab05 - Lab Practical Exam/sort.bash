#! /bin/bash

while getopts f:-: thisopt
do
        case $thisopt in
          f)filename=$OPTARG;;
          -)column_number=$OPTARG;;
          *) echo "Unknown option" 
        esac
done

if [[ ! -e $filename ]]
then 
   echo "Error: File does not exist." 
   exit 1
fi

if (( $# != 3 ))
then 
   echo "Insufficient information."
   exit 1
fi 

exit 0
  

