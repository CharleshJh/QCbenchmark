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

for f in inDir:
  target = join(mypath, f)

  if isfile(target):
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
          writingFile.write('.numvars ' + str(numInLine) + '\n')

          writingFile.write('.variables')
          for i in range(numInLine):
            writingFile.write(' q' + str(i))
          writingFile.write('\n')

          writingFile.write('.constants ')
          for i in range(numInLine):
            writingFile.write('0')
          writingFile.write('\n')

          writingFile.write('.garbage ')
          for i in range(numInLine):
            writingFile.write('-')
          writingFile.write('\n')

          writingFile.write('begin\n')

        elif aLine[0] == 'h' or :aLine[0] == 'y' or aLine[0] == 'z' or aLine[0] == 'h'
          writingFile.write()

