#ifndef DATA_REQUEST_FORM_H
#define DATA_REQUEST_FORM_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files */
#include "Connection.h"
#include "ConnectionManager"


class DataRequestForm
{

protected:
	Connection conn;
	ConnectionManager connMgr;
	int* table;

public:
	bool getTable(string);

};














#endif
