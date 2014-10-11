__author__ = 'Alex Gheith'
__date__ = '2014-September-15'

import copy
import math
import inspect
from dataFile import *
import myOperations
from myOperations import *
resultList = []
sep = '-----------------------------------------------------------------------------------------------------------'

def functionExists(fn):
    """
    Verify that the function 'fn' exists in the module myOperations.
    """
    expression = "inspect.isfunction(myOperations.{})".format(fn)
    if fn not in dir(myOperations) or not eval(expression):
        msg = "Function '{}' has not been found.".format(fn)
        resultList.append(msg)
        return False
    return True


def evaluateFunctionWithOneInput(fn, testValues, expectedValues):
    """
    Evaluates the given functions for all the inputs to determine a match. If an error is produced, it will be captured.
    The results are aggregated to be reported. Note that all input lists must have equal length.
    """
    resultList.append(sep)

    if not functionExists(fn):
        return

    for tVal, eVal in zip(testValues, expectedValues):
        try:
            # Guard against string input parameters.
            if type(tVal) is str:
                tVal = '"{}"'.format(tVal)

            expression = "{}({})".format(fn, tVal)
            rVal = eval(expression)

            if eVal == rVal:
                msg = "Correct! Function '{}' with input: {} => {}.".format(fn, tVal, eVal)
            else:
                msg = "WRONG! Function '{}' with input: {} => {}. I really wanted {}.".format(fn, tVal, rVal, eVal)

            resultList.append(msg)

        except:
            msg = "ERROR! Function '{}' with input: {} => ERROR.".format(fn, tVal)
            resultList.append(msg)

def evaluateFunctionWithTwoInputs(fn, testValues1, testValues2, expectedValues):
    """
    Evaluates the given functions for all the inputs to determine a match. If an error is produced, it will be captured.
    The results are aggregated to be reported. Note that all input lists must have equal length.
    """
    resultList.append(sep)

    if not functionExists(fn):
        return

    for tVal1, tVal2, eVal in zip(testValues1, testValues2, expectedValues):
        try:
            # Guard against string input parameters.
            if type(tVal1) is str:
                tVal1 = '"{}"'.format(tVal1)

            if type(tVal2) is str:
                tVal2 = '"{}"'.format(tVal2)

            expression = "{}({}, {})".format(fn, tVal1, tVal2)
            rVal = eval(expression)

            if eVal == rVal:
                msg = "Correct! Function '{}' with inputs: {} and {} => {}.".format(fn, tVal1, tVal2, rVal)
            else:
                msg = "WRONG! Function '{}' with inputs: {} and {} => {}. I really wanted {}.".format(fn, tVal1, tVal2, rVal, eVal)

            resultList.append(msg)

        except:
            msg = "ERROR! Function '{}' with inputs: {} and {} => ERROR.".format(fn, tVal1, tVal2)
            resultList.append(msg)

def test_findMultiplesUnder():

    fn = 'findMultiplesUnder'
    testValues = [100, -1]
    expectedValues = [2318, None]

    evaluateFunctionWithOneInput(fn, testValues, expectedValues)

def test_scaleVector():
    fn = 'scaleVector'
    testValues1 = [2, math.e, 'Hello', 3, 1]
    x = [8, 4, 2, -3, 6]
    testValues2 = [x, [4], x, 3, []]
    y1 = [16, 8, 4, -6, 12]
    y2 = [10.87312731383618]
    expectedValues = [y1, y2, None, None, None]

    evaluateFunctionWithTwoInputs(fn, testValues1, testValues2, expectedValues)

def test_getColumnAverage():
    fn = 'getColumnAverage'
    A = [[4, -5, -6, -2, 0], [-2, -7, 3, 1, -9], [-8, -4, -2, -3, 0]]
    testValues1 = [[], A, A, A]
    testValues2 = [0, 3.14, 10, 4]
    expectedValues = [None, None, None, -3]

    evaluateFunctionWithTwoInputs(fn, testValues1, testValues2, expectedValues)

def test_isSubsetOf():
    fn = 'isSubsetOf'
    l1 = [4, -5, -6, -2, 0, -4, 9]
    testValues1 = [l1, l1, 'H', l1]

    l2 = [-6, 4, 9]
    l3 = l1 + [11]
    testValues2 = [l2, 5, l2, l3]
    expectedValues = [True, None, None, None]

    evaluateFunctionWithTwoInputs(fn, testValues1, testValues2, expectedValues)

def test_dotProduct():
    fn = 'dotProduct'
    l1 = [4, -5, -6, -2, 0, -4, 9]
    l2 = [8, 3, 0, -9, 4]
    testValues1 = [l1, l2, l1 + l2, 2, l1]

    l3 = [4, 2, -3, -8, 6]
    testValues2 = [l1, l3, l3, l3, 'A']

    expectedValues = [178, 134, None, None, None]

    evaluateFunctionWithTwoInputs(fn, testValues1, testValues2, expectedValues)

def test_getLongestWord():
    fn = 'getLongestWord'
    someWords = 'It rocks when depreciation has ignored the case'
    testValues = [sentence, someWords, 34, [], ['Single']]
    expectedValues = ['Aardvark', 'depreciation', None, None, None]

    evaluateFunctionWithOneInput(fn, testValues, expectedValues)

def test_decodeNumbers():
    fn = 'decodeNumbers'
    testValues = [104, [72, 97, 104, 97], coded, [72, 97, 104, 97, 'H']]
    wording = 'Python is the best language, and everyone should really learn it!'
    expectedValues = [None, 'Haha', wording, None]

    evaluateFunctionWithOneInput(fn, testValues, expectedValues)

def test_getStudentAverage():

    del students[4]
    del students[3]
    fn = 'getStudentAverage'
    testValues = [0, 1, 3]
    expectedValues = [97.16, 88.72, None]

    evaluateFunctionWithOneInput(fn, testValues, expectedValues)

def test_getSubjectAverage():
    fn = 'getSubjectAverage'
    testValues = [1, 4, 10]
    expectedValues = [85.78, 91.88, None]

    evaluateFunctionWithOneInput(fn, testValues, expectedValues)


if __name__ == "__main__":
    test_findMultiplesUnder()
    test_scaleVector()
    test_getColumnAverage()
    test_isSubsetOf()
    test_dotProduct()
    test_getLongestWord()
    test_decodeNumbers()

    test_getSubjectAverage()

    # Must be the last; because it changes local data.
    test_getStudentAverage()

    print('\n'.join(resultList))
