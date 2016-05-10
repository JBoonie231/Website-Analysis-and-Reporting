#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"

using namespace std;

class databaseConnection:public Connection 
{
  private:
    void setHashId(vector<string> identifiers);
    string sqlHashIdentifier;
  public:
    databaseConnection(vector<string>& identifiers);
    ~databaseConnection();
    string getHashId();
    string getTableContents(string tableName);
    string getTableRow(string tableName, string columnName, string value);
    Json::Value getJsonTable(string tableName);
};

#endif
