#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

char safe = '-';
char direction =  '-';
int safe_counter = 0;



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
		int kk = jj + 1;
		if (kk == line.size()){
			cout << safe << direction << endl;
			if((direction == 'd' || direction == 'a') &&  safe == 's') {
				safe_counter++;
				cout << "safe counter updated to: " << safe_counter << endl;
			}
			return;
		}
		else {
			cout << "Checking safety on " << line[jj] << " and " << line[kk] << endl;
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
}

void dampner(vector<int> unsafeReport){
	//create subReports to check each iteration of problem dampner
	vector< vector <int> > subReports;
	for (int ii = 0; ii < unsafeReport.size(); ++ii){
		vector<int> reportCopy(unsafeReport);
		reportCopy.erase(reportCopy.begin()+ii);
		subReports.push_back(reportCopy);
	}

	for (const auto& row : subReports) {
		for(int num : row) {
			cout << num << " ";
		}
		cout << endl;
	}
	//iterate over each subreport
	//if subreport is valid update report counter
	//break out of chekcing subReports
	for (int jj = 0; jj < subReports.size(); ++jj){
		safe = '-';
		direction =  '-'; 
		checkLineForSafety(subReports[jj]);
		if (safe == 's') {
			return;
		}
		else {
			continue;
		}
	}
	return;
}

int main(int argc, char *argv[]){
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << "<filename>" << endl;
		return 1;
	}
	string filename = argv[1];
	ifstream file(filename);
	string line;
	vector< vector<int> > lines;
	vector <vector<int> > unsafe_reports;
	
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
		cout << endl << "Checking line " << ii << endl;
		checkLineForSafety(lines[ii]);
		if (safe == 'u') {
			unsafe_reports.push_back(lines[ii]);
		}
		direction = '-';
		safe = '-';
	}
	cout << safe_counter << endl;
	cout <<  "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Running dampner" << endl;
/*
	cout << "Unsafe Reports:" << endl;
	for (int ii=0; ii < unsafe_reports.size();++ii){
		for (int jj=0; jj < unsafe_reports[ii].size(); ++jj) {
			cout <<  unsafe_reports[ii][jj];
			}
		cout << endl;
		}
*/
	for (int ii = 0; ii < unsafe_reports.size(); ++ii){
		dampner(unsafe_reports[ii]);
		safe = '-';
	}
	cout << safe_counter << endl;
	return 0;
}
