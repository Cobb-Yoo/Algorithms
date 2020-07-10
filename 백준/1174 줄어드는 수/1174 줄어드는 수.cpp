#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<ll> answer;
	for(int i=1;i<1024;i++){
		ll sum = 0;
		for(int j=0;j<10;j++){
			if(i & (1<<j)) sum = sum*10 + 9-j;
		}
		answer.push_back(sum);
	}
	
	sort(answer.begin(), answer.end());
	if(n > answer.size()) cout << -1;
	else cout << answer[n-1];
}
