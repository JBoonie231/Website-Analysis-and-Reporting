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
    databaseFile.open("Website_Database.txt");//change to depend on length of vector not the zero index
}

string Connection::getTableContents(string tableName)
{
  string line, line2;
  string table;

  while(getline(databaseFile, line))
  {
    //tableName = toupper(tableName);
    tableName = "VISITS:";//+":/n";
    //need to omit whitespace for each line got to compare without the whitespace
    if (line.compare(tableName))
    {
      table.append(line);
      while(getline(databaseFile, line2))
      {
        table.append(line2);        
      }
      break;
    }
  }
    return table;
}
//getRow



int main()
{
  Connection conn;

  string table = "VISITS";
  string table2 = conn.getTableContents(table);
  cout << table2 <<endl;

 return 0;
}



#endif
