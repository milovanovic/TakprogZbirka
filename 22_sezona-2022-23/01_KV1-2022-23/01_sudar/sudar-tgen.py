# numExampleCases  = 5
# numSingleDigitCases = 4
# numDoubleDigitCases = 6
# numTripleDigitCases = 6
# numEqNumDigitsCases = 8
# numRestTestCases = 16

exampleCasesInput = [(73, 28),                 # 1
                     (64, 357),                # 2
                     (234, 135),               # 3
                     (99099, 9999),            # 4
                     (2, 100)]                 # 5

singleDigitInputs = [(1, 8),                   # 1/1/6
                     (7, 3),                   # 2/2/7
                     (2, 2),                   # 3/3/8
                     (6, 9)]                   # 4/4/9

doubleDigitInputs = [(34, 67),                 # 1/5/10
                     (98, 21),                 # 2/6/11
                     (37, 46),                 # 3/7/12
                     (82, 72),                 # 4/8/13
                     (10, 10),                 # 5/9/14
                     (55, 55)]                 # 6/10/15

tripleDigitInputs = [(123, 456),               # 1/11/16
                     (406, 307),               # 2/12/17
                     (300, 500),               # 3/13/18
                     (313, 306),               # 4/14/19
                     (801, 381),               # 5/15/20
                     (666, 666)]               # 6/16/21

eqNumDigitsInputs = [(2341, 6785),             # 1/17/22
                     (456328, 284315),         # 2/18/23
                     (152535455, 505152534),   # 3/19/24
                     (152535455, 554535251),   # 4/20/25
                     (123456789, 123456789),   # 5/21/26
                     (987654321, 123456789),   # 6/22/27
                     (999999999, 999999999),   # 7/23/28
                     (1000000000, 1000000000)] # 8/24/29

restTestCaseInputs = [(3, 32),                 # 1/25/30
                      (33, 3),                 # 2/26/31
                      (444, 2424),             # 3/27/32
                      (2424, 242),             # 4/28/33
                      (1, 123456789),          # 5/29/34
                      (1000000000, 1),         # 6/30/35
                      (999, 111555999),        # 7/31/36
                      (999555111, 999),        # 8/32/37
                      (123, 123000321),        # 9/33/38
                      (123000321, 321),        # 10/34/39
                      (555, 333444555),        # 11/35/40
                      (223344556, 556),        # 12/36/41
                      (545454545, 54545),      # 13/37/42
                      (100000, 1000000000),    # 14/38/43
                      (1000000000, 111111111), # 15/39/44
                      (234567890, 1000000000)] # 16/40/45

allTestCases = exampleCasesInput + \
               singleDigitInputs + \
               doubleDigitInputs + \
               tripleDigitInputs + \
               eqNumDigitsInputs + \
               restTestCaseInputs

from sudar import sudar

for testcase in range(len(allTestCases)):
    x, y = map(str, allTestCases[testcase])
    with open('testcases/' + str(testcase + 1).zfill(2) + '.in', 'w') as file:
        file.write('\n'.join([x, y]))
    with open('testcases/' + str(testcase + 1).zfill(2) + '.out', 'w') as file:
        file.write(str(sudar(x, y)))
