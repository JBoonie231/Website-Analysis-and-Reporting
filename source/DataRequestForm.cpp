#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "DataRequestForm.h"

using namespace std;

DataRequestForm::DataRequestForm() : conn(identifiersForConnMgr)
{
	connectionName = "User_Database.txt";

	connMgr = ConnectionManager::instance();
	identifiersForConnMgr.push_back(connectionName);
	connPtr = connMgr -> newConnection(identifiersForConnMgr);

}


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
string DataRequestForm :: getTable(string table)
{
  string tableContents;
  tableString = tableContents;

  // if connection exists save table JSON string
  tableContents = connPtr -> getTableContents(table);
  tableString = tableContents;

  return tableContents;

}


DataRequestForm :: ~DataRequestForm()
{
	bool connectionDeleted = false;
	connectionDeleted = connMgr->deleteConnection(conn);

}




#endif
