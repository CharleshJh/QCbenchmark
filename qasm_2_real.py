import sys
import os
from os import listdir
from os.path import isfile, isdir, join
import re

mypath = sys.argv[1]
os.chdir(mypath)
if not os.path.exists('out'):
    os.mkdir('out')
os.chdir('..')

inDir = listdir(mypath)

for fname in inDir:
  target = join(mypath, fname)

  if isfile(target):
    f = open(target, 'r', encoding = 'unicode_escape')
    fileLines = f.readlines()
    splitPath = f.name.split('/')
    tmpNum = len(splitPath)
    splitPath.append(splitPath[tmpNum - 1])
    splitPath[tmpNum - 1] = 'out'
    path = '/'.join(splitPath)
    path = path.replace('.qasm', '.real')

    with open(path, 'w') as writingFile:
      for fl in range(len(fileLines)):
        aLine = fileLines[fl].split()

        if aLine[0] == 'qreg':
          writingFile.write('.version 1.0\n')

          numInLine = re.findall('[0-9]+', aLine[1])
          writingFile.write('.numvars ' + numInLine[0] + '\n')

          writingFile.write('.variables')
          for i in range(int(numInLine[0])):
            writingFile.write(' q' + str(i))
          writingFile.write('\n')

          writingFile.write('.constants ')
          for i in range(int(numInLine[0])):
            writingFile.write('0')
          writingFile.write('\n')

          writingFile.write('.garbage ')
          for i in range(int(numInLine[0])):
            writingFile.write('-')
          writingFile.write('\n')

          writingFile.write('.begin\n')

        elif (aLine[0][0] == '/' and aLine[0][1] == '/') or aLine[0] == 'OPENQASM' or aLine[0] == 'include' or aLine[0] == 'creg' or aLine[0] == 'barrier':
          continue;

        elif aLine[0] == 'x' or aLine[0] == 'y' or aLine[0] == 'z' or aLine[0] == 'h':
          numInLine = re.findall('[0-9]+', aLine[1])
          writingFile.write(aLine[0] + '1 q' + numInLine[0] + '\n')

        elif aLine[0] == 'cx':
          numInLine = re.findall('[0-9]+', aLine[1])
          writingFile.write('t2 q' + numInLine[0] + ' q' + numInLine[1] + '\n')

        elif aLine[0] == 'measure':
          writingFile.write('.end')
          writingFile.close()
          break;

        else:
          sys.exit(aLine[0] + ' not supported')
