"""
File       [real_2_qasm.py]
Synopsis   [translate .real in a directory to .qasm]
Author     [Chilsan Jhang]
Modify     [2020/09/01]
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
            qbitList[aLine[i]] = i
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
          if len(aLine) == 3:
            if qbitList[int(str(qbitList[aLine[2]]))] == aLine[1]:
              writingFile.write('t q[' + str(qbitList[aLine[2]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Tdg
        elif aLine[0] == 'q1:-4':
          if len(aLine) == 3:
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
        elif aLine[0] == 't3':
          if len(aLine) == 4:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't4':
          if len(aLine) == 5:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't5':
          if len(aLine) == 6:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't6':
          if len(aLine) == 7:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]])+ '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't7':
          if len(aLine) == 8:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't8':
          if len(aLine) == 9:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't9':
          if len(aLine) == 10:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't10':
          if len(aLine) == 11:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't11':
          if len(aLine) == 12:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 't12':
          if len(aLine) == 13:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 't13':
          if len(aLine) == 14:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't14':
          if len(aLine) == 15:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 't15':
          if len(aLine) == 16:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 't16':
          if len(aLine) == 17:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't17':
          if len(aLine) == 18:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None' and qbitList.get(aLine[17]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '],q[' + str(qbitList[aLine[17]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't18':
          if len(aLine) == 19:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None' and qbitList.get(aLine[17]) != 'None' and qbitList.get(aLine[18]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '],q[' + str(qbitList[aLine[17]]) + '],q[' + str(qbitList[aLine[18]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 't19':
          if len(aLine) == 20:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None' and qbitList.get(aLine[17]) != 'None' and qbitList.get(aLine[18]) != 'None' and qbitList.get(aLine[19]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '],q[' + str(qbitList[aLine[17]]) + '],q[' + str(qbitList[aLine[18]]) + '],q[' + str(qbitList[aLine[19]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't20':
          if len(aLine) == 21:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None' and qbitList.get(aLine[17]) != 'None' and qbitList.get(aLine[18]) != 'None' and qbitList.get(aLine[19]) != 'None' and qbitList.get(aLine[20]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '],q[' + str(qbitList[aLine[17]]) + '],q[' + str(qbitList[aLine[18]]) + '],q[' + str(qbitList[aLine[19]]) + '],q[' + str(qbitList[aLine[20]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 't21':
          if len(aLine) == 22:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None' and qbitList.get(aLine[15]) != 'None' and qbitList.get(aLine[16]) != 'None' and qbitList.get(aLine[17]) != 'None' and qbitList.get(aLine[18]) != 'None' and qbitList.get(aLine[19]) != 'None' and qbitList.get(aLine[20]) != 'None' and qbitList.get(aLine[21]) != 'None':
              writingFile.write('ccx q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '],q[' + str(qbitList[aLine[15]]) + '],q[' + str(qbitList[aLine[16]]) + '],q[' + str(qbitList[aLine[17]]) + '],q[' + str(qbitList[aLine[18]]) + '],q[' + str(qbitList[aLine[19]]) + '],q[' + str(qbitList[aLine[20]]) + '],q[' + str(qbitList[aLine[21]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        # Fredkin a.k.a. C-swap
        elif aLine[0] == 'f3':
          if len(aLine) == 4:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None':
              writingFile.write('cswap q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 'f4':
          if len(aLine) == 5:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None':
              writingFile.write('cswap q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]])  + '],q[' + str(qbitList[aLine[4]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 'f5':
          if len(aLine) == 6:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None':
              writingFile.write('cswap q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]])  + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')

        elif aLine[0] == 'f6':
          if len(aLine) == 7:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None':
              writingFile.write('cswap q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]])  + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '];\n')
            else:
              sys.exit('qbit name error')
          else:
            sys.exit('qbit name error')
        
        elif aLine[0] == 'f14':
          if len(aLine) == 15:
            if qbitList.get(aLine[1]) != 'None' and qbitList.get(aLine[2]) != 'None' and qbitList.get(aLine[3]) != 'None' and qbitList.get(aLine[4]) != 'None' and qbitList.get(aLine[5]) != 'None' and qbitList.get(aLine[6]) != 'None' and qbitList.get(aLine[7]) != 'None' and qbitList.get(aLine[8]) != 'None' and qbitList.get(aLine[9]) != 'None' and qbitList.get(aLine[10]) != 'None' and qbitList.get(aLine[11]) != 'None' and qbitList.get(aLine[12]) != 'None' and qbitList.get(aLine[13]) != 'None' and qbitList.get(aLine[14]) != 'None':
              writingFile.write('cswap q[' + str(qbitList[aLine[1]]) + '],q[' + str(qbitList[aLine[2]]) + '],q[' + str(qbitList[aLine[3]])  + '],q[' + str(qbitList[aLine[4]]) + '],q[' + str(qbitList[aLine[5]]) + '],q[' + str(qbitList[aLine[6]]) + '],q[' + str(qbitList[aLine[7]]) + '],q[' + str(qbitList[aLine[8]]) + '],q[' + str(qbitList[aLine[9]]) + '],q[' + str(qbitList[aLine[10]]) + '],q[' + str(qbitList[aLine[11]]) + '],q[' + str(qbitList[aLine[12]]) + '],q[' + str(qbitList[aLine[13]]) + '],q[' + str(qbitList[aLine[14]]) + '];\n')
            else:
              sys.exit('qbit name error')
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
