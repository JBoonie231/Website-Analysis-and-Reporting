#ifndef MODEL_H
#define MODEL_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files

#include "userAccount.h"
#include "dataRequestForm.h"

*/


class model
{

protected:
  userAccount userAccount;
  dataRequestForm dataRequestForm;

public:
  bool createUser(userAccount);
  bool deleteUser(userAccount);
  bool loadUser(string, string);
  bool getTable (string);

};





#endif
