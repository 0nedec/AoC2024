#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

bool is_descending(int a, int b) {
	return ( a - b  > 0 );
}

bool is_ascending(int a, int b) {
	return ( a - b < 0); 
}

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "Usage: " << argv[0] << "<filename>" << endl;
		return 1;
	}
	string filename = argv[1];
	ifstream file(filename);
	string line;
	vector< vector<int> > lines;
	int safe_counter = 0;		
	char direction = '0';
  char safe = 'u';

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
			int kk = 0;
				//check if the line is completely ascending or descending
					kk=jj+1;
					if (kk == lines[ii].size()) {
						break;
					}
					else if(is_descending(lines[ii][jj],lines[ii][kk]) && (direction == '0' || direction == 'd')) {
						direction = 'd';
						int diff= abs(lines[ii][jj]-lines[ii][kk]);
						if (diff >= 1 && diff <= 3){
							safe = 's';
						}
						else {
							safe = 'u';
							break;
						}
					}

					else if (is_ascending(lines[ii][jj],lines[ii][kk]) && (direction == '0' || direction == 'a')) {
						direction = 'a';
						int diff= abs(lines[ii][jj]-lines[ii][kk]);
						if (diff >= 1 && diff <= 3){
							safe = 's';
						}
						else {
							safe = 'u';
							break;
						}
					}
					else if ((lines[ii][jj]-lines[ii][kk] == 0) || direction=='a' || direction == 'd') {
						direction = 'E';
						break;
					}
		}
		cout << ii+1 << "\t" << direction << endl;
		if ((direction == 'd' || direction =='a') && safe == 's'){
			safe_counter++;
		}
		direction = '0';
		safe = 'u';
	}

	cout << safe_counter;
	return 0;
}
