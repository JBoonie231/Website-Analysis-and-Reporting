#ifndef USER_ACCOUNT_CPP
#define USER_ACCOUNT_CPP

//******To Compile on Linux must do : 
// must include model.cpp and commandline.cpp in the WEbsite reporting
// add ConnectionManager * ConnectionManager :: s_instance = 0; to ConnectionManager.cpp
// add default constructor in ConnectionManager.cpp

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "UserAccount.h"

using namespace std;


// confused why its on the same line but it prevented an error
UserAccount::UserAccount()//: role(), connPtr(NULL), conn(identifierForConnection), connMgr(NULL)
{
	//cout << "UserAccount called" << endl;
	connMgr = ConnectionManager::instance();
	tableName = "users";
	connectionName = "User_Database.txt"; //"C:\\Users\\Joshua Boone\\Documents\\GitHub\\Website - Analysis - and - Reporting\\source\\User_Database.txt";
	identifierForConnection.push_back(connectionName);
	connPtr = connMgr->newConnection(identifierForConnection);
	//cout << "UserAccount exited" << endl;
}


//loads user information via the connection class
string UserAccount :: loadUser(string uname, string pwd)
{
	string tableName = "USERS";
	//string connectionName;
	string tableContents;

	//tableContents = "You're logged in!";
	tableContents = connPtr->getTableContents(tableName);
	//cout << "tableContents = " << tableContents << endl;
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
	//cout << "UserAccount destructor called" << endl;
	bool connectionDeleted = false;
	connectionDeleted = connMgr->deleteConnection(*connPtr);
	//cout << "UserAccount destructor  exited" << endl;
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
