#include <iostream>
using namespace std;

long long cal(int a, int b,int c){
	if(b == 1) return a;
	else {
		long long tmp = cal(a,b/2,c);
		
		if(b % 2) return ((tmp*tmp)%c * a) % c;
		else return (tmp*tmp)%c;
	}
}

int main(){
	long long a,b,c;
	cin >> a >> b >> c;
		
	cout << cal(a%c,b,c) << endl;
}
