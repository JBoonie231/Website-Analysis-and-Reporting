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
	//cout << "Model called" << endl;
	userAccount = new UserAccount();
	dataRequestForm = new DataRequestForm();
	//cout << "Model exited" << endl;
}

Model* Model::inst = 0;

// initialize the instance for singleton
Model *Model::instance()
{
  //cout << "Model::instance called" << endl;
  if (!inst)
  {
    //cout << "Model::instance being set" << endl;
    inst = new Model();
  }
  //cout << "Model::instance exited" << endl;
  return inst;

}


/*
Function: Create User
Input: User information to create an account
Purpose: calls frunction create user from userAccount class
*/
bool Model :: createUser(string userName, string password, string &role)
{
  bool createUserSuccessful = false;

  createUserSuccessful = userAccount->createUser(userName, password, role);
  
  return createUserSuccessful;

} // end  createUser


/*
Function: Delete User
Input: User account to delete
Purpose: calls frunction delete user from userAccount class
*/
bool Model:: deleteUser(string userName)
{
  bool deleteUserSuccessful = false;

  deleteUserSuccessful = userAccount->deleteUser(userName);// send to user account class

  return deleteUserSuccessful;

} // end deleteUser


/*
Function: Load User
Input: Username and password to validate and load the user
Purpose: calls frunction  load user from userAccount class
*/
bool Model :: loadUser(string username, string password)
{
  string userInformation = "" ;
  bool loadUserSuccessful = false;

  userInformation = userAccount->loadUser(username, password);
  if (userInformation != "")
    loadUserSuccessful = true;

  return loadUserSuccessful;

} // end loadUser


/*
Function: getTable
Input: table information to load
Purpose: calls frunction get table from the data request form class
*/
string Model :: getTable (string table)
{
  string returnedTable = "";

  returnedTable = dataRequestForm->getTable(table);

  return returnedTable;
}





#endif
