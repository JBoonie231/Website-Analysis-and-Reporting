// Libraries
#include <string>

using namespace std;

class View
{
public:
	View();
	virtual void displayLogIn()             = 0;
	virtual void displaySearchForm()        = 0;
	virtual void displayResults(string[][]) = 0;
	virtual void displayUserAccount()       = 0;
	virtual void displayErrorMsg(string)    = 0;
	~View;
};
