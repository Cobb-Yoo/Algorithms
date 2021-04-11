#include <iostream>
#include <cstring>
using namespace std;

int n,l;
int map[100][200];
int answer = 0;

void runway(int idx){
	int cnt = 1;
	int i;
	for(i=0;i<n-1;i++){
		if(map[i][idx] == map[i+1][idx]) cnt++;
		else if(map[i][idx]+1 == map[i+1][idx] && cnt >= l) cnt = 1;
		else if(map[i][idx]-1 == map[i+1][idx] && cnt >= 0) cnt = 1-l;
		else break;
	}
	
	if(i==n-1 && cnt >= 0) answer++;
}

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=n;j<2*n;j++){
			map[i][j] = map[j-n][i];
		}
	}
}

int main(){
	memset(map,-1,sizeof(map));
	cin >> n >> l;
	
	init();
	
	for(int i=0;i<2*n;i++) runway(i);
	
	cout << answer << endl; 
}
