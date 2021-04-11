#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main(){
	ll t;
	cin >> t;
	
	while(t--){
		ll x,y;
		cin >> x >> y;
		
		ll distance = y - x;
		
		if(distance < 4){
			cout << distance << endl;
			continue;
		}
		
		ll tmp = sqrt(distance);
		ll tmp2 = tmp + 1;
		
		if(distance == tmp*tmp){
			cout << tmp * 2 - 1 << endl;
			continue;
		}
		
		if(distance <= (tmp2*tmp2 + tmp*tmp) / 2) {
			cout << tmp * 2 << endl;
		}
		else{
			cout << tmp * 2 + 1 << endl;
		}
	}
}
