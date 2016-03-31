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
#include <cctype>
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
  string upperTableName = toUpper(tableName);
  upperTableName = upperTableName+":";

  while(getline(databaseFile, line))
  {
    //need to omit whitespace for each line got to compare without the whitespace
    if (!line.compare(tableName))
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
//equals : compare the hashIdentifier value of two connections

string toUpper(string lower)
{
  char letter;
  string upper;
cout<< lower <<endl;
  for(int i=0; i < lower.size(); i++)
  {
    letter=lower[i];
cout<< letter << " == ";
    upper[i] = toupper(letter);
cout<< upper[i] <<endl;
  }
cout<< "upper="<<upper <<endl;
  return upper;
}

int main()
{
  Connection conn;

  string table = "vists";
  string ret = toUpper(table);
  //string table2 = conn.getTableContents(table);
  cout << ret <<endl;

 return 0;
}



#endif
