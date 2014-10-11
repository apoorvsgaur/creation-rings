#! /bin/bash

while getopts a:b:-: thisopt
do
        case $thisopt in
          a)echo $OPTARG;;
          b)echo $OPTARG;;
          -)echo  "${OPTARG}" ;;
          *)echo "Invalid arg";;
        esac
done

exit 0