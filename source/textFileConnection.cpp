using namespace std;



bool textFileConnnect()
{
  textConnect = databaseFile.open(identifiers[0]);//file access
  if (textConnect) return true;
  else return false;
}
