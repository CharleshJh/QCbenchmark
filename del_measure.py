'''
usage: python3 <filename> <path_to_directory>
change QASM file only
'''
import sys
import os
from os import listdir
from os.path import isfile, isdir, join
import re
import io


# create directory
mypath = sys.argv[1]
os.chdir(mypath)
if not os.path.exists('no_m'):
    os.mkdir('no_m')
os.chdir('..')

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

        # change write destination
        splitPath = f.name.split('/')
        tmpNum = len(splitPath)
        splitPath.append(splitPath[tmpNum - 1])
        splitPath[tmpNum - 1] = 'no_m'
        path = '/'.join(splitPath)

        if '_addedAncilla' not in path:
            path = path.replace('.qasm', '_no_m.qasm')

        with open(path, 'w') as writingFile:
            for fl in range(len(fileLines)):

                # every block in a line, split by ' ' and ','
                aLine = re.split(',| ', fileLines[fl])

                if not aLine[0] == 'measure':
                    writingFile.write(fileLines[fl])
            writingFile.close()
