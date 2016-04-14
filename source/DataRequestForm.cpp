#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>

// Included Header Files
#include "DataRequestForm.h"

using namespace std;

DataRequestForm::DataRequestForm() //: conn(identifiersForConnMgr)
{
	//cout << "DataRequestForm called" << endl;
	connectionName = "Website_Database.txt"; //"C:\\Users\\Joshua Boone\\Documents\\GitHub\\Website - Analysis - and - Reporting\\source\\Website_Database.txt";

	connMgr = ConnectionManager::instance();
	identifiersForConnMgr.push_back(connectionName);
	connPtr = connMgr->newConnection(identifiersForConnMgr);
	//cout << "DataRequestForm exited" << endl;
}


/*
Function: Get Table
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
string DataRequestForm::getTable(string tableName)
{
  string tableContents;

  // if connection exists save table JSON string
  //tableContents = "Here's your table contents!";
  tableContents = connPtr->getTableContents(tableName);
  //setTableString(tableContents);

  return tableContents;

}
/*
void DataRequestForm::setTableString(string tString)
{
	tableString = tString;
}
*/

DataRequestForm :: ~DataRequestForm()
{
	//cout << "DataRequestForm destructor called" << endl;
	bool connectionDeleted = false;
	connectionDeleted = connMgr->deleteConnection(*connPtr);
	//cout << "DataRequestForm destructor exited" << endl;
}




#endif
