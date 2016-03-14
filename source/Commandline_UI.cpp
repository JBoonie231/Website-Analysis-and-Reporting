// Libraries
#include <string>
#include <iostream>
#include <array>

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

void Commandline_UI::displayResults(string[][] table)
{
	for (int x = 0; x < table.size(); x++)
	{
		for (int y = 0; y < table[x].size(); y++)
		{
			if (y != 0) { cout << " | "; }
			cout << table[x][y];
		}
		cout << endl;
	}
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
