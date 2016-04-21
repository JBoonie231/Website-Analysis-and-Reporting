#include <iostream>
#include <vector>
#include <string>
#include <string.h>

#include "Connection.h"
#include "textFileConnection.h"

using namespace std;


//Testing Connection class methods
int main()
{
  //textFileConnection.getTable() test
  vector<string> fileId;
  fileId.push_back("Website_Database.txt");
  textFileConnection websiteConn(fileId);

  string tableInfo = "visits";
  string table = websiteConn.getTableContents(tableInfo);
  cout << table <<endl;

//-----------------------------------------------------------------------------------
  //textFileConnection.getHashId() Test
  fileId.pop_back();
  fileId.push_back("User_Database.txt");
  textFileConnection userConn(fileId);
  string websiteHashId = websiteConn.getHashId();
  string userHashId = userConn.getHashId();

  cout<< websiteHashId << " == " << userHashId <<endl;

/*-----------------------------------------------------------------------------------
  //databaseConnection.getTable() test
  //fileId.pop_back();
  fileId.push_back("bedrock.db");
  databaseConnection websiteConn(fileId);
  string tableInfo = "visits";
  string table = websiteConn.getTableContents(tableInfo);
  cout << table <<endl;

//-----------------------------------------------------------------------------------
  //databaseConnection.getHashId() Test
  fileId.pop_back();
  fileId.push_back("Sqlite_Test.db");
  databaseConnection userConn(fileId);
  string websiteHashId = websiteConn.getHashId();
  string userHashId = userConn.getHashId();

  cout<< websiteHashId << " == " << userHashId <<endl;
*/  
  return 0;
}
