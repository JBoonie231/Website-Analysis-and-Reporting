// Libraries
#include <string>

using namespace std;

class Controller
{
public:
	virtual void submitLogIn(string &username, string &password)              = 0;
	virtual void submitSearchForm(string &table)                              = 0;
	virtual void createUser(string &username, string &password, string &role) = 0;
};
