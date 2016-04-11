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
  if (getHashId() == conn2.getHashId())return true;
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


string Connection::getHashId()
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


/*Testing main for running Connection class methods*/
int main()
{
//-----------------------------------------------------------------------------------
  //getTable() test
  vector<string> fileId;
  fileId.push_back("Website_Database.txt");
  Connection websiteConn(fileId);

  string tableInfo = "visits";
  string table = websiteConn.getTableContents(tableInfo);
  cout << table <<endl;

//-----------------------------------------------------------------------------------
  //getHashId() Test
  fileId.pop_back();
  fileId.push_back("User_Database.txt");
  Connection userConn(fileId);
  string websiteHashId = websiteConn.getHashId();
  string userHashId = userConn.getHashId();

//-----------------------------------------------------------------------------------
  //equals() Test
  bool same = websiteConn.equals(userConn);
  string compare = "";
  if (same) compare = "True";else compare = "False";
  cout<< websiteHashId << " == " << userHashId << " : " << compare <<endl;
  same = websiteConn.equals(websiteConn);
  if (same) compare = "True";else compare = "False";
  cout<< websiteHashId << " == " << websiteHashId << " : " << compare <<endl;
  
  return 0;
}

