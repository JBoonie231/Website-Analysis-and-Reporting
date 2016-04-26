#ifndef TEXTFILECONNECTION_H
#define TEXTFILECONNECTION_H
#include <vector>

using namespace std;


class textFileConnection:public Connection 
{
  private:
  void setHashId(vector<string> identifiers);
  vector<string> identifiers;
  string hashIdentifier;

  public:
  textFileConnection(vector<string>& identifiers);
  ~textFileConnection();
  string getHashId();
  string getTableContents(string table);
};

#endif