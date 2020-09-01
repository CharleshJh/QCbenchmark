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
      writingFile.write('OPENQASM 2.0;\n')
      writingFile.write('include "qelib1.inc";\n')
      for fl in range(len(fileLines)):
        aLine = fileLines[fl].split()
        numInLine = re.findall('[0-9]+', fileLines[fl])

        if aLine[0] == '.numvars':
          writingFile.write('.numvars ' + str(numInLine[0]) + '\n')

        if aLine[0] == '.variables':
          qbitList = aLine
          del qbitList[0]

        if aLine[0] == 'h1':
          if 
          writingFile.write('h ')
