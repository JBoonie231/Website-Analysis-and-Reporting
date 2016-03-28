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
  UserAccount userAccount;
  DataRequestForm dataRequestForm;

public:
  Model();
  bool createUser(userAccount);
  bool deleteUser(userAccount);
  bool loadUser(string, string,enum);
  string getTable (string);

};





#endif
