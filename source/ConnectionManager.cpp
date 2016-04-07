/**
CS 441
ConnectionManager.cpp
Purpose: Manage unique connections to database data.

@author Sara Adra, Joshua Boone, Josiah Hayes, Alex Hoppe, Jordan Spinato
@version 1.0 3/31/16
*/

// Libraries
#include <string>
#include <vector>

// Included Header Files
#include "ConnectionManager.h"


using namespace std;

//Input: list of strings
//Purpose:  creates a new connection between user and db
Connection ConnectionManager::newConnection(vector<string> identifiers)
{
	// Concatinate identifier values into one hash value
	string hashIdentifier = "";
	for (int i = 0; i < identifiers.size() ;i++)
	{
		hashIdentifier += identifiers.at(i);
	}

	// Search for connection
	for(int i = 0; i < identifiers.size() ;i++)
	{
		// If connection exists, return it
		if(identifiers.at(i) == hashIdentifier)
		{
			numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) + 1;
			return connections.at(i);
		}
	}

	// If connection wasn't found, create connection and connection values.
	connections.push_back(Connection temp_conn(identifiers));
	hashIdentifiers.push_back(hashIdentifier);
	numOfConnectionUsers.push_back(1);

	return connections.back();
}

//Input: deletes a connection
//Purpose: disconnects user from db
bool ConnectionManager::deleteConnection(Connection connection)
{
	// Search for connection
	for (int i = 0; i < connections.size(); i++)
	{
		if(connections.at(i).equals(connection))
		{
			// If the connection has more than one user, decrement the number of users
			if(numOfConnectionUsers.at(i) > 1)
			{
				numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) - 1;
			}
			// Otherwise delete the connection and its values.
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
