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


	string checkUsername = "username to check";
	string checkPassword = "password to check";
	string tableName = "USERS";
	string tableContents = "table of contents";

	//tableContents = "You're logged in!";
	tableContents = connPtr->getTableContents(tableName);
	
	/* parse table contents to get checkUsername and checkPassword*/
	
	if (uname == checkUsername)
	{
		cout << "username correct" << endl;

		if (pwd == checkPassword)
		{
			cout << "password check correct" << endl;
			cout << "user is valid" << endl;
			return tableContents;
		}
	}

	tableContents = "ERROR. User not found";
	cout << "User not found" << endl;
	return tableContents;

	//cout << "tableContents = " << tableContents << endl;
}


//creates user with parameters via the connection class
bool UserAccount :: createUser(string uname, string pwd, string rol)
{
	string tableName;
	bool createNewUser = false;
	string usernameCheck = "parsedUserName";
	string passwordCheck = "parsedPassword";

	// parse myself or use the parser.. TBD
	if (uname == usernameCheck)
	{
		cout << "Username already exists" << endl;

		if (pwd == passwordCheck)
		{
			cout << "Username and password are a match" << endl;
			cout << "Account already exists" << endl;
		}	
		cout << "password was not correct" << endl;
	}

	else
	{
		/* Assign parameters to UserAccount attributes */
		userName = uname;
		password = pwd;

		if (rol == "IT")
			role = ADMIN;
		else if (rol == "GENERAL")
			role = GENERAL;
		else if (rol == "ACCOUNTANT")
			role = ACCOUNTANT;
		else if (rol == "MARKETING")
			role = MARKETING;
		else
			role = NONE;
	
		createNewUser = true;
	}

	return createNewUser;	
}

//deletes user from the reporting database via the connection class
bool UserAccount ::deleteUser(string uname)
{
	bool userDeleted = false;
	string userToDelete = "deleteUser";

	if (uname == userToDelete)
	{
		cout << "Delete this user" << endl;
		userDeleted = true;
	}
	else
	{
		cout << "user does not exist" << endl;
		userDeleted = false;

	}
	
	/*
	 leave out until new function is created 
	userRow = conn.deleteRow(tableName, userName);
	*/

	return userDeleted;
	
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
