#include <iostream>
#include <string>
using namespace std;

string a,b;
int currentH, currentM, currentS;
int lastH, lastM, lastS;

int main(){
	cin >> a >> b;	
	
	currentH = stoi(a.substr(0,2));
	currentM = stoi(a.substr(3,2));
	currentS = stoi(a.substr(6,2));
	
	lastH = stoi(b.substr(0,2));
	lastM = stoi(b.substr(3,2));
	lastS = stoi(b.substr(6,2));
	
	int resultH;
	int resultM;
	int resultS = lastS-currentS;
	
	if(resultS < 0){
		resultS += 60;
		lastM--;
	}
	
	resultM = lastM-currentM;
	
	if(resultM < 0){
		resultM += 60;
		lastH--;
	}
	
	resultH = lastH-currentH;
	
	if(resultH < 0) resultH += 24;
	
	string x[3];
	x[0] = to_string(resultH);
	x[1] = to_string(resultM);
	x[2] = to_string(resultS);
	
	for(int i=0;i<3;i++){
		if(x[i].size() == 1) {
			x[i] = '0'+x[i];
		}
	}
	
	cout << x[0] << ":" << x[1] << ":" << x[2];
}
