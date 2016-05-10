#ifndef TEXTFILECONNECTION_H
#define TEXTFILECONNECTION_H

#include <vector>
#include <fstream>
#include "json/json.h"

using namespace std;


class textFileConnection:public Connection 
{
  private:
    void setHashId(vector<string> identifiers);
    string txtHashIdentifier;
    ifstream databaseFile;

  public:
    textFileConnection(vector<string>& identifiers);
    ~textFileConnection();
    string getHashId();
    string getTableContents(string tableName);
    string getTableRow(string tableName, string columnName, string value);
    Json::Value getJsonTable(string tableName);
};

#endif
