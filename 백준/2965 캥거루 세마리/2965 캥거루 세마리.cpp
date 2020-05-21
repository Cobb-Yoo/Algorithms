#include <iostream> 
using namespace std;

int main(){
	int a,b,c;
	
	cin >> a >> b >> c;
	
	b-a > c-b ? cout << b-a-1 : cout << c-b-1;
}
