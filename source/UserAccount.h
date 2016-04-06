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
	Connection conn;
	ConnectionManager connMgr;


public:
	UserAccount();
	bool createUser(string uname, string pwd, int rol);
	bool deleteUser(string);
	string loadUser(string uname, string pwd);
};














#endif
