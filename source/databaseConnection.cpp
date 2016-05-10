// Libraries
#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>

// headers
#include "sqlite3.h"
#include "Connection.h"
#include "databaseConnection.h"
#include "json/json.h"


using namespace std;

string sqlHashIdentifier="";
string sqlReturn="";
sqlite3* database;
int rc;
int rowNum = 0;
Json::Value jsonTable;
Json::Value jsonRows;


static int jsonCallback(void* NotUsed, int colNum, char** value, char** colName)
{
  int i;
	for(i=0; i<colNum; i++)
	{
    const char* col_name = colName[i];
    const char* row_value = value[i];
    jsonRows[rowNum][col_name] = row_value;
	}
  rowNum+=1;
	return 0;
}

static int callback(void* NotUsed, int argc, char** argv, char** szColName)
{
  if(rowNum==0)
  {
    for(int i = 0; i < argc; i++)
    {
      sqlReturn.append(szColName[i]);
      if(i<argc-1)sqlReturn.append(",");
    }
    sqlReturn.append("\n");
  }
  for(int i = 0; i < argc; i++)
  {
   sqlReturn.append(argv[i]);
   if(i<argc-1)sqlReturn.append(",");
  }
  sqlReturn.append("\n");
  rowNum+=1;
  return 0;
}

Json::Value databaseConnection::getJsonTable(string tableName)
{
  char* errorMsg = 0;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);

  // prepare our sql statements
  string selectQuery = "SELECT * FROM "+tableName;
  const char* ptr_sqlSelect = selectQuery.c_str();

  // execute sql
  rc = sqlite3_exec(database, ptr_sqlSelect, jsonCallback, 0, &errorMsg);
  if(rc != SQLITE_OK)
  {
    std::cout << "SQL Error: " << errorMsg << std::endl;
    sqlite3_free(errorMsg);
  }

  jsonTable[tableName] = jsonRows;

  return jsonTable;
}

string databaseConnection::getTableContents(string tableName)
{
  sqlReturn="";
  char* errorMsg = 0;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);
  sqlReturn = tableName+":\n";

  // prepare our sql statements
  string selectQuery = "SELECT * FROM "+tableName;
  const char* ptr_sqlSelect = selectQuery.c_str();

  // execute sql
  rc = sqlite3_exec(database, ptr_sqlSelect, callback, 0, &errorMsg);
  if(rc != SQLITE_OK)
  {
    std::cout << "SQL Error: " << errorMsg << std::endl;
    sqlite3_free(errorMsg);
  }

  return sqlReturn;
}

string databaseConnection::getTableRow(string tableName, string columnName, string value)
{
  sqlReturn="";
  char* errorMsg = 0;

  // prepare our sql statements
  string selectQuery = "SELECT * FROM "+tableName+" WHERE "+columnName+"='"+value+"'";
  const char* ptr_sqlSelect = selectQuery.c_str();

  // execute sql
  rc = sqlite3_exec(database, ptr_sqlSelect, callback, 0, &errorMsg);
  if(rc != SQLITE_OK)
  {
    std::cout << "SQL Error: " << errorMsg << std::endl;
    sqlite3_free(errorMsg);
  }

  return sqlReturn;
}



void databaseConnection::setHashId(vector<string> identifiers)
{
  for(int i=0; i<identifiers.size(); i++)
  {
    sqlHashIdentifier = sqlHashIdentifier.append(identifiers[i]);
  }
}



string databaseConnection::getHashId()
{
  return sqlHashIdentifier;
}



databaseConnection::databaseConnection(vector<string>& identifiers)
{
  setHashId(identifiers);
  char* filename = &sqlHashIdentifier[0];

  // open database
  rc = sqlite3_open(filename, &database);
  if(rc)
  {
    std::cout << "Can't open database\n";
  }
  else
  {
    //std::cout << "Open database successfully\n";
  }
}



databaseConnection::~databaseConnection()
{
  // close database
  if(database)
  {
    sqlite3_close(database);
  }
}
