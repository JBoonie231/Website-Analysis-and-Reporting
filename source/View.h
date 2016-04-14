// Libraries
#include <string>

using namespace std;

class View
{
public:
	virtual void displayLogIn()          = 0;
	virtual void displaySearchForm()     = 0;
	virtual void displayResults(string)  = 0; // string argument must be a JSON string
	virtual void displayUserAccount()    = 0;
	virtual void displayErrorMsg(string) = 0;
};
