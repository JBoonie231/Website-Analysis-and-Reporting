#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

// Libraries
#include <iostream>
#include <string>
#include <map>

// Included Header Files
#include "UserAccount.h"

using namespace std;





//loads user information via the connection class
string UserAccount :: loadUser(string uname, string pwd)
{
	string tableName;
	tableName = "user";

	map<string,string> fieldValuePairs;
	fieldValuePairs["userName"] = uname;
	fieldValuePairs["password"] = pwd;

	string userRow[2];

	//query database for user role where userName and password exist

	/* leave out until the function is created
	role = conn.getTableRow(tableName, fieldValuePairs);

	*/
	string account = uname + " " + pwd;
	return account;
}


//creates user with parameters via the connection class
bool UserAccount :: createUser(string uname, string pwd, int rol)
{
	string tableName;
	bool userRow = false;
	tableName = "user";

	/* Assign parameters to UserAccount attributes */
	userName = uname;
	password = pwd;

	switch (rol)
	{
	case 0:
		role = ADMIN;
		break;
	case 1: 
		role = GENERAL;
		break;
	case 2: 
		role = ACCOUNTANT;
		break;
	case 3:
		role = ENGINEER;
		break;
	case 4:
		role = MARKETING;
		break;
	default:
		role = NONE;
		break;
	}


	map<string,string> fieldValuePairs;
	fieldValuePairs["userName"] = uname;
	fieldValuePairs["password"] = pwd;
	fieldValuePairs["role"] = rol;
	
	/* keep out until new function is created
	userRow = conn.insertRow(userName, fieldValuePair);
	*/
	if (userRow) 
		return true;
	else 
		return false;
	
}

//deletes user from the reporting database via the connection class
bool UserAccount ::deleteUser(string uname)
{
	bool userRow = false;
	string tableName; 
	tableName = "user";

	/*
	 leave out until new function is created 
	userRow = conn.deleteRow(tableName, userName);
	*/

	if (userRow) 
		return true;
	else 
		return false;
	
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
