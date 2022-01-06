"""
File       [real_2_qasm.py]
Synopsis   [translate .real in a directory to .qasm]
Author     [Chilsan Jhang]
Modify     [2022/01/03]
"""

"""
Usage: python3 real_2_qasm.py <real folder> 
The result folder is at `<real folder>/out`
"""
import sys
import os
from os import listdir
from os.path import isfile, isdir, join
import re

def writeSingleQubitGate(qbitList, line, writingFile, gate):
  if len(line) == 2:
    if qbitList.get(line[1]) != 'None':
      writingFile.write(gate)
      writingFile.write(' q[' + str(qbitList[line[1]]) + '];\n')
    else:
      sys.exit('qbit name error')
  else:
    sys.exit('qbit name error')

try:
  mypath = sys.argv[1]
  os.chdir(mypath)
except:
  print("Please specify a correct absolute path!")

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

    print(target)
    with open(path, 'w') as writingFile:
      writingFile.write('OPENQASM 2.0;\n')
      writingFile.write('include "qelib1.inc";\n')
      qbitList = {}
      for fl in range(len(fileLines)):
        aLine = fileLines[fl].split()
        if len(aLine) == 0:
          continue
        if aLine[0] == '.numvars':
          writingFile.write('qreg q[' + aLine[1] + '];\n')
          writingFile.write('creg c[' + aLine[1] + '];\n')
          numOfQbit = int(len(aLine))
        elif aLine[0] == '.variables':
          for i in range(1, len(aLine)):
            qbitList[aLine[i]] = i-1
        elif aLine[0] == '.version' or aLine[0] == '.constants' or aLine[0] == '.garbage' or aLine[0] == '.begin':
          continue

        # Hadamard
        elif aLine[0] == 'h1':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'h')

        # X
        elif aLine[0] == 't1':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'x')

        # Y
        elif aLine[0] == 'y1':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'y')

        # Z
        elif aLine[0] == 'z1':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'z')

        # S
        elif aLine[0] == 's1':
          writeSingleQubitGate(qbitList, aLine, writingFile, 's')

        # Sdg
        elif aLine[0] == 'q1:-2':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'sdg')

        # T
        elif aLine[0] == 'q1:4':
          writeSingleQubitGate(qbitList, aLine, writingFile, 't')

        # Tdg
        elif aLine[0] == 'q1:-4':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'tdg')

        # Rotation-X
        elif aLine[0] == 'rx_pi_2' or aLine[0] == 'rx1:2':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'rx(pi/2)')

        # Rotation-Y
        elif aLine[0] == 'ry_pi_2' or aLine[0] == 'ry1:2':
          writeSingleQubitGate(qbitList, aLine, writingFile, 'ry(pi/2)')

        # C-NOT
        elif aLine[0] == 't2':
          if len(aLine) == 3:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None':
              writingFile.write('cx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # C-Phase
        elif aLine[0] == 'z2':
          if len(aLine) == 3:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None':
              writingFile.write('cz q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Toffoli
        elif aLine[0][0] == 't' and aLine[0][1:].isalnum():
          qbitLength = int(aLine[0][1:])
          print(qbitLength)
          if len(aLine) != (qbitLength + 1):
            sys.exit('qbit name error')
          else:
            for i in range(1, qbitLength+1):
              if qbitList.get(aLine[i]) == 'None':
                sys.exit('qbit name error')
            # TODO: change to 'ctrl @ x q[' for openQASM 3.0
            if (qbitLength == 3):
              writingFile.write('ccx q[')
            else:
              writingFile.write('mcx q[')

            for i in range(1, qbitLength+1):
              writingFile.write(str(qbitList[aLine[i]]))
              if i != qbitLength:
                writingFile.write('],q[')
              else:
                writingFile.write('];\n')

        # Fredkin a.k.a. C-swap
        elif aLine[0][0] == 'f' and aLine[0][1:].isalnum():
          qbitLength = int(aLine[0][1:])
          print(qbitLength)
          if len(aLine) != (qbitLength + 1):
            sys.exit('qbit name error')
          else:
            for i in range(1, qbitLength+1):
              if qbitList.get(aLine[i]) == 'None':
                sys.exit('qbit name error')
            writingFile.write('cswap q[')
            for i in range(1, qbitLength+1):
              writingFile.write(str(qbitList[aLine[i]]))
              if i != qbitLength:
                writingFile.write('],q[')
              else:
                writingFile.write('];\n')

        # measure
        elif aLine[0] == '.end':
          writingFile.close()
        elif aLine[0] == '.inputs':
          continue
        elif aLine[0] == '.outputs':
          continue
        elif aLine[0] == '.inputbus':
          continue
        elif aLine[0] == '.outputbus':
          continue  
        elif aLine[0][0] == '#':
          continue
        else:
          print(target)
          sys.exit(aLine[0] + ' not supported')
