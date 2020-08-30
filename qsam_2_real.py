import sys
import os
from os import listdir
from os.path import isfile, isdir, join

mypath = sys.argv[1]
os.chdir(mypath)
if not os.path.exists('out'):
    os.mkdir('out')
os.chdir('..')


