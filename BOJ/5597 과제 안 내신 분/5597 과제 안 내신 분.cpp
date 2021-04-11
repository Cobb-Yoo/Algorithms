#include <iostream>
using namespace std;

bool arr[31];

int main(){
	int n;
	for(int i=0;i<28;i++){
		cin >> n;
		
		arr[n] = 1;
	}
	
	for(int i=1;i<=30;i++){
		if(!arr[i]) cout << i << endl;
	}
}
