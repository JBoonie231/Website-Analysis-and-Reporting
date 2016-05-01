#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <vector>
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
};

#endif



//make database name not hard coded and table name not hard coded
