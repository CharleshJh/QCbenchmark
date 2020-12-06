"""
File       [real_2_qasm.py]
Synopsis   [translate .real in a directory to .qasm]
Author     [Chilsan Jhang]
Modify     [2020/09/01]
"""
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
    f = open(target, 'r')
    fileLines = f.readlines()
    splitPath = f.name.split('/')
    tmpNum = len(splitPath)
    splitPath.append(splitPath[tmpNum - 1])
    splitPath[tmpNum - 1] = 'out'
    path = '/'.join(splitPath)
    path = path.replace('.real', '.qasm')

    with open(path, 'w') as writingFile:
      writingFile.write('OPENQASM 2.0;\n')
      writingFile.write('include "qelib1.inc";\n')
      for fl in range(len(fileLines)):
        aLine = fileLines[fl].split()
        numInLine = re.findall('[0-9]+', fileLines[fl])

        if aLine[0] == '.numvars':
          writingFile.write('qreg q[' + str(numInLine[0]) + '];\n')
          writingFile.write('creg c[' + str(numInLine[0]) + '];\n')
          numOfQbit = int(numInLine[0])

        elif aLine[0] == '.variables':
          qbitList = aLine
          del qbitList[0]

        elif aLine[0] == '.version' or aLine[0] == '.constants' or aLine[0] == '.garbage' or aLine[0] == '.begin':
          continue

        # Hadamard
        elif aLine[0] == 'h1':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('h q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # X
        elif aLine[0] == 't1':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('x q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Y
        elif aLine[0] == 'y1':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('y q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Z
        elif aLine[0] == 'z1':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('z q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # S
        elif aLine[0] == 's1':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('s q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Sdg
        elif aLine[0] == 'q1:-2':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[2])] == aLine[1]:
              writingFile.write('sdg q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # T
        elif aLine[0] == 'q1:4':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[2])] == aLine[1]:
              writingFile.write('t q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Tdg
        elif aLine[0] == 'q1:-4':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[2])] == aLine[1]:
              writingFile.write('tdg q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-X 1
        elif aLine[0] == 'rx_pi_2':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('rx(pi/2) q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-X 2
        elif aLine[0] == 'rx1:2':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[2])] == aLine[1]:
              writingFile.write('rx(pi/2) q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-Y 1
        elif aLine[0] == 'ry_pi_2':
          if len(numInLine) == 2:
            if qbitList[int(numInLine[1])] == aLine[1]:
              writingFile.write('ry(pi/2) q[' + numInLine[1] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-Y 2
        elif aLine[0] == 'ry1:2':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[2])] == aLine[1]:
              writingFile.write('ry(pi/2) q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # C-NOT
        elif aLine[0] == 't2':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[1])] == aLine[1] and qbitList[int(numInLine[2])] == aLine[2]:
              writingFile.write('cx q[' + numInLine[1] + '],q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # C-Phase
        elif aLine[0] == 'z2':
          if len(numInLine) == 3:
            if qbitList[int(numInLine[1])] == aLine[1] and qbitList[int(numInLine[2])] == aLine[2]:
              writingFile.write('cz q[' + numInLine[1] + '],q[' + numInLine[2] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Toffoli
        elif aLine[0] == 't3':
          if len(numInLine) == 4:
            if qbitList[int(numInLine[1])] == aLine[1] and qbitList[int(numInLine[2])] == aLine[2] and qbitList[int(numInLine[3])] == aLine[3]:
              writingFile.write('ccx q[' + numInLine[1] + '],q[' + numInLine[2] + '],q[' + numInLine[3] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Fredkin a.k.a. C-swap
        elif aLine[0] == 'f3':
          if len(numInLine) == 4:
            if qbitList[int(numInLine[1])] == aLine[1] and qbitList[int(numInLine[2])] == aLine[2] and qbitList[int(numInLine[3])] == aLine[3]:
              writingFile.write('cswap q[' + numInLine[1] + '],q[' + numInLine[2] + '],q[' + numInLine[3] + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # measure
        elif aLine[0] == '.end':
          for i in range(numOfQbit):
            writingFile.write('measure q[' + str(i) + '] -> c[' + str(i) + '];\n')
          writingFile.close()

        else:
            sys.exit(aLine[0] + ' not supported')

