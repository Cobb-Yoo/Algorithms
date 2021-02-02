#include <iostream>
#include <string>
using namespace std;

int arr[21];
int cnt;
void solve(int idx, int n, string str){
	str += to_string(idx);
	
	if(n <= 0) {
		cnt++;
		cout << str << endl;
		return;
	}
	else{
		for(int i=idx;i>=1;i--){
			if(n-i >= 0)
				solve(i, n-i,str+"+");
		}
	}
}

int main(){
	for(int i=1;i<=20;i++) arr[i] = i;
	int n; cin >> n;
	
	for(int i=n-1;i>=1;i--) solve(i, n-i, "");
	cout << cnt;
}
