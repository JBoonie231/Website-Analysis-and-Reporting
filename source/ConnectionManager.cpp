// Libraries
#include <iostream>
#include <string>
#include <vector>

// Included Header Files
#include "ConnectionManager.h"

using namespace std;

//Input: list of strings
//Purpose:  creates a new connection between user and db
bool newConnection(vector<string> identifiers)
{
	string hashIdentifier = "";
	for (int i = 0; i<identifiers.size() ;i++)
		{
			hashIdentifier += identifiers.at(i);
		}

 for(int i = 0; i<hashIdentifiers.size() ;i++)
 	{
		if(hashIdentifiers.at(i) == hashIdentifier )
		{
			numOfConnectionUsers.at(i)=numOfConnectionUsers.at(i)+1 ;
			return connections.at(i);
		}
	}
	connections.push_back(new Connection(identifiers));
	hashIdentifiers.push_back(hashIdentifiers);
	numOfConnectionUsers.push_back(1);
	}
	return true;
}

//Input: deletes a connection
//Purpose: disconnects user from db
bool deleteConnection(connection)
{
	for (int i = 0; i<connections.size(); i++)
	{
		if(connections.at(i) == connection)
		{
			if(numOfConnectionUsers.i > 1)
			{
				numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) - 1;
				return true;
			}
			else
			{
				connections.erase(i);
				hashIdentifiers.erase(i);
				numOfConnectionUsers.erase(i);
				return true;
			}
		}
	}
		return false;
}
