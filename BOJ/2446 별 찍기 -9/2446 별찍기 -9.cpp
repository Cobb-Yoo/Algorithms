#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int len = 2*n -1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++) cout << " ";
		for(int j=0;j<len-i*2;j++) cout << "*";
		cout << endl;
	}
	
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<i;j++) cout << " ";
		for(int j=0;j<len-i*2;j++) cout << "*";
		cout << endl;
	}
}
