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
bool createUser(UserAccount newUser)
{
  cout << "Create User: " << newUser << endl;

  newUser.createUser(newUser);


return true;

} // end  createUser


/*
Function: Delete User
Input: User account to delete
Purpose: calls frunction delete user from userAccount class
*/
bool deleteUser(UserAccount account)
{

  cout << "Delete User" << account << endl;

  userAccount.deleteUser(account);// send to user account class

  return true;

} // end deleteUser


/*
Function: Load User
Input: Username and password to validate and load the user
Purpose: calls frunction  load user from userAccount class
*/
bool loadUser(string username, string password, int role)
{

  cout << "Username: " << username << "\nPassword: " << password << endl;
  userAccount.loadUser(username, password, &role);

  return true;

} // end loadUser


/*
Function: getTable
Input: table information to load
Purpose: calls frunction get table from the data request form class
*/
bool getTable (string table)
{
  dataRequestForm.getTable(table);

  return true;
}





#endif
