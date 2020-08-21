/**************************************************************************
  File       [rep.cpp]
  Synopsis   [EevLib benchmark tramsform]
  Author     [Chilsan Zhang]
  Modify     [2020/02/27]
 **************************************************************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <filesystem>
#include <vector>

using namespace std;

#define DEBUG

void help_message() {
  cout << "usage: generator_name [ -1 | -2 ] <input_file>" << endl
    << "-1 means type 1: turn - into random" << endl
    << "-2 means type 2: turn - into 0 and apply Hadamard" << endl;
}

size_t myStrGetTok(const string& str, string& tok, size_t pos = 0, const char del = ' ') {
  size_t begin = str.find_first_not_of(del, pos);
  if (begin == string::npos) { tok = ""; return begin; }
  size_t end = str.find_first_of(del, begin);
  tok = str.substr(begin, end - begin);
  return end;
}

void repFile(const int& format, const string& fileName) {

  cout << "repFile() is called..." << endl;

  fstream file;
  file.open(fileName, ios::in);

  if (!file.is_open()) {
    cout << "Maybe file name typo" << endl;
    return;
  }

  srand(time(NULL));
  vector<string> content, variables;
  vector<int> needH;
  string tmpString, token;
  size_t pos;
  bool flag = false;
  int numvar = 0;

  if (format == 0) {
    while (getline(file, tmpString)) {
      pos = myStrGetTok(tmpString, token);
      if (strcmp(token.c_str(), ".constants") == 0) {
        flag = true;
        myStrGetTok(tmpString, token, pos);
        for (string::iterator it = token.begin(); it != token.end(); ++it) {
          if (*it == '-') {
            *it = (char)((rand() % 2) + 48);
          }
        }
        tmpString = ".constants " + token;
      }
      else if (strcmp(token.c_str(), ".numvars") == 0) {
        pos = myStrGetTok(tmpString, token, pos);
        numvar = stoi(token);
      }
      else if ((strcmp(token.c_str(), ".begin") == 0 || strcmp(token.c_str(), ".garbage") == 0)
          && flag == false) {
        flag = true;
        token = ".constants ";
        for (int i = 0; i < numvar; ++i) {
          token = token + (char)((rand() % 2) + 48);
        }
        content.push_back(token);
      }
#ifdef DEBUG1
      cout << tmpString << endl;
#endif
      content.push_back(tmpString);
    }
  }
  else if (format == 1) {
    while (getline(file, tmpString)) {
      pos = myStrGetTok(tmpString, token);
      if (strcmp(token.c_str(), ".variables") == 0) {
        while (pos != string::npos) {
          pos = myStrGetTok(tmpString, token, pos);
          variables.push_back(token);
        }
      }
      else if (strcmp(token.c_str(), ".numvars") == 0) {
        pos = myStrGetTok(tmpString, token, pos);
        numvar = stoi(token);
      }
      else if (strcmp(token.c_str(), ".constants") == 0) {
        flag = true;
        myStrGetTok(tmpString, token, pos);
        for (int i = 0, n = token.size(); i < n; ++i) {
          if (token[i] == '-') {
            needH.push_back(i);
            token[i] = (char)(48);
          }
        }
        tmpString = ".constants " + token;
      }
      else if ((strcmp(token.c_str(), ".begin") == 0 || strcmp(token.c_str(), ".garbage") == 0)
          && flag == false) {
        token = ".constants ";
        for (int i = 0; i < numvar; ++i) {
          token = token + (char)(48);
        }
        content.push_back(token);
        token = ".begin";
      }

#ifdef DEBUG1
      cout << tmpString << endl;
#endif
      content.push_back(tmpString);

      if (strcmp(token.c_str(), ".begin") == 0) {

#ifdef DEBUG1
        cout << needH.size() << endl;
#endif
        if (flag == true) {
          for (int i = 0, n = numvar; i < n; ++i) {
            token = "h1 " + variables[needH[i]];
#ifdef DEBUG1
            cout << token << endl;
#endif
            content.push_back(token);
          }
        }
        else {
          for (int i = 0, n = variables.size(); i < n; ++i) {
            token = "h1 " + variables[i];
#ifdef DEBUG1
            cout << token << endl;
#endif
            content.push_back(token);
          }
        }
      }

    }
  }

  file.close();

  tmpString = fileName;
  for (int i = 0; i < 4; ++i) {
    tmpString.pop_back();
  }
  file.open(tmpString, ios::out);
  for (int i = 0, n = content.size(); i < n; ++i) {
    file << content[i] << endl;
  }
  file.close();
}

int main(int argc, char* argv[]) {

  if (argc == 1 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
    help_message();
    return 0;
  }

#ifdef DEBUG
  cout << "running..." << endl;
#endif

  if (strcmp(argv[1],"-1") == 0)
    repFile(0, argv[2]);
  else if (strcmp(argv[1],"-2") == 0)
    repFile(1, argv[2]);
  else
    cout << "Maybe command typo" << endl;

#ifdef DEBUG
  cout << "end" << endl;
#endif

  return 0;
}

