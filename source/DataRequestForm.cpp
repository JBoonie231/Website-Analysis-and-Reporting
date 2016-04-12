#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "DataRequestForm.h"

using namespace std;

DataRequestForm::DataRequestForm()
{
	connMgr = ConnectionManager::instance();
	conn = connMgr -> newConnection(identifiersForConnMgr);
	// Access Singleton for Connection Manager

}


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
string DataRequestForm :: getTable(string table)
{
  string tableContents;
  bool connectionState = false;

  // if connection exists save table JSON string
  tableContents = conn.getTableContents(table);

	return tableContents;

}


DataRequestForm :: ~DataRequestForm()
{
  ConnectionManager::instance() -> deleteConnection(conn);
}




#endif
