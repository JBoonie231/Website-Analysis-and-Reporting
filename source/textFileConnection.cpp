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
#include "json/json.h"
#include "json/json-forwards.h"

using namespace std;

ifstream databaseFile;
string txtHashIdentifier="";


Json::Value textFileConnection::getJsonTable(string tableName)
{
  Json::Value jsonTable;
  jsonTable["table_name"]["column_name"] = "value";
  return jsonTable;
}


string textFileConnection::getTableRow(string tableName, string columnName, string value)
{
  databaseFile.clear();
  databaseFile.seekg(0, ios::beg);

  string line, line2;
  string table;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);
  string tableNameLine = tableName+":";

  while(getline(databaseFile, line))
  {
    if (!line.compare(tableNameLine))
    {
      while(getline(databaseFile, line2))
      {
        line2.erase( remove( line2.begin(), line2.end(), ' ' ), line2.end() );
        line2.erase( remove( line2.begin(), line2.end(), '\t' ), line2.end() );
        size_t found = line2.find(",");
        if(found!=std::string::npos)
        {
          string subValue = line2.substr(0,found);
          if(!subValue.compare(value))table.append(line2);
        }
        else break;        
      }
      break;
    }
  }
  return table;
}



string textFileConnection::getTableContents(string tableName)
{
  databaseFile.clear();
  databaseFile.seekg(0, ios::beg);

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
        size_t found = line2.find(",");
        if(found!=std::string::npos)
        {
          table.append(line2);
          table.append("\n");
        }
        else break;        
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
  string elm_filename = identifiers[0];
  char* filename = &elm_filename[0];
  databaseFile.open(filename);
}



textFileConnection::~textFileConnection()
{
  databaseFile.close();
}
