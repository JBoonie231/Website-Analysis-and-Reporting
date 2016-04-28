/**
 CS 441
 ConnectionManager.cpp
 Purpose: Manage unique connections to database data.
 
 @author Sara Adra, Joshua Boone, Josiah Hayes, Alex Hoppe, Jordan Spinato
 @version 1.0 3/31/16
 */

// Libraries
#include <string>
#include <vector>
#include <iostream>

// Included Header Files
#include "ConnectionManager.h"
#include "textFileConnection.h"

using namespace std;

ConnectionManager *ConnectionManager::s_instance = 0;

ConnectionManager::ConnectionManager()
{}




string ConnectionManager::getFileExt(vector<string> identifiers)
{
    string fileName = identifiers[0];
    int lastChar = fileName.length()-3;
    string fileExt = "";

    for(int i=0; i<3; i++)
    {
        fileExt += fileName[lastChar];
        lastChar = lastChar+1;
    }
    return fileExt;
}


//Input: list of strings
//Purpose:  creates a new connection between user and db
Connection * ConnectionManager::newConnection(vector<string> identifiers)
{
    //cout << "newConnection called" << endl;
    // Concatinate identifier values into one hash value
    string hashIdentifier = "";
    for (int i = 0; i < identifiers.size() ;i++)
    {
        hashIdentifier += identifiers.at(i);
    }
    //cout << "hashIdentifier = " << hashIdentifier << endl;
    // Search for connection
    for(int i = 0; i < hashIdentifiers.size() ;i++)
    {
        // If connection exists, return it
        if(hashIdentifiers.at(i) == hashIdentifier)
        {
            numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) + 1;
            return connections.at(i);
        }
    }
    
    // If connection wasn't found, create connection and connection values.
    //cout << "temp_conn about to be allocated" << endl;

    string fileExt = getFileExt(identifiers);
    
    Connection *temp_conn;
    if (fileExt == "txt")
    {
        temp_conn = new textFileConnection(identifiers);
    }
    /*else if (fileExt == ".db")
    {
        Connection *temp_conn = (Connection*)new databaseConnection(identifiers);
    }*/
    
    //cout << "temp_conn allocated" << endl;
    //cout << "connections.size =" << connections.size() << endl;
    connections.push_back(temp_conn);
    //cout << "temp_conn pushed into list" << endl;
    hashIdentifiers.push_back(hashIdentifier);
    numOfConnectionUsers.push_back(1);
    //cout << "newConnection exited" << endl;
    return connections.back();
}

//Input: deletes a connection
//Purpose: disconnects user from db
bool ConnectionManager::deleteConnection(Connection& connection)
{
    // Search for connection
    for (int i = 0; i < connections.size(); i++)
    {
        if((*connections.at(i)).getHashId() == connection.getHashId())
        {
            // If the connection has more than one user, decrement the number of users
            if(numOfConnectionUsers.at(i) > 1)
            {
                numOfConnectionUsers.at(i) = numOfConnectionUsers.at(i) - 1;
            }
            // Otherwise delete the connection and its values.
            else
            {
                connections.erase(connections.begin() + i);
                hashIdentifiers.erase(hashIdentifiers.begin() + i);
                numOfConnectionUsers.erase(numOfConnectionUsers.begin() + i);
            }
            return true;
        }
    }
    return false;
}

ConnectionManager *ConnectionManager::instance()
{
    if (!s_instance)
    {
        s_instance = new ConnectionManager();
    }
    return s_instance;
}
