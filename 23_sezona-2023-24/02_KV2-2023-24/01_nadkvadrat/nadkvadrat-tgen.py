# numExampleCases = 3
# numPositiveOnlyCases = 6
# numRelativelySmallCases = 6
# collinearTestCases = 6
# numRestTestCases = 2

exampleCasesInput = [[(1, 2), (3, 3), (2, 1)],                                      # 1
                     [(1, 1), (-2, -1), (3,-2)],                                    # 2
                     [(1, 2), (3, 4), (5, 6)]]                                      # 3

positiveOnlyInputs = [[(1, 2), (2, 1), (2, 2)],                                     # 1/1/4
                      [(3, 3), (3, 7), (7, 3)],                                     # 2/2/5
                      [(1234, 6543), (3456, 5432), (2345, 4321)],                   # 3/3/6
                      [(9876, 5432), (1234, 5678), (9876, 7890)],                   # 4/4/7
                      [(10000, 0), (0, 0), (0, 10000)],                             # 5/5/8
                      [(0, 10000), (10000, 10000), (10000, 0)]]                     # 6/6/9

relativelySmallInputs = [[(-1, -2), (-2, -1), (-2, -2)],                            # 1/7/10
                         [(-3, -3), (-3, -7), (-7, -3)],                            # 2/8/11
                         [(-1234, 6543), (3456, -5432), (2345, 4321)],              # 3/9/12
                         [(9876, -5432), (-1234, 5678), (-9876, -7890)],            # 4/10/13
                         [(10000, -10000), (10000, 10000), (-10000, 10000)],        # 5/11/14
                         [(-10000, 10000), (-10000, -10000), (10000, -10000)]]      # 6/12/15

collinearInputs = [[(1, 1), (0, 0), (-1,-1)],                                       # 1/13/16
                   [(-1, 0), (0, 0), (1, 0)],                                       # 2/14/17
                   [(0, -1), (0, 0), (0, 1)],                                       # 3/15/18
                   [(100, 101), (100, 200), (100,100)],                             # 4/16/19
                   [(303, -100), (-303, -100), (303,-100)],                         # 5/17/20
                   [(0, 0), (0, 0), (0, 0)]]                                        # 6/18/21

restTestCaseInputs = [[(-1000000000, -999999999), (999999999, 1000000000), (0, 0)], # 1/19/22
                      [(0, 0), (-999999999, 1000000000), (999999999, -1000000000)]] # 2/20/23

allTestCases = exampleCasesInput + \
               positiveOnlyInputs + \
               relativelySmallInputs + \
               collinearInputs + \
               restTestCaseInputs

from nadkvadrat import nadkvadrat

for testcase in range(len(allTestCases)):
    (x1, y1), (x2, y2), (x3, y3) = allTestCases[testcase]
    with open('testcases/' + str(testcase + 1).zfill(2) + '.in', 'w') as file:
        file.write('\n'.join([str(x1)+' '+str(y1), str(x2)+' '+str(y2), str(x3)+' '+str(y3)]))
    with open('testcases/' + str(testcase + 1).zfill(2) + '.out', 'w') as file:
        file.write(str(nadkvadrat((x1, y1), (x2, y2), (x3, y3))))
