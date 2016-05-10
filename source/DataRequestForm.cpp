#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>
#include <vector>

// Included Header Files
#include "DataRequestForm.h"
#include "json/json.h"
//#include "jsoncpp.cpp"

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
Json :: Value DataRequestForm::getTable(string tableName)
{
	Json::Value tableContents;

	/* Columns from the database */
	vector <string> columns;
	vector <string> tableVector;
	string output;

	// DB Info: visitor_ip,visitor_username,date_of_visit      ,page_visited     ,date_left_page
	int tableColumns = 5;
	columns.push_back("visitor_ip");
	columns.push_back("visitor_username");
	columns.push_back("date_of_visit");
	columns.push_back("page_visited");
	columns.push_back("date_left_page");

  // if connection exists save table JSON string
  tableContents = connPtr->getJsonTable(tableName);

	for (int i = 0; i < tableColumns; i++)
	{
		output = tableContents[tableName][0][columns[i]].asString();
		tableVector.push_back(output);
	}
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
	//bool connectionDeleted = false;
	connMgr->deleteConnection(*connPtr);
	//cout << "DataRequestForm destructor exited" << endl;
}




/*
int main()
{
	DataRequestForm d1;
	string test = d1.getTable("visits");

	cout << test << endl;
}
*/


#endif
