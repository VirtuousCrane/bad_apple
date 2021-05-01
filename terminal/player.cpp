#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

int main(){
	string line;
	int counter = 0;
	ifstream pf("bad_apple.txt");

	while(getline(pf, line)){
		cout << line << endl;
		counter++;
		if(counter >= 18){
			usleep(33000);
			counter = 0;
		}
	}
}
