#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "Usage: " << argv[0] << "<filename>" << endl;
		return 1;
	}
	string filename = argv[1];
	ifstream file(filename);
	string line;
	vector< vector<int> > lines;
		

	if (!file.is_open()){
		cerr << "Error opening file: " << filename << endl;
		return 1;
	}

	while(getline(file, line)){
		//do something
		istringstream iss(line);
		int num;
		vector<int> numbers;
		while (iss >> num) {
			numbers.push_back(num);
		}
		lines.push_back(numbers);
	}
	file.close();

	for (int ii=0;ii < lines.size();++ii){
		for(int jj = 0; jj < lines[ii].size(); ++jj){
			cout << lines[ii][jj] << " ";
		}
		cout << endl;
	}


	return 0;
}
