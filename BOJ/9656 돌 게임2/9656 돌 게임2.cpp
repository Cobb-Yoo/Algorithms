#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	
	if(n&1)  cout << "CY\n";
	else cout << "SK\n";
}
