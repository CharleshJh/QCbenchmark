'''
usage: python3 <filename> <path_to_directory> <replace_how_many>
replace_how_many: [all/<number>]
change QASM file only
'''
import sys
import os
from os import listdir
from os.path import isfile, isdir, join
import re
import io


tmpList = list()
ancQbInt = int()

# function of decompose
def recursive_decompose(inputQbList, decompTimes, lastQbit = 0):

    lengOfInput = len(inputQbList)
    # dont need decompose
    if lengOfInput == 3 or decompTimes == 0:
        tmpList.append(inputQbList)
        return

    # look for ancilla gate
    ancilla_finded = False
    # check last qbit ancilla
    for i in range(lengOfInput):
        if lastQbit == int(inputQbList[i]):
            break
        if lastQbit != int(inputQbList[i]) and i == lengOfInput - 1:
            ancilla_finded = True
            ancQbInt = lastQbit
    # check other qbit ancilla
    for i in range(lengOfInput):
        if ancilla_finded == True:
            break
        for j in range(lengOfInput):
            if i == int(inputQbList[j]):
                break
            if i != int(inputQbList[j]) and j == lengOfInput - 1:
                ancilla_finded = True
                ancQbInt = i
    if ancilla_finded == False:
        sys.exit('ancilla finding error 1')
    if ancQbInt > lastQbit:
        sys.exit('ancilla finding error 2')

    # decompose part
    halfList1 = inputQbList[:lengOfInput//2]
    halfList2 = inputQbList[lengOfInput//2:]
    halfList1.append(ancQbInt)
    halfList2.append(halfList2[len(halfList2) - 1])
    halfList2[len(halfList2) - 2] = ancQbInt

    recursive_decompose(halfList1, decompTimes - 1, lastQbit)
    recursive_decompose(halfList2, decompTimes - 1, lastQbit)
    recursive_decompose(halfList1, decompTimes - 1, lastQbit)
    recursive_decompose(halfList2, decompTimes - 1, lastQbit)

# wrong input
if len(sys.argv) != 3:
    print('usage: python3 <filename> <path_to_directory> <replace_how_many>\n')
    print('replace_how_many: [all/<number>]')
    sys.exit('need more argv')

# create directory
mypath = sys.argv[1]
os.chdir(mypath)
if not os.path.exists('MCX_de'):
    os.mkdir('MCX_de')
os.chdir('..')

# decompose argv
decomArgvIsInt = False
if sys.argv[2] != 'all':
    decomArgvIsInt = True
    decomArgv = int(sys.argv[2])

# all file in directory
inDir = listdir(mypath)
for fname in inDir:
    target = join(mypath, fname)

    # check whether this benchmark was already added ancilla
    ancilla_already_added = True
    if '_addedAncilla' not in target:
        ancilla_already_added = False

    if isfile(target):

        # read file
        f = io.open(target, 'r', encoding = 'unicode_escape')
        fileLines = f.readlines()
        numQbit = 0

        # change write destination
        splitPath = f.name.split('/')
        tmpNum = len(splitPath)
        splitPath.append(splitPath[tmpNum - 1])
        splitPath[tmpNum - 1] = 'MCX_de'
        path = '/'.join(splitPath)
        
        if '_addedAncilla' not in path:
            path = path.replace('.qasm', '_addedAncilla.qasm')

        with open(path, 'w') as writingFile:
            for fl in range(len(fileLines)):

                # every block in a line, split by ' ' and ','
                aLine = re.split(',| ', fileLines[fl])
                numInLine = re.findall('[0-9]+', fileLines[fl])

                if aLine[0] == 'qreg':
                    if ancilla_already_added == True:
                        # total number of qbits
                        writingFile.write('qreg q[' + str(int(numInLine[0])) + '];\n')
                        numQbit = int(numInLine[0])
                    if ancilla_already_added == False:
                        # add ancilla
                        writingFile.write('qreg q[' + str(int(numInLine[0]) + 1) + '];\n')
                        numQbit = int(numInLine[0]) + 1

                if aLine[0] == 'creg':
                    if ancilla_already_added == True:
                        # total number of qbits
                        writingFile.write('creg c[' + str(int(numInLine[0])) + '];\n')
                    if ancilla_already_added == False:
                        # add ancilla
                        writingFile.write('creg c[' + str(int(numInLine[0]) + 1) + '];\n')

                elif aLine[0] == 'mcx':
                    if decomArgvIsInt == False:
                        decomArgv = numQbit
                    recursive_decompose(numInLine, decomArgv, numQbit - 1)
                    for i in range(len(tmpList)):
                        writingFile.write('mcx q[')
                        for j in range(len(tmpList[i])):
                            writingFile.write(str(tmpList[i][j]))
                            if j != len(tmpList[i]) - 1:
                                writingFile.write('],q[')
                            else:
                                writingFile.write('];\n')
                    tmpList.clear()

                else:
                    writingFile.write(fileLines[fl])
            writingFile.close()
