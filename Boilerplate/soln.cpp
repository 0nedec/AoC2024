#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
  if (argc != 2){
    cerr << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }
  string filename = argv[1];
  ifstream file(filename);
  string line;

  if (!file.is_open()){
    cerr << "Error opening file: " << filename << endl;
    return 1;
  }

  while(getline(file, line)){
  //do something
  }

  cout << "Hello BoilerPlate!" << endl;
  return 0;
}
