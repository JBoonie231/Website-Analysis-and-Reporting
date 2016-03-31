#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

// Libraries
#include <iostream>
#include <string>
//#include <json.h>
#include <fstream>
#include <vector>
// Included Header Files
#include "Connection.h"
#include <ctype.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;

ifstream databaseFile;
//vector<string> identifiers.push_back("Website_Database.txt");
//string identifiers="Website_Database.txt";

Connection::Connection(/*vector<string> identifiers*/)
{
    databaseFile.open("Website_Database.txt");//change to depend on length of vector not ... the zero
}

string Connection::getTableContents(string tableName)
{
  string line;
  string table;

  while(getline(databaseFile, line))
  {
    //tableName = toupper(tableName);
    tableName = "VISITS:";//+":/n";
    if (getline(databaseFile,line) == tableName)
    {
      table.append(line);
      while(getline(databaseFile, line)
      {
        table.append(line);        
      }
      break;
    }
  }
    return table;
}
//getRow



int main()
{
  Connection conn();

  string table = "VISITS";
  string table2 = conn.getTableContents(table);
  cout << table2 <<endl;

 return 0;
}



#endif
