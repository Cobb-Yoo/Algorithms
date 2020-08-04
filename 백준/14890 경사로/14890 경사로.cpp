#include <iostream>
#include <cstring>
using namespace std;

int n, l;
int answer = 0;
int map[100][100];
bool useRunway[100];

void row(int x){
	memset(useRunway,0,sizeof(useRunway));
	for(int i=0;i<n;){
		int now = map[i][x];
		
		if(i+1<n && now == map[i+1][x]){
			i++;
			continue;
		}
		
		int j;
		for(j=i;j<i+l && j<n;j++) {
			if(now != map[j][x] && !useRunway[j]) return;
			useRunway[j] = 1;
		}
		if(j != i+l) return;
		
		i+=l;
	}
	
	answer++;
}

void col(int y){
	memset(useRunway,0,sizeof(useRunway));
	for(int i=0;i<n;){
		int now = map[y][i];
		
		if(i+1<n && now == map[y][i+1]){
			i++;
			continue;
		}
		
		int j;
		for(j=i;j<i+l && j<n;j++) {
			if(now != map[y][j] && !useRunway[j]) return;
			useRunway[j] = 1;
		}
		if(j != i+l) return;
		
		i+=l;
	}
	
	answer++;
}

int main(){
	cin >> n >> l;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<n;i++) row(i);
	for(int i=0;i<n;i++) col(i);
	
	cout << answer << endl;
}
