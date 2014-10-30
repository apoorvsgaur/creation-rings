#! /bin/bash

###########################################################
#
# This is a sample script to use in Lab01, 
# Part 2, in case your script in Part 1
# is incomplete / does not work.
#
###########################################################

fout="roster.grades"

#Print output
printf "Class average: 78\n"
printf "ee364a01 Troy Barnes troy@purdue.edu 85 B 
ee364b02 Abed Nadir abed@purdue.edu 73 C
ee364c10 Pierce Hawthorne pierce@purdue.edu 96 A
ee364j13 Benjamin Chang chang@purdue.edu 67 D
ee364d07 Britta Perry britta@purdue.edu 49 F
ee364b04 Annie Edison annie@purdue.edu 100 A
ee364a09 Shirley Bennett shirley@purdue.edu 81 B\n" > $fout

exit 0
