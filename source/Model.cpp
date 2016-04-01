#ifndef MODEL_CPP
#define MODEL_CPP

// Libraries
#include <iostream>
#include <string>

using namespace std;

// Included Header Files
#include "Model.h"

Model::Model()
{

}

Model* Model::inst = 0;

// initialize the instance for singleton
Model *Model::instance()
{
  if (inst = 0)
    inst = new Model();
  return inst;

}


/*
Function: Create User
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool Model :: createUser(string userName, string password, enum role)
{
  bool createUserSuccessful = false;

  createUserSuccessful = userAccount.createUser(userName, password, role);
  
  return createUserSuccessful;

} // end  createUser


/*
Function: Delete User
Input: User account to delete
Purpose: calls frunction delete user from userAccount class
*/
bool Model:: deleteUser(string userName)
{

  userAccount.deleteUser(userName);// send to user account class

  return true;

} // end deleteUser


/*
Function: Load User
Input: Username and password to validate and load the user
Purpose: calls frunction  load user from userAccount class
*/
bool Model :: loadUser(string username, string password)
{

  userAccount.loadUser(username, password);

  return true;

} // end loadUser


/*
Function: getTable
Input: table information to load
Purpose: calls frunction get table from the data request form class
*/
string Model :: getTable (string table)
{
  string returnedTable = " ";

  returnedTable = dataRequestForm.getTable(table);

  return returnedTable;
}





#endif
