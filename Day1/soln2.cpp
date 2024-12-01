#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[] ){
  if (argc !=2) {
    cerr << "Usage: " << argv[0] << "<filename>" << endl;
    return 1;
  }
  
  int sum = 0;
  string filename = argv[1];
  string line;
  ifstream file(filename);
  vector<int> first_array, second_array;

  //Open the file
  if (!file.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return 1;
  }
  //Parse the file and create 2 arrays
  while (getline(file, line)) {
    istringstream iss(line);
    int num1, num2;
    if (iss >> num1 >> num2) {
      first_array.push_back(num1);
      second_array.push_back(num2);
    } 
    else {
      cerr << "Error parsing line:" << line << endl;
    }
  }
  file.close();
  
  for(int i = 0; i < first_array.size(); ++i) {
    int similarity = 0;
    for (int j = 0; j < second_array.size(); ++j) {
      if (first_array[i] == second_array[j]){
        similarity++;
      }
    }
    sum+= (first_array[i]*similarity);
  }
  
  cout << "Sum: " << sum << endl;
  
  return 0;
}
