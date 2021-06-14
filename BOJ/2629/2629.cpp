#include <bits/stdc++.h>
using namespace std;

const int Max = 30;
int n,m;
int weight[Max+1];
int marble[7];
bool cache[Max+1][Max*500];

void solve(int weightNum, int currentWeight){
	if(weightNum > n) return;
	
	bool &result = cache[weightNum][currentWeight];
	if(result) return;
	
	result = 1;
	
	solve(weightNum+1, currentWeight+weight[weightNum]);
	solve(weightNum+1, currentWeight);
	solve(weightNum+1, abs(currentWeight-weight[weightNum]));
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> weight[i];
	
	cin >> m;
	for(int i=0;i<m;i++) cin >> marble[i];
	
	solve(0,0);
	
	for(int i=0;i<m;i++){
		if(marble[i] > 500*Max) cout << "N ";
		else if(cache[n][marble[i]]) cout << "Y ";
		else cout << "N ";
	}
	
	return 0;
}
