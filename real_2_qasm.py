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
          writingFile.write('qreg q[' + str(numInLine[0]) + '];\n')

        elif aLine[0] == '.variables':
          qbitList = aLine
          del qbitList[0]

        # Hadamard
        elif aLine[0] == 'h1':
          if len(numInLine) == 2:
            if qbitList[numInLine[1]] == aLine[1]:
              writingFile.write('h q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # X
        elif aLine[0] == 't1':
          if len(numInLine) == 2:
            if qbitList[numInLine[1]] == aLine[1]:
              writingFile.write('x q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Y
        elif aLine[0] == 'y1':
          if len(numInLine) == 2:
            if qbitList[numInLine[1]] == aLine[1]:
              writingFile.write('y q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Z
        elif aLine[0] == 'z1':
          if len(numInLine) == 2:
            if qbitList[numInLine[1]] == aLine[1]:
              writingFile.write('z q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # S
        elif aLine[0] == 's1':
          if len(numInLine) == 2:
            if qbitList[numInLine[1]] == aLine[1]:
              writingFile.write('s q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Sdg
        elif aLine[0] == 'q1:-2':
          if len(numInLine) == 3:
            if qbitList[numInLine[2]] == aLine[1]:
              writingFile.write('sdg q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # T
        elif aLine[0] == 'q1:4':
          if len(numInLine) == 3:
            if qbitList[numInLine[2]] == aLine[1]:
              writingFile.write('t q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Tdg
        elif aLine[0] == 'q1:-4':
          if len(numInLine) == 3:
            if qbitList[numInLine[2]] == aLine[1]:
              writingFile.write('tdg q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # C-NOT
        elif aLine[0] == 't2':
          if len(numInLine) == 3:
            if qbitList[numInLine[1]] == aLine[1] and qbitList[numInLine[2]] == aLine[2]:
              writingFile.write('cx q[' + numInLine[1] + '],q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # C-Phase
        elif aLine[0] == 'z2':
          if len(numInLine) == 3:
            if qbitList[numInLine[1]] == aLine[1] and qbitList[numInLine[2]] == aLine[2]:
              writingFile.write('cz q[' + numInLine[1] + '],q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
