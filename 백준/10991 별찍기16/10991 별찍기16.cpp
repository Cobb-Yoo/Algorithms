#include <iostream>
using namespace std;

void printing(int n){
	for(int i=0;i<n*2;i++){
		if(!(i&1)) cout << "*";
		else cout << " ";
	}
	cout << endl;
}

int main(){
	int n; cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++) cout << " ";
		printing(i);
	}
}
