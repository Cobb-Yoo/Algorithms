#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[50][50];
int dis[50][50];
bool unbroken[13];
vector<pair<int,int>> chicken; // <y,x>
vector<pair<int,int>> home;
int n, m;
int answer = 987654321;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int getlen(int y, int x){
	int len = 987654321;
	
	for(int i=0;i<chicken.size();i++){
		if(unbroken[i]){
			len = min(len, abs(y-chicken[i].first)+abs(x-chicken[i].second));
		}
	}
	
	return len;
}

void checking(){
	int result = 0;
	for(int i=0;i<home.size();i++){
		memset(dis,-1,sizeof(dis));
		result += getlen(home[i].first, home[i].second);
	}
	
	answer = min(answer, result);
}

void f(int begin, int cnt){
	if(cnt == m){
		checking();
		return;
	}
	
	for(int i=begin+1;i<chicken.size();i++){
		unbroken[i] = 1;
		map[chicken[i].first][chicken[i].second] = 2;
		f(i, cnt+1);
		map[chicken[i].first][chicken[i].second] = 0;
		unbroken[i] = 0;
	}
}

int main(){
	memset(unbroken,0,sizeof(unbroken));
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 1) home.push_back({i,j});
			else if(map[i][j] == 2){
				chicken.push_back({i,j});
				map[i][j] = 0;
			}
		}
	}
	
	for(int i=0;i<chicken.size();i++){
		unbroken[i] = 1;
		map[chicken[i].first][chicken[i].second] = 2;
		f(i, 1);
		map[chicken[i].first][chicken[i].second] = 0;
		unbroken[i] = 0;
	}
	
	cout << answer << endl;
}
