#ifndef CONNECTION_H
#define CONNECTION_H

using namespace std;


class Connection
{
  private:
  bool sqlFile; //flag to ID file type
  void setHashId(vector<string> identifiers);

  protected:
  vector<string> identifiers; //identifiers of specific connection
  string hashIdentifier; //appended values of identifiers[]

  public:
  Connection(vector<string>& identifiers);
  string getTableContents (string table);
  string getHashId();
  bool equals(Connection conn2); //compares hashIdentifiers of 2 Connections
};

#endif
