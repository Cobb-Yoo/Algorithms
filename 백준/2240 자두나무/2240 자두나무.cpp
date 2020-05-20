#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000;

int t,w;
int arr[MAX+1];
int dp[3][MAX+1][31];

int solve(int tree, int second, int move){
	if(second == t) return 0;
	
	int &result = dp[tree][second][move];
	if(result != -1) return result;
	
	if(arr[second] == tree){
		if(move < w) return result = max(1+solve(tree,second+1,move),solve(3-tree,second+1,move+1));
		else return result =  1+solve(tree,second+1,move);
	}
	else{
		if(move < w) return result =  max(solve(tree,second+1,move),1+solve(3-tree,second+1,move+1));
		else return result = solve(tree,second+1,move);
	}
}

int main(){
	cin >> t >> w;
	
	for(int i=0;i<t;i++) cin >> arr[i];
	
	memset(dp,-1,sizeof(dp));
	
	cout << solve(1,0,0) << endl;
}
