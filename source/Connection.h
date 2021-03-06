#ifndef CONNECTION_H
#define CONNECTION_H

#include <vector>
#include "json/json.h"

using namespace std;

class Connection
{
  protected:
    virtual void setHashId(vector<string> identifiers) = 0;

  public:
    virtual string getHashId() = 0;
    virtual string getTableContents(string table) = 0;
    virtual string getTableRow(string tableName, string columnName, string value) = 0;
    virtual Json::Value getJsonTable(string tableName) = 0;
};

#endif
