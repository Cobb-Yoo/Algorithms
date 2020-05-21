#include <iostream> 
using namespace std;

int main(){
	long long n;
	cin >> n;
	int answer = (1 + 4*n +3*n*(n-1)/2) % 45678;
	
	cout << answer << endl;
}
