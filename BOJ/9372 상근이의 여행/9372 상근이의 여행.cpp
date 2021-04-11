#include <iostream>
using namespace std;

int n,m;

int main(){
	int t; cin >> t;
	
	while(t--){
		cin >> n >> m;
		
		for(int i=0;i<m;i++){
			int a,b;
			cin >> a >> b;
		}
		cout << n-1 << endl; 
	}
}
