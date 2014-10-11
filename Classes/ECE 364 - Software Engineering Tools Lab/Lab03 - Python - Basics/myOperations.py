__author__ = 'ee364a11'

from dataFile import *

def findMultiplesUnder(maxValue):
    if (maxValue == 0):
        return None;
    i = 1;
    sum = 0;
    while (i < maxValue):
        if (i % 3 == 0 or i % 5 == 0):
            sum=sum+i;
        i+=1
    return sum;

def scaleVector(s,vList):
    a=1
    b=3.14
    c=[1,2,3,4]
    if (type(s) != type(a) and type(s) != type(b)):
        return None
    if (type(vList) != type(list)):
        return None
    if (len(vList) == 0):
        return None

    return

def getColumnAverage(matrix, colIndex):
    a=1
    if (len(matrix) == 0):
        return None

    if (type(colIndex) != type(a)):
        return None

    i=0
    sum=0
    for k in matrix:
        if (len(k) < colIndex):
            return None
        sum += k[colIndex];
        i += 1;
    return (sum/i)

def isSubsetOf(superList, subList):
    a = [1,2,3];
    if (type(superList) != type(a) or type(subList) != type(a)):
        return None

    if (len(superList) < len(subList)):
        return None

    i=0
    for k in subList:
        if ((k in superList) == True):
            i+=1;

    if (i == len(subList)):
        return True;

def dotProduct(x,y):
    a = [1,2,3];
    i = 0;
    sum = 0;
    if (type(x) != type(a) or type(y) != type(a)):
        return None

    if (len(x) != len(y)):
        return None

    while (i < len(x)):
        sum+=x[i]*y[i];
        i+=1;
    return sum;

def getLongestWord(sentence):
    length_c=0
    string_check = "String"
    word = ""
    if (type(string_check) != type(sentence)):
        return None
    Cols=sentence.split();

    for k in Cols:
        if (len(k) > length_c):
            length_c = len(k)
            word = k
    return word







