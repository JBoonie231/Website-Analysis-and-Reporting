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

using namespace std;


string sqlsqlHashIdentifier="";
string sqlTable="";
int rowNum = 0;

static int callback(void* NotUsed, int argc, char** argv, char** szColName)
{
  if(rowNum==0)
  {
    for(int i = 0; i < argc; i++)
    {
      sqlTable.append(szColName[i]);
      if(i<argc-1)sqlTable.append(",");
    }
    sqlTable.append("\n");
  }
  for(int i = 0; i < argc; i++)
  {
   sqlTable.append(argv[i]);
   if(i<argc-1)sqlTable.append(",");
  }
  sqlTable.append("\n");
  rowNum+=1;
  return 0;
}

sqlite3 *db;
int rc;
string databaseConnection::getTableContents(string tableName)
{
  char *szErrMsg = 0;
  transform(tableName.begin(),tableName.end(),tableName.begin(),::toupper);
  sqlTable = tableName+":\n";


  // prepare our sql statements
  string selectQuery = "SELECT * FROM "+tableName;
  const char* ptr_sqlSelect = selectQuery.c_str();

  // execute sql
  rc = sqlite3_exec(db, ptr_sqlSelect, callback, 0, &szErrMsg);
  if(rc != SQLITE_OK)
  {
    std::cout << "SQL Error: " << szErrMsg << std::endl;
    sqlite3_free(szErrMsg);
  }

  return sqlTable;
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
  rc = sqlite3_open(/*"Sqlite_Test.db"*/filename, &db);
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
  if(db)
  {
    sqlite3_close(db);
  }
}

