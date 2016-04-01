#ifndef CONNECTION_H
#define CONNECTION_H

// Libraries
#include <iostream>
#include <string>
//#include <json.h>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <locale>
#include <algorithm>

using namespace std;


class Connection
{
  protected:
  string hashIdentifier; 
  vector<string> identifiers;//path to file but for DB connection it something else

  public:
  Connection();//vector<string> identifiers);
  string getTableContents (string table);
};

string toUpper (string lower);


#endif