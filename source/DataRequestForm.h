#ifndef DATA_REQUEST_FORM_H
#define DATA_REQUEST_FORM_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files */
#include "Connection.h"
#include "ConnectionManager.h"

class DataRequestForm
{

private:
	Connection *connPtr;
	//Connection conn;
	ConnectionManager *connMgr;
	string connectionName;
	string tableString; // json string
	vector <string> identifiersForConnMgr;


public:
  DataRequestForm();
  Json::Value getTable(string tableName);
  void setTableString(string tString);
  ~DataRequestForm();

};














#endif
