__author__ = 'ee364a11'

#def getLargestProduct():
#   with open('Number Grid.txt', 'r') as myFile:
#      lines = myFile.readlines()
#      for l in lines:
#        print (l)

def getListProduct(numList):
    product = 1
    for i in numList:
       product = product*i

    return product

def partition(numList, n):
    length = len(numList);
    i = 0
    j = 0
    loop=0
    p = []
    while (i <= (length - n)):
        empty_list = []
        j = i
        while (loop < n):
            empty_list.append(numList[j])
            j+=1
            loop+=1
        i+=1
        loop=0

        p.append(empty_list)
    return p

def getLargestPartition(numList, n):
   product = 0
   highest_prod = []
   sep_lists = partition(numList, n)
   for i in sep_lists:
       prod = getListProduct(i)
       if (prod == product):
          highest_prod.append([i, prod])
       else:
           if (prod > product):
             product = prod
             highest_prod = []
             highest_prod.append([i, prod])
   return (highest_prod)

def getDirectory():
    Directory = {}
    Directory_area = {}
    with open('Phone Directory.txt', 'r') as myFile:
      lines = myFile.readlines()
      for l in lines:
        lines = l.split()
        tuple = (lines[0], lines[1], lines[2])
        Directory[tuple] = (lines[3] + lines[4])
    return Directory

def getPhoneByPartialName(partialName):
    Directory = getDirectory()
    final_list = []
    for keys, values in Directory.items():
        if (keys[0] == partialName or keys[2] == partialName):
            final_list.append(values)
    return (final_list)

def reverseLookup(areaCode):
    Directory = getDirectory()
    final_list = []
    for keys, values in Directory.items():
        print (int(values[1:4]))
        if (int(values[1:4]) == areaCode):
            final_list.append(keys)
    return (final_list)


if __name__ == "__main__":
    # getLargestPartition ([1,2,3,4,5,6], 3)
    #getDirectory()
    #getPhoneByPartialName('Russell')
    reverseLookup(602)