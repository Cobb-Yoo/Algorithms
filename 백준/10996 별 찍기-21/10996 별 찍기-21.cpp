#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int len = n*2;
	bool env = 1;
	
	for(int i=0;i<len;i++){
		i&1 ? env=0 : env =1;
		for(int j=0;j<n;j++){
			if(env) cout << "*";
			else cout << " ";
			env ^= 1;
		}
		cout << endl;
	}
}
