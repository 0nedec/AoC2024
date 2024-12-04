#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

void getMulFromLine(string line){
	regex mulRegex("mul\\(\\d{1,3},\\d{1,3}\\)");
	smatch match;
	string::const_iterator start = line.begin();

	while (regex_search(start, line.cend(), match, mulRegex)){
		cout << "Match found: " << match.str() << endl;
		start = match.suffix().first;
	}
	return;
}

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
  getMulFromLine(line);

	}

  cout << "Hello BoilerPlate!" << endl;
  return 0;
}
