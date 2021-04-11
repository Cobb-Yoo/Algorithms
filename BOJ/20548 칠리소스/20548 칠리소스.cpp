#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int answer = 0;
ll n;

void solve(int num){
	if(num < 0) return;
	ll tmp = pow(7, num);
	
	if(tmp <= n && n < tmp*2){
		answer += pow(3, num);
		if(tmp == n) {
			return;
		}
		else{
			n -= tmp;
			solve(num-1);
		}
	}
	else if(tmp*2 <= n){
		answer += pow(3, num)*2;
		if(tmp*2 == n){
			return;
		}
		else{
			n -= tmp*2;
			solve(num-1);
		}
	}
	else{
		solve(num-1);
	}
}

int main(){
	cin >> n;
	
	solve(15);
	
	cout << answer << endl;
}
