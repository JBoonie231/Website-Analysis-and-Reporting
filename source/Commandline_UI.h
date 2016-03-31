// Libraries
#include <string>

using namespace std;

/* Included Header Files */
#include "View.h"
#include "Controller.h"

class Commandline_UI: public Controller, public View
{
public:
	void displayLogIn();
	void displaySearchForm();
	void displayResults(string table); // string argument must be a JSON string
	void displayUserAccount();
	void displayErrorMsg(string msg);

	void submitLogIn(string &username, string &password);
	void submitSearchForm(string &table);
	void createUser(string &username, string &password, string &role);
};
