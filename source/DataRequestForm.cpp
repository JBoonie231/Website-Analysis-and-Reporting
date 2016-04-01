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

}


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool DataRequestForm :: getTable(string table)
{
  string contents;
  bool connectionState = false;

  // Access Singleton for Connection Manager
  conn = ConnectionManager::instance() -> newConnection(identifiersForConnMgr);

  // if connection exists save table JSON string
  contents = conn.getTableContents(table);
  table = contents;
  connectionState = true;

	return connectionState;

}


DataRequestForm :: ~DataRequestForm()
{
  ConnectionManager::instance() -> deleteConnection(conn);
}




#endif
