#ifndef MODEL_CPP
#define MODEL_CPP

// Libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Included Header Files
#include "Model.h"


/*
Function: Create User
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool createUser(userAccount newUser)
{
  cout << "Create User: " << newUser << endl;

return true;

} // end  createUser


/*
Function: Delete User
Input: User account to delete
Purpose: calls frunction delete user from userAccount class
*/
bool deleteUser(userAccount account)
{
  cout << "Delete User" << account << endl;

  return true;

} // end deleteUser


/*
Function: Load User
Input: Username and password to validate and load the user
Purpose: calls frunction  load user from userAccount class
*/
bool loadUser(string username, string password)
{
  cout << "Username: " << username << "\nPassword: " << password << endl;

  return true;

} // end loadUser


/*
Function: getTable
Input: table information to load
Purpose: calls frunction get table from the data request form class
*/
bool getTable (string table)
{


  return true;
}





#endif
