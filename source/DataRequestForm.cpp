#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "DataRequestForm.h"

using namespace std;


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool getTable(string table)
{
  string[][] contents;

    // if connection exists return table
  if () 

  // connection doesnt exist.. create new connection
  else {
    connMgr.newConnection(conn);
    contents = conn.getTableContents(table);
    table = &contents; // point to address of the contents table
  }


  // delete connection 
  connMgr.deleteConnection(conn);


	return true;

}




#endif
