#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

// Libraries
#include <iostream>
#include <string>
#include <string.h>
//#include <json.h>
#include <fstream>
#include <vector>
// Included Header Files
#include "Connection.h"
#include <ctype.h>
#include <cctype>
#include <stdio.h>
#include <locale>
#include <algorithm>

using namespace std;

ifstream databaseFile;

vector<string> identifiers.push_back("Website_Database.txt");
string hashIdentifier="Website_Database.txt";

Connection::Connection(vector<string> identifiers)
{
    databaseFile.open("Website_Database.txt");//change to depend on length of vector not the zero index
}

bool equals(Connection conn)
{
    
}

vector<string> vectorize(string table)
{
  //for(string::iterator it=table.begin(); it!=table.end(); ++it)
  for (int i=0; i<table.size(); i++)
  {
    //cout << *it <<endl;
    cout<< table[i] <<endl;
  }
}

string Connection::getTableContents(string tableName)
{
  string line, line2;
  string table;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);
  string tableNameLine = tableName+":";

  while(getline(databaseFile, line))
  {
    //need to omit whitespace for each line got to compare without the whitespace
    if (!line.compare(tableNameLine))
    {
      table.append(line);
      table.append("\n");
      while(getline(databaseFile, line2))
      {
        table.append(line2);
        table.append("\n");        
      }
      break;
    }
  }
  //vector<string> tableVector = vectorize(table);
  return table;
}

//testing area to run getTableContents()
int main()
{
  Connection conn;

  string table = "visits";
  string table2 = conn.getTableContents(table);
  cout << table2 <<endl;
  
 return 0;
}



#endif
