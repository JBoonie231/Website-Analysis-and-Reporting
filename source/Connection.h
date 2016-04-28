#ifndef CONNECTION_H
#define CONNECTION_H
#include <vector>
using namespace std;

class Connection
{
  protected:
  virtual void setHashId(vector<string> identifiers) = 0;
  vector<string> identifiers;
  string hashIdentifier;

  public:
  virtual string getHashId() = 0;
  virtual string getTableContents(string table) = 0;
};

#endif
