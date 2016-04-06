#ifndef MODEL_H
#define MODEL_H

// Libraries
#include <iostream>
#include <string>

using namespace std;

/* Included Header Files */
#include "UserAccount.h"
#include "DataRequestForm.h"

/* Singleton Class
1- Define a private static attribute in the "single instance" class
2- Define a public static accessor function in the class
3- Do "lazy initialization" (creation on demand) in the accessor function
4- Define all constructors to be protected or private
5- Clients may only use the accessor function to manipulate the Singleton
6- Inheritance can be supported, but static functions may not be overridden.
The base class must be declared a friend of the derived class
(in order to access the protected constructor).
*/
 
class Model
{

private:
  // 1. Private Static attribute
  static Model *inst;

protected:
  UserAccount userAccount;
  DataRequestForm dataRequestForm;
  // 4. protected constructor
  Model();

public:
  bool createUser(string username, string password, int role);
  bool deleteUser(string username);
  bool loadUser(string username, string password);
  string getTable (string tableName);

  // 2. Public Static Accessor
  static Model *instance();

};





#endif
