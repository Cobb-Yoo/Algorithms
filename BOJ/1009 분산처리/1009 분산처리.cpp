#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		
		int result = a % 10;
		int mul = b % 4;
		
		for(int j=1;j< (mul == 0 ? 4 : mul);j++){
			result *= a;
			result %= 10;
		}
		
		result = result ? result : 10;
		
		cout << result << endl;
	}
}

jaimemin
