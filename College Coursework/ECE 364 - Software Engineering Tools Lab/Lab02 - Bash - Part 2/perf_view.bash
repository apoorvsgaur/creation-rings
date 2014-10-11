#! /bin/bash
#$Author$
#$Date$
#$Revision$
#$HeadUR$
#$Id$

choice=0
if (($# != 1))
then 
  echo "usage: ./perf_view.bash <filename>"
  exit 1
fi

if [[ ! -r $1 ]] 
then 
  echo "Error: $1 does not exist or is not readable"
  exit 2
fi 

echo "Your choices are:"
echo "1) 5 fastest CPUs"
echo "2) 10 most efficient CPUs"
echo "3) Sorted by name, then efficiency"
echo "4) 10 slowest CPUs"
echo "5) Pick a number of the fastest CPUs"
echo "6) Exit"

while (($choice != 6))
do
read -p "Your choice: " choice

if (($choice == 6))
  then  
  echo "Have a nice day!"
  exit 0

elif (( $choice == 1 ))
then  
  cat $1 | sort -n -t"," -k5 | head -n5 
  
elif (( $choice == 2 ))
then
  cat $1 | sort -t"," -k4 -n | head -n10
  
elif (( $choice == 3 ))
then 
  cat $1 | sort -t"," -k1,1 -k4,4 

elif (( $choice == 4 ))
then
  cat $1 | sort -t"," -k5 -n | tail -n10
elif (( $choice == 5 ))
then
  read -p "Enter a number: " number
  cat $1 | sort -t"," -k5 -n | head -n $number
else
  echo "Error! Invalid selection!"
fi
done

exit 0