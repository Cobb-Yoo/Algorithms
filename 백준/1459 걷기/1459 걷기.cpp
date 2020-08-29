#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	ll x,y,w,s;
	cin >> x >> y >> w >> s;
	
	int flag = (x+y)%2;
	
	if(x < y) swap(x,y);
	cout << min({(x+y)*w, (x-flag)*s+flag*w, y*s+(x-y)*w}) << endl;
}
