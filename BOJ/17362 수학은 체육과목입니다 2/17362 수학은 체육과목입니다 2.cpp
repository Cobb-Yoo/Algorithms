#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	if(n <= 5) {
		cout << n;
		return 0;
	}
	
	while (n > 5) n -= 8;
	
	int result = n;
	if (result <= 0) result = 2 + (result * -1);
	
	cout << result << "\n";
}
