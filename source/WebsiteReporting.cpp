/**
CS 441
WebsiteReporting.cpp
Purpose: To retrieve and manipulate website anaylitic data.

@author Sara Adra, Joshua Boone, Josiah Hayes, Alex Hoppe, Jordan Spinato
@version 1.0 3/31/16
*/

// Libraries
#include <string>
#include <iostream>

using namespace std;

/* Included Header Files */
#include "Model.h"
#include "Commandline_UI.h" // View and Controller

int main()
{
	Model          *model;
	Commandline_UI view;
	Commandline_UI controller;
	
	model      = Model::instance();

	int state  = 0;

	while (true)
	{
		string username;
		string password;
		string role;
		string tableName;
		string table = "";
		bool   success;

		switch (state)
		{
		// LogIn
		case 0: 
			view.displayLogIn();
			controller.submitLogIn(username, password);
			success = model->loadUser(username, password);

			if (success)
			{
				if (role == "IT")
					state = 2; // User Account Settings
				else
					state = 1; // Data Search Form
			}
			else
				view.displayErrorMsg("ERROR: Unable to log in.");

			break;
		// Data Search Form
		case 1 : 
			view.displaySearchForm();
			controller.submitSearchForm(tableName);
			table = model->getTable(tableName);

			// Search Results
			view.displayResults(table);

			break;
		// User Account Settings
		case 2 : 
			view.displayUserAccount();
			controller.createUser(username, password, role);
			success = model->createUser(username, password, role);

			if (success)
				view.displayErrorMsg("SUCCESS: User created successfully.");
			else
				view.displayErrorMsg("ERROR: Unable to create user.");
			
			break;
		}
	}

	return 0;
}
