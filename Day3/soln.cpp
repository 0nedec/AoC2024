#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <regex>

using namespace std;

void printVector(vector<string> printable){
	for (const string& item : printable) {
		cout << item << endl;
	}
	return;
}


void getMulFromLine(string line, vector<string>& muls){
	regex mulRegex("mul\\(\\d{1,3},\\d{1,3}\\)");
	smatch match;
	string::const_iterator start = line.begin();
	
	while (regex_search(start, line.cend(), match, mulRegex)){
		//cout << "Match found: " << match.str() << endl;
		muls.push_back(match.str());
		start = match.suffix().first;
	}
	//printVector(muls);
	return;
}

int parseAndMultiplyMuls(vector<string> muls) {
	int sum = 0;
	for (int ii=0; ii < muls.size();++ii) {
		cout <<  muls[ii] << endl;
		size_t start = muls[ii].find('(');
		size_t comma = muls[ii].find(',');
		size_t end = muls[ii].find(')');

		if(start != string::npos && comma != string::npos && end != string::npos){
		int num1 = stoi(muls[ii].substr(start+1, comma - start -1));
		int num2 = stoi(muls[ii].substr(comma+1, end - comma -1));
		cout << " Adding "<< num1 << " and " << num2 << endl;
			sum += num1*num2;
		}
	}
	return sum;
}

int main(int argc, char *argv[]){
	string filename = argv[1];
  ifstream file(filename);
  string line;
	vector<string> muls;

	if (argc != 2){
		cerr << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }
  if (!file.is_open()){
    cerr << "Error opening file: " << filename << endl;
    return 1;
  }

  while(getline(file, line)){
		//do something
		getMulFromLine(line, muls); 
	}
	printVector(muls);
	int sum = parseAndMultiplyMuls(muls);

	cout << muls.size() << endl;
	cout << sum << endl;
  return 0;
}
