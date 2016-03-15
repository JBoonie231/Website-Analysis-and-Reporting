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
	string passowrd;
	enum role : int;
	Connection conn;
	ConnectionManager connMgr;


public:
	bool createUser(userName, passowrd, role);
	bool deleteUser(userName);
	bool loadUser(userName, passowrd, &role);
};














#endif