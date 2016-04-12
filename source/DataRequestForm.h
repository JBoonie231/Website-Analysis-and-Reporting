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

protected:
	Connection conn;
	ConnectionManager *connMgr;
	string table; // json string
  vector <string> identifiersForConnMgr;


public:
  DataRequestForm();
	string getTable(string tableName);
  ~DataRequestForm();

};














#endif
