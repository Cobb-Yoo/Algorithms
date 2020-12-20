#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool arr[300000];
vector<int> v;
int a,p;
int idx;

void solve(){
	int tmp = a;
	v.push_back(tmp);
	arr[tmp] = 1;
	
	while(1){
		int n = tmp;
		int b = 0;
		
		while(n > 0){
			b += (int)pow((n%10), p);
			n /= 10;
		}
		
		tmp = b;
		
		if(arr[tmp]) {
			idx = tmp;
			return;
		}
		else{
			v.push_back(tmp);
			arr[tmp] = 1;
		}
	}
}

int main(){	
	cin >> a >> p;
	
	solve();
	
	int cnt = 0;
	
	for(auto i : v){
		if(i == idx) break;
		else cnt++;
	}
	
	cout << cnt << endl;
}
