/**************************************************************************
  File       [gen.cpp]
  Synopsis   [Entanglement & fake QFT]
  Author     [Chilsan Zhang]
  Modify     [2020/02/27]
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define DEBUG

void help_message() {
  cout << "usage: generator_name [ -E | -fQ | -rQ ] [ int number ] <output_file>" << endl
    << "-E  means entangle" << endl
    << "-fQ means fake     QFT" << endl
    << "-rQ means real     QFT" << endl
    << "-cQ means clifford QFT" << endl;
}

bool myStr2Int(const string& str, int& num) {

#ifdef DEBUG1
  cout << "str2int called" << endl;
#endif

  num = 0;
  size_t i = 0;
  int sign = 1;
  if (str[0] == '-') { sign = -1; i = 1; }
  bool valid = false;
  for (; i < str.size(); ++i) {
    if (isdigit(str[i])) {
      num *= 10;
      num += int(str[i] - '0');
      valid = true;
    }
    else return false;
  }
  num *= sign;
  return valid;
}

int myPow(const int& x, const int& p) {
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0)
    return tmp * tmp;
  else
    return x * tmp * tmp;
}

void appro100(const int num, const int qb, fstream& file) {
  switch (num) {
    case 0:
      break;
    case 1:
      file << "s1 q" << qb << endl;
      break;
    case 2:
      file << "q1:4 q" << qb << endl;
      break;
    case 3:
      file << "s1 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb  << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 4:
      file << "q1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 5:
      file << "h1 q" << qb << "\ns1 q" << qb << "\nx1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << endl;
      break;
    case 6:
      file << "h1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 7:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 8:
      file << "q1:-2 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 9:
      file << "h1 q" << qb << "\ns1 q" << qb << "\nx1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << endl;
      break;
    case 10:
      file << "x1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-2 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << endl;
      break;
    case 11:
      file << "q1:-2 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 12:
      file << "h1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 13:
      file << "h1 q" << qb << "\nq1:-2 q" << qb << "\nx1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 14:
      file << "h1 q" << qb << "\nq1:-2 q" << qb << "\nx1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 15:
      file << "s1 q" << qb << "\nh1 q" << qb << "\nq1:-2 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 16:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 17:
      file << "q1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
        "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 18:
        file << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << endl;
        break;
    case 19:
        file << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\ns1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nz1 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
        break;
    default:
      break;
  }
}

void approInv100(const int num, const int qb, fstream& file) {
  switch (num) {
    case 0:
      break;
    case 1:
      file << "q1:-2 q" << qb << endl;
      break;
    case 2:
      file << "q1:-4 q" << qb << endl;
      break;
    case 3:
      file << "h1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb 
        << "\nq1:-2 q" << qb << endl;
      break;
    case 4:
      file << "h1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << endl;
      break;
    case 5:
      file << "q1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nx1 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb
        << endl;
      break;
    case 6:
      file << "q1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 7:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << endl;
      break;
    case 8:
      file << "h1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nz1 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << endl;
      break;
    case 9:
      file << "q1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nx1 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 10:
      file << "q1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\ns1 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nx1 q" << qb << endl;
      break;
    case 11:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << endl;
      break;
    case 12:
      file << "q1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nz1 q" << qb << "\nh1 q" << qb << endl;
      break;
    case 13:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb 
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb 
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb 
        << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb
        << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb 
        << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nx1 q" << qb << "\ns1 q" << qb
        << "\nh1 q" << qb << endl;
      break;
    case 14:
      file << "q1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb
        << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nx1 q" << qb << "\ns1 q" << qb << 
        "\nh1 q" << qb << endl;
      break;
    case 15:
      file << "z1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\ns1 q" << qb << "\nh1 q" << qb << 
        "\nq1:-2 q" << qb << endl;
      break;
    case 16:
      file << "q1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb
        << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nz1 q" << qb << endl;
      break;
    case 17:
      file << "z1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
        "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
        "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
        "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
        "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << endl;
      break;
    case 18:
        file << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << endl;
        break;
    case 19:
        file << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << 
"\nh1 q" << qb << "\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << 
"\nq1:-4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << "\nz1 q" << qb << 
"\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nh1 q" << qb << 
"\nz1 q" << qb << "\nq1:4 q" << qb << "\nh1 q" << qb << "\nq1:-4 q" << qb << "\nq1:-2 q" << qb << 
"\nh1 q" << qb << "\nq1:-4 q" << qb << "\nz1 q" << qb << "\nh1 q" << qb << "\ns1 q" << qb << endl;
        break;
    default:
      break;
  }
}
void genFile(const int& qbits, const int& format, const string& fileName) {

  cout << "genFile() is called..." << endl;

  fstream file;
  file.open(fileName, ios::out);

  if (!file.is_open()) {
    cout << "Maybe file name typo" << endl;
    return;
  }

  // headers
  file << ".numvars " << qbits << endl << ".variables";
  for (int i = 0; i < qbits; ++i) {
    file << " q" << i;
  }
  file << endl << ".constants ";

  if (format == 0 || format == 2) {
    srand(time(NULL));
    for (int i = 0; i < qbits; ++i) {
      file << (rand() % 2);
    }
  }
  else if (format == 1) {
    for (int i = 0; i < qbits; ++i) {
      file << 0;
    }
  }

  file << endl << ".garbage ";
  for (int i = 0; i < qbits; ++i) {
    file << "-";
  }
  file << endl << ".begin" << endl;


  // entangle
  if (format == 0) {
    file << "h1 q0" << endl;
    for (int i = 1; i < qbits; ++i) {
      file << "t2 q0 q" << i << endl;
    }
  }

  // fake QFT
  else if (format == 1) {
    for (int i = 0; i < qbits; ++i) {
      file << "h1 q" << i << endl;
      for (int j = i + 1; j < qbits; ++j) {
        file << "q2:4 q" << j << " q" << i << endl;
      }
    }
  }

  // real QFT
  else if (format == 2) {
    for (int i = 0; i < qbits; ++i) {
      file << "h1 q" << i << endl;
      for (int j = 1, k = (qbits - i); j < k; ++j) {
        file << "q2:" << myPow(2, j) << " q" << (i + j) << " q" << i << endl;
      }
    }
  }

  else if (format == 3) {
    for (int i = 0; i < qbits; ++i) {
      file << "h1 q" << i << endl;
      for (int j = 1, k = (qbits - i); j < k; ++j) {
        appro100(j + 1, i + j, file);
        file << "x2 q" << (i + j) << " q" << i << endl;
        approInv100(j + 1, i, file);
        file << "x2 q" << (i + j) << " q" << i << endl;
        appro100(j + 1, i, file);
      }
    }
  }

  file << ".end";

  file.close();
}

int main(int argc, char* argv[]) {

  if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
    help_message();
    return 0;
  }

  int qbits;
  if (!myStr2Int(argv[2], qbits)) {
    cout << "Can't convert integer" << endl;
    return 0;
  }
  if (qbits == 0) {
    cout << "Please use a number greater than 0";
    return 0;
  }

#ifdef DEBUG1
  cout << "running..." << endl;
#endif

  if (strcmp(argv[1],"-E") == 0)
    genFile(qbits, 0, argv[3]);
  else if (strcmp(argv[1],"-fQ") == 0)
    genFile(qbits, 1, argv[3]);
  else if (strcmp(argv[1], "-rQ") == 0)
    genFile(qbits, 2, argv[3]);
  else if (strcmp(argv[1], "-cQ") == 0) {
    if (qbits > 18) {
      cout << "Can't generate > 18 qbits" << endl;
      return 0;
    }
    genFile(qbits, 3, argv[3]);
  }
  else
    cout << "Maybe command typo" << endl;

#ifdef DEBUG1
  cout << "end" << endl;
#endif

  return 0;
}

