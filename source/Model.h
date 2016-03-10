#ifndef MODEL_H
#define MODEL_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files */
#include "UserAccount.h"
#include "DataRequestForm.h"

class Model
{

protected:
  userAccount userAccount;
  dataRequestForm dataRequestForm;

public:
  Model();
  bool createUser(userAccount);
  bool deleteUser(userAccount);
  bool loadUser(string, string);
  string getTable (string);

};





#endif
