// Libraries
#include <string>
#include <vector>
#include <iostream>

// Included Header Files
#include "ConnectionManager.h"
#include "Connection.h"
#include "textFileConnection.h"
#include "databaseConnection.h"

using namespace std;

ConnectionManager* ConnectionManager::s_instance = 0;

ConnectionManager::ConnectionManager(){}


string ConnectionManager::getFileExtension(vector<string> identifiers)
{
    string fileName = identifiers[0];
    int lastChar = fileName.length()-3;
    string fileExt = "";

    for(int i=0; i<3; i++)
    {
        fileExt += fileName[lastChar];
        lastChar = lastChar+1;
    }
    return fileExt;
}


Connection* ConnectionManager::newConnection(vector<string> identifiers)
{
  string hashIdentifier = "";
  for (int i = 0; i < identifiers.size() ;i++)
  {
    hashIdentifier += identifiers.at(i);
  }
  for(int i = 0; i < hashIdentifiers.size() ;i++)
  {
    if(hashIdentifiers.at(i) == hashIdentifier)
    {
      numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) + 1;
      return connections.at(i);
    }
  }

  string fileExt = getFileExtension(identifiers);
    
  Connection* temp_conn;

  if (fileExt == "txt")
  {
    temp_conn = new textFileConnection(identifiers);
  }
  else if (fileExt == ".db")
  {
    temp_conn = new databaseConnection(identifiers);
  }

  connections.push_back(temp_conn);    
  hashIdentifiers.push_back(hashIdentifier);
  numOfConnectionUsers.push_back(1);
  return connections.back();
}


bool ConnectionManager::deleteConnection(Connection& connection)
{
  for (int i = 0; i < connections.size(); i++)
  {
    if((*connections.at(i)).getHashId() == connection.getHashId())
    {
      if(numOfConnectionUsers.at(i) > 1)
      {
        numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) - 1;
      }
      else
      {
        connections.erase(connections.begin() + i);
        hashIdentifiers.erase(hashIdentifiers.begin() + i);
        numOfConnectionUsers.erase(numOfConnectionUsers.begin() + i);
      }
      return true;
    }
  }
  return false;
}


ConnectionManager* ConnectionManager::instance()
{
  if (!s_instance)
  {
    s_instance = new ConnectionManager();
  }
  return s_instance;
}
