#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "UserAccount.h"

using namespace std;


// confused why its on the same line but it prevented an error
UserAccount :: UserAccount(): role(), connPtr(nullptr), conn(identifierForConnection), connMgr(nullptr)
{
	tableName = "users";
	connectionName = "User_Database.txt";
	identifierForConnection.push_back(connectionName);
	connPtr = connMgr->newConnection(identifierForConnection);

}


//loads user information via the connection class
string UserAccount :: loadUser(string uname, string pwd)
{
	string tableName;
	string connectionName;
	string tableContents = "EMPTY";

	tableContents = connPtr->getTableContents(tableName);

	return tableContents;	
}


//creates user with parameters via the connection class
bool UserAccount :: createUser(string uname, string pwd, string rol)
{
	string tableName;
	bool userRow = false;


	/* Assign parameters to UserAccount attributes */
	userName = uname;
	password = pwd;

	if (rol == "IT")
	{
		role = ADMIN;
		userRow = true;
	}
	else if (rol == "GENERAL")
	{
		role = GENERAL;
		userRow = true;
	}

	else if (rol == "ACCOUNTANT")
	{
		role = ACCOUNTANT;
		userRow = true;
	}
	
	else if (rol == "MARKETING")
	{
		role = MARKETING;
		userRow = true;
	}

	else
		role = NONE; 

	return userRow;	
}

//deletes user from the reporting database via the connection class
bool UserAccount ::deleteUser(string uname)
{
	bool userRow = false;
	
	/*
	 leave out until new function is created 
	userRow = conn.deleteRow(tableName, userName);
	*/

	return userRow;
	
}

UserAccount::~UserAccount()
{
	bool connectionDeleted = false;

	connectionDeleted = connMgr->deleteConnection(conn);

}





/*
//Testing Area
int main()
{
	string userName = "root";
	string password = "pass";
	int role = ADMIN;

	//createUser(userName, password, role);
	loadUser(userName, password);
	//deleteUser(userName);
}

*/



#endif
