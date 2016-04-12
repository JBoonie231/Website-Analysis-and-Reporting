#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

// Libraries
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Included Header Files */
#include "Connection.h"


class ConnectionManager
{
	static ConnectionManager *s_instance;

	vector<Connection> connections;          // List of all connections
	vector<string>     hashIdentifiers;      // List of each connection's identifier
	vector<int>        numOfConnectionUsers; // List of each connection's number of users

	ConnectionManager();

public:
	Connection * newConnection(vector<string> identifiers); //
	bool deleteConnection(Connection& connection);
	static ConnectionManager *instance()
	{
		if (!s_instance)
		{
			s_instance = new ConnectionManager;
		}
		return s_instance;
	}
};
#endif
