// Libraries
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <cctype>
#include <locale>
#include <algorithm>

// Included Header Files
#include <ctype.h>
#include <stdio.h>
#include "Connection.h"


using namespace std;

ifstream databaseFile;

vector<string> identifiers;//.push_back("Website_Database.txt");
string hashIdentifier="";
bool sqlFile = false;


bool Connection::equals(Connection conn2)
{
  if (hashIdentifier == getHashId(conn2))return true;
  else return false;
}


string Connection::getTableContents(string tableName)
{
  string line, line2;
  string table;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);
  string tableNameLine = tableName+":";

  while(getline(databaseFile, line))
  {
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
  return table; //returns a simple string
}


string Connection::getHashId(Connection conn)
{
  return hashIdentifier;
}


void Connection::setHashId(vector<string> identifiers)
{
  if (identifiers.size() > 1) sqlFile=true;
  else sqlFile=false;

  for(int i=0; i<identifiers.size(); i++)
  {
    hashIdentifier = hashIdentifier.append(identifiers[i]);
  }
}


Connection::Connection(vector<string>& identifiers)
{
  setHashId(identifiers);

  if(!sqlFile)
  {
    databaseFile.open("Website_Database.txt");//file connection
  }
  else
  {
    //sqlite connection
  }
}


//testing area to run getTableContents()
int main()
{
  vector<string> fileId;
  fileId.push_back("Website_Database.txt");

  Connection conn(fileId);

  string tableInfo = "visits";
  string table = conn.getTableContents(tableInfo);
  cout << table <<endl;
  
  return 0;
}

