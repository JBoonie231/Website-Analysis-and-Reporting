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
  Connection conn;
  ConnectionManager connMgr;
  
}


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool DataRequestForm :: getTable(string table)
{
  // change to json string
  string contents;
  bool connectionState = false;

    // if connection exists save table pointer
    connMgr.newConnection(table);
    contents = connection.getTableContents(table);
    table = &contents;
    connectionState = true;

	return connectionState;

}


DataRequestForm :: ~DataRequestForm()
{
  connMgr.deleteConnection(conn);


}




#endif
