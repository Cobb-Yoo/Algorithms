#include <iostream>
using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	
	int answer = 0;
	
	while(a++ != b++){
		a >>= 1;
		b >>= 1;
		answer++;
	}
	
	cout << answer << endl;
}
