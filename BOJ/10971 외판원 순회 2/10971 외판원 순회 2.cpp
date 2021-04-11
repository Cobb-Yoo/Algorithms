#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[10][10];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	int answer = 987654321;
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	vector<int> option(n);
	for(int i=0;i<n;i++) option[i] = i;
	
	do{
		int sum = 0;
		bool flag = 1;
		
		for(int i=0;i<n-1;i++){
			if(map[option[i]][option[i+1]] != 0){
				sum += map[option[i]][option[i+1]];
			}
			else {
				flag = 0;
				break;
			}
		}
		
		if(flag && map[option[n-1]][option[0]] != 0){
			sum += map[option[n-1]][option[0]];
			answer = min(answer, sum);
		}
	}while(next_permutation(option.begin(), option.end()));
	
	cout << answer << endl;
}
