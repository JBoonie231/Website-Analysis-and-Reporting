#ifndef USER_ACCOUNT_H
#define USER_ACCOUNT_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files */
#include "Connection.h"
#include "ConnectionManager.h"


class UserAccount
{

protected:
	string userName;
	string password;
	enum userRole {ADMIN, GENERAL, ACCOUNTANT, ENGINEER, MARKETING, NONE};
	userRole role;
	string tableName;
	string connectionName;
	Connection *connPtr;
	//Connection conn;
	ConnectionManager *connMgr;
	vector<string> identifierForConnection;


public:
	UserAccount();
	~UserAccount();
	bool createUser(string uname, string pwd, string rol);
	bool deleteUser(string uname);
	string loadUser(string uname, string pwd);
};














#endif
