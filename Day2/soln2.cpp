#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

char safe = '-';
char direction =  '-';

void dampner(vector<int> unsafeReport){
	vector< vector <int> > subReports;
	for (int ii = 0; ii < unsafeReport.size(); ++ii){
		vector<int> reportCopy(unsafeReport);
		reportCopy.erase(reportCopy.begin()+ii);
		subReports.push_back(reportCopy);
	}
return;
}





void check_safety(int a, int b) {
	//find the difference
	int diff = a - b;
	int adj_level = abs(diff);
	//check if ascending or descending difference has flipped. if so mark unsafe.
	if ((diff < 0) && direction == 'd'){
		safe = 'u';
		return;
	}
	else if ((diff > 0)	 && direction == 'a'){
		safe = 'u';
		return;
	}
	//check if no difference between two numbers. if so mark unsafe.
	else if (diff == 0){
		safe = 'u';
		return;
	}
	//check if two adjajent levels are at least 1 and at most 3
	else if (adj_level <1 || adj_level >3){
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

void checkLineForSafety(vector<int> line){
	for (int jj = 0; jj < line.size(); ++jj){
		kk = jj + 1;
		if (kk == line.size()){
			return;
		}
		else {
			check_safety(line[jj], line[kk]);
			if (safe == 's') {
				continue;
			}
			else {
				break;
			}
		}
	}
	cout << safe << direction << endl;
	if((direction == 'd' || direction == 'a') &&  safe == 's') {
		safe_counter++
	}
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
	vector <vector<int> > unsafe_reports;
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
		checkLineForSafety(lines[ii]);
/*		for(int jj = 0; jj < lines[ii].size(); ++jj){
			int kk = 0;
					kk=jj+1;
					if (kk == lines[ii].size()) {
						break;
					}
					else{
						check_safety(lines[ii][jj],lines[ii][kk]);
						if(safe == 's'){
							continue;
						}
						else {
							unsafe_reports.push_back(lines[ii]);
							break;
						}
					}
		}
		cout << ii+1 << "\t" << safe << direction << endl;
		if ((direction == 'd' || direction =='a') && safe == 's'){
			safe_counter++;
		}
*/
		direction = '-';
		safe = '-';
		//prob_damp = 't';
	}
	cout << safe_counter << endl;
	
	cout << "Unsafe Reports:" << endl;
	for (int ii=0; ii < unsafe_reports.size();++ii){
		for (int jj=0; jj < unsafe_reports[ii].size(); ++jj) {
			cout <<  unsafe_reports[ii][jj];
			}
		cout << endl;
		}

	return 0;
}
