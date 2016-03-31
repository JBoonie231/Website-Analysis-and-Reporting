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
protected:
	vector<Connection> connections;          // List of all connections
	vector<string>     hashIdentifiers;      //
	vector<int>        numOfConnectionUsers; //

public:
	newConnection(vector<Connection> &connections); //
	deleteConnection(Connection connection);
};
#endif
