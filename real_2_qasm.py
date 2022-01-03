"""
File       [real_2_qasm.py]
Synopsis   [translate .real in a directory to .qasm]
Author     [Chilsan Jhang]
Modify     [2022/01/03]
"""

"""
Usage: python3 real_2_qasm.py <real folder> 
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
      qbitList = {}
      for fl in range(len(fileLines)):
        aLine = fileLines[fl].split()
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
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('h q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # X
        elif aLine[0] == 't1':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('x q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Y
        elif aLine[0] == 'y1':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('y q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Z
        elif aLine[0] == 'z1':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('z q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # S
        elif aLine[0] == 's1':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('s q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Sdg
        elif aLine[0] == 'q1:-2':
          if len(aLine) == 3:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('sdg q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # T
        elif aLine[0] == 'q1:4':
          if len(aLine) == 2:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('t q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Tdg
        elif aLine[0] == 'q1:-4':
          if len(aLine) == 2:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('tdg q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-X 1
        elif aLine[0] == 'rx_pi_2':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('rx(pi/2) q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-X 2
        elif aLine[0] == 'rx1:2':
          if len(aLine) == 3:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('rx(pi/2) q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-Y 1
        elif aLine[0] == 'ry_pi_2':
          if len(aLine) == 2:
            if qbitList.get(aLine[1]) != 'None':
              writingFile.write('ry(pi/2) q[' + str(qbitList[aLine[1]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Rotation-Y 2
        elif aLine[0] == 'ry1:2':
          if len(aLine) == 3:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('ry(pi/2) q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

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
            writingFile.write('ccx q[')
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
            sys.exit('qbit name error')

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
