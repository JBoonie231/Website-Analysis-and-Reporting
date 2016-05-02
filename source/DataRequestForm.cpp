#ifndef DATA_REQUEST_FORM_CPP
#define DATA_REQUEST_FORM_CPP

// Libraries
#include <iostream>
#include <string>
#include <vector>

// Included Header Files
#include "DataRequestForm.h"
#include "json/json.h"
#include "jsoncpp.cpp"

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
	string returnedValue;
	vector<string> tableVector;

  // if connection exists save table JSON string
  //tableContents = "Here's your table contents!";
  tableContents = connPtr->getTableContents(tableName);

	Json::Value root; // root value after parsing
	Json::Reader reader;
	bool parsingSuccessful = reader.parse("Website_Database.txt", root,true);
	if (!parsingSuccessful)
	{
		cout << "Failed to parse the configuration" << endl;
		return "INVALID";
	}
	// DB Info: visitor_ip,visitor_username,date_of_visit      ,page_visited     ,date_left_page
	cout << "Success1" << endl;

while(reader.parse(connectionName,root,true))
{
	cout << "Success2" << endl;
// get value of the member of root named encoding and return ERROR if there is no such member
	string visitorIP       = root.get("visitor_ip", "Invalid_IP").asString();
	string visitorUserName = root.get("visitor_username", "Invalid_Username").asString();
	string dateOfVisit     = root.get("date_of_visit", "Invalid_Date_Visit").asString();
	string pageVisited     = root.get("page_visited", "Invalid_Page_Visit").asString();
	string dateLeftPage    = root.get("date_left_page", "Invalid_Date_Left").asString();

	tableVector.push_back(visitorIP);
	tableVector.push_back(visitorUserName);
	tableVector.push_back(dateOfVisit);
	tableVector.push_back(pageVisited);
	tableVector.push_back(dateLeftPage);
	tableVector.push_back("\n");

	returnedValue = visitorIP + " " + visitorUserName + " " + dateOfVisit + " " + pageVisited + " " + dateLeftPage + "\n";
}
  //setTableString(tableContents);

  return returnedValue;
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





int main()
{
	DataRequestForm d1;
	string test = d1.getTable("visits");

	cout << test << endl;



}


#endif
