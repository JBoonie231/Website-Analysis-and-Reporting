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

vector<string> identifiers;
string hashIdentifier="";


//use get hash from both objects and then compare. Don't need an equals function =>  conn1->getHashId == conn2->getHashId
/*bool Connection::equals(textFileConnection conn2)
{
  if (getHashId() == conn2.getHashId())return true;
  else return false;
}*/


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
  return table;
}


string textFileConnection::getHashId()
{
  return hashIdentifier;
}


void textFileConnection::setHashId(vector<string> identifiers)
{
  for(int i=0; i<identifiers.size(); i++)
  {
    hashIdentifier = hashIdentifier.append(identifiers[i]);
  }
}


textFileConnection::textFileConnection(vector<string>& identifiers)
{
  setHashId(identifiers);
  char* filename = &hashIdentifier[0];
  databaseFile.open(filename);
}


textFileConnection::~textFileConnection()
{
  databaseFile.close();
}

