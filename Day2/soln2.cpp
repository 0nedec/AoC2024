#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

char safe '-';
char direction '-';


void set-safety(int a, int b) {
	//find the difference
	int diff = a - b;
	int adj_level = abs(diff);

	//check if ascending or descending difference has flipped. if so mark unsafe.
	if ((diff < 0) && (direction !=  '-' || direction == 'd'){
		safe = 'u';
		return;
	}
	else if ((diff > 0)	 && (direction != '-' || direction == 'a'){
		safe = 'u'
		return;
	}
	//check if no difference between two numbers. if so mark unsafe.
	else if (diff == 0){
		safe = 'u';
		return;
	}
	//check if two adjajent levels are at least 1 and at most 3
	else if (adj_level <1 && adj_level >3){
		safe = 'u';
		return;
	}
	else if ( diff > 0 && direction == '-'){
		direction = 'd';
	}
	else if ( diff < 0 && direction == '-') {
		direction = 'a';
	}
	safe = 's';
	return;
}



/*

bool is_descending(int a, int b) {
	return ( a - b  > 0 );
}

bool is_ascending(int a, int b) {
	return ( a - b < 0); 
}
*/

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
  char prob_damp = 't';
	
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
					kk=jj+1;
					if (kk == lines[ii].size()) {
						break;
					}
/*					else if(is_descending(lines[ii][jj],lines[ii][kk]) && (direction == '0' || direction == 'd')) {
						direction = 'd';
						int diff= abs(lines[ii][jj]-lines[ii][kk]);
						if (diff >= 1 && diff <= 3){
							safe = 's';
						}
						else if(is_descending(lines[ii][jj],lines[ii][kk+1]) && (direction == '0' || direction == 'd') && prob_damp == 't') {
							direction = 'd';
							prob_damp = 'f';
							int diff= abs(lines[ii][jj]-lines[ii][kk+1]);
							if (diff >= 1 && diff <= 3){
								safe = 's';
							}
							jj++;
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
						else if(is_ascending(lines[ii][jj],lines[ii][kk+1]) && (direction == '0' || direction == 'a') && prob_damp == 't') {
							direction = 'a';
							prob_damp = 'f';
							int diff= abs(lines[ii][jj]-lines[ii][kk+1]);
							if (diff >= 1 && diff <= 3){
								safe = 's';
							}
							jj++;
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
		cout << ii+1 << "\t" << safe << direction << endl;
		if ((direction == 'd' || direction =='a') && safe == 's'){
			safe_counter++;
		}
		direction = '0';
		safe = 'u';
		prob_damp = 't';
	}
*/
	cout << safe_counter;
	return 0;
}
