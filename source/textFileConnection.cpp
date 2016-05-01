// Libraries
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <locale>
#include <algorithm>

// Included Header Files
#include "Connection.h"
#include "textFileConnection.h"


using namespace std;

ifstream databaseFile;

string txtHashIdentifier="";


//use getHash() on both objects and then compare. Don't need an equals function =>  conn1->getHashId == conn2->getHashId


string textFileConnection::getTableContents(string tableName)
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

  table.erase( remove( table.begin(), table.end(), ' ' ), table.end() );
  table.erase( remove( table.begin(), table.end(), '\t' ), table.end() );

  return table;
}


string textFileConnection::getHashId()
{
  return txtHashIdentifier;
}


void textFileConnection::setHashId(vector<string> identifiers)
{
  for(int i=0; i<identifiers.size(); i++)
  {
    txtHashIdentifier = txtHashIdentifier.append(identifiers[i]);
  }
}


textFileConnection::textFileConnection(vector<string>& identifiers)
{
  setHashId(identifiers);
  char* filename = &txtHashIdentifier[0];
  databaseFile.open(filename);
}


textFileConnection::~textFileConnection()
{
  databaseFile.close();
}
