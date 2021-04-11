#include <iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	
	long long answer = (n-1)*n/2;
	answer *= (n+1);
	
	cout << answer << endl;
}
