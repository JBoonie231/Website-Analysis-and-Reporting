// Libraries
#include <string>

using namespace std;

/* Included Header Files */
#include "Model.h"
#include "Commandline_UI.h" // View and Controller

main()
{
	Model      model;
	View       view;
	Controller controller;

	model      = new Model();
	view       = new CommandLine_UI();
	controller = view;
	
	int state  = 0;

	while (true)
	{
		switch (state)
		{
		// LogIn
		case 0: 
			string username;
			string password;
			string role;
			bool   success;

			view.displayLogIn();
			controller.submitLogIn(username, password);
			success = model.loadUser(username, password, role);

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
			string     tableName;
			string[][] table;

			view.displaySearchForm();
			controller.submitSearchForm(tableName);
			table = model.getTable(tableName);

			// Search Results
			view.displayResults(table);

			break;
		// User Account Settings
		case 2 : 
			string username;
			string password;
			string role;
			bool   success;

			view.displayUserAccount();
			controller.createUser(username, password, role);
			success = model.createUser(username, password, role);

			if (success)
				view.displayErrorMsg("SUCCESS: User created successfully.");
			else
				view.displayErrorMsg("ERROR: Unable to create user.");
			
			break;
		}
	}

	return 0;
}
