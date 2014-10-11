__author__ = 'ee364a11'

import glob
import random

def getWordFrequency():
    check_files = glob.glob('./files/*.txt')
    A = {}
    for k in check_files:
        FileObject = open(k, "r")
        lines = FileObject.readlines()
        for l in lines:
           l=l.replace(".","")
           l=l.replace(",","")
           cols=l.split()

           for w in cols:
             if (w not in A):
               A[w] = 1
             else:
               Value = A.pop(w)
               A[w] = Value + 1
        FileObject.close()
    return A

def getDuplicates():
    check_files = glob.glob('./files/*.txt')
    A = {}
    B = {'Item': 0}

    for k in check_files:
        FileObject = open(k, "r")
        k = k[8:11]
        lines = FileObject.readlines()
        #print lines[0]
        #print k
        if (lines[0] in A):
           value = A[lines[0]]
           value.append(k)
           value.sort()
           A[lines[0]] = value
        else:
           A[lines[0]] = [k]
        FileObject.close()

        for value in A.values():
           B[value[0]]=(value)

    return B

def getPurchaseReport():
    check_files = glob.glob('./purchases/purchase_???.txt')
    FileObject = open('./purchases/Item List.txt', "r")
    Price_List = {}
    Final_List = {}
    lines = FileObject.readlines()
    sum = 0
    for l in lines:
       words = l.split()
       if (words[0].isalnum()):
         Price_List[words[0]] = words[1]

    for k in check_files:
        with open(k, 'r') as open_file:
           lines = open_file.readlines()
           for l in lines:
              words = l.split()
              if (words[0].isalnum() and words[0] != 'Item'):
                  Item = Price_List[words[0]]
                  Quantity = words[1]
                  sum += int(Quantity) * float(Item[1:])
           Final_List[k[21:24]] = round(sum)
           sum=0
    return Final_List

def getTotalSold():
    check_files = glob.glob('./purchases/purchase_???.txt')
    Value_List = {}
    for k in check_files:
      with open(k, 'r') as open_file:
        lines = open_file.readlines()
        for l in lines:
           words = l.split()
           if (words[0].isalnum() and words[0] != 'Item'):
              if (words[0] in Value_List):
                 Value = Value_List.pop(words[0])
                 Value = int(Value) + int(words[1])
                 Value_List[words[0]] = Value
              else:
                 Value_List[words[0]] = words[1]

    return Value_List


if (__name__ == "__main__"):
   getWordFrequency()
   getDuplicates()
   getPurchaseReport()
   getTotalSold()

   random.seed