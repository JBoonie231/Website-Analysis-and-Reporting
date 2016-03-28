#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

// Libraries
#include <iostream>
#include <string>
#include <map>

// Included Header Files
#include "userAccount.h"

using namespace std;

enum roles{ADMIN, GENERAL, ACCOUNT, ENGINEER, MARKETING};

//call connection manager which creates new connection instance on initialization
connectionManager connMgr();


//loads user information via the connection class
bool loadUser(userName, password);
{
	tableName = "user";

	map<string,string> fieldValuePairs;
	fieldValuePairs["userName"] = userName;
	fieldValuePairs["password"] = password;

	string userRow[2];

	//query database for user role where userName and password exist
	role = conn.selectRow(tableName, fieldValuePairs);
	if (userRow) return true;
	else return false;
}

//creates user with parameters via the connection class
bool createUser(userName, password, role);
{
	tableName = "user";

	map<string,string> fieldValuePairs;
	fieldValuePairs["userName"] = userName;
	fieldValuePairs["password"] = password;
	fieldValuePairs["role"] = role;

	userRow = conn.insertRow(userName, fieldValuePair);
	if (userRow) return true;
	else return false;
}

//deletes user from the reporting database via the connection class
bool deleteUser(userName);
{
	tableName = "user";

	userRow = conn.deleteRow(tableName, userName);
	if (userRow) return true;
	else return false;
}

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

#endif
