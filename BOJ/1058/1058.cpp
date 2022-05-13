#include <bits/stdc++.h>
using namespace std;

const int Max = 50;
const int inf = 987654321;

int n;
int Map[Max][Max];

void floyd_warshall(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j || j==k || i==k) {
					continue;
				}
				else if(Map[i][j] > Map[i][k]+Map[k][j]){
					Map[i][j] = Map[i][k]+Map[k][j];
				}
			}
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		string str;
		cin >> str;
		
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			else {
				Map[i][j] = str[j] == 'Y' ? 1 : inf;
			}
		}
	}
	
	floyd_warshall();
	
	int answer = 0;
	for(int i=0;i<n;i++){
		int cnt =0;
		
		for(int j=0;j<n;j++){
			if(i==j) {
				continue;
			}
			else if(Map[i][j] <= 2) {
				cnt++;
			}
		}
		
		answer = max(answer, cnt);
	}
	cout << answer;
}
