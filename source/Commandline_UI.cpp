/**
	CS 441
	CommandLine_UI.cpp
	Purpose: To use the command line console as a user input and user output interface.

	@author Sara Adra, Joshua Boone, Josiah Hayes, Alex Hoppe, Jordan Spinato
	@version 1.0 3/31/16
*/

// Libraries
#include <string>
#include <iostream>

using namespace std;

/* Included Header Files */
#include "Commandline_UI.h"

void Commandline_UI::displayLogIn()
{
	cout << "Please enter a username and password." << endl;
	return;
}

void Commandline_UI::displaySearchForm()
{
	cout << "Please enter a table name." << endl;
	return;
}

/**
	Displays the results to the screen

	@param table - A JSON string representing the results.

	JSON string format:

	{
	   "table_name":
	     [
	       {
	         "col_1_header": "row_1_col_1_value",
	         "col_2_header": "row_1_col_2_value",
	         "col_3_header": "row_1_col_3_value",
	         ...,
	         "con_N_header": "row_1_col_N_value"
	       },
	       {
	         "col_1_header": "row_2_col_1_value",
	         "col_2_header": "row_2_col_2_value",
	         "col_3_header": "row_2_col_3_value",
	         ...,
	         "con_N_header": "row_2_col_N_value"
	       },
	       {
	         ...
	       },
	       {
	         "col_1_header": "row_N_col_1_value",
	         "col_2_header": "row_N_col_2_value",
	         "col_3_header": "row_N_col_3_value",
	         ...,
	         "con_N_header": "row_N_col_N_value"
	       }
	     ]
	 }
*/
void Commandline_UI::displayResults(string table)
{
	/*for (int x = 0; x < table.size(); x++)
	{
		for (int y = 0; y < table[x].size(); y++)
		{
			if (y != 0) { cout << " | "; }
			cout << table[x][y];
		}
		cout << endl;
	}*/
	cout << table << endl;
	return;
}

void Commandline_UI::displayUserAccount()
{
	cout << "Please enter a new username, password, and role." << endl;
	return;
}

void Commandline_UI::displayErrorMsg(string msg)
{
	cout << msg << endl;
	return;
}

void Commandline_UI::submitLogIn(string &username, string &password)
{
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	return;
}

void Commandline_UI::submitSearchForm(string &table)
{
	cout << "Table name : ";
	cin >> table;
	return;
}

void Commandline_UI::createUser(string &username, string &password, string &role)
{
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> password;
	cout << "Role : ";
	cin >> role;
	return;
}
