#include <iostream>
#include <vector>
// #include <stdlib.h>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	vector<int> v_input;
	int i = 1;
	while(argv[i]) {
		v_input.push_back(stoi(argv[i]));
		i++;
	}
	
	for (auto el : v_input) {
		cout << el << " ";
	}
	cout << endl;
	return 0;
}
