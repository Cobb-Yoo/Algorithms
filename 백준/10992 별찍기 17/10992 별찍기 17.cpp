#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	for(int i=1;i<n;i++) cout << " ";
	cout << "*\n";
	
	for(int i=2;i<n;i++){
		for(int j=i;j<n;j++) cout << " ";
		cout << "*";
		for(int j=2;j<i*2-1;j++) cout << " ";
		cout << "*\n";
	}
	for(int i=1;i<=n*2-1;i++) cout << "*";
}
