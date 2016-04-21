#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

using namespace std;

class dataBaseConnection
{
  private:
    static int callback(void *NotUsed, int argc, char **argv, char **szColName);

  protected:
    

  public:
    void getTableContent();
};

#endif



//make database name not hard coded, pointer to object and then dereference when use sqlite function

