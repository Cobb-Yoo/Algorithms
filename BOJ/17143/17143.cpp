#include <bits/stdc++.h>
using namespace std;

struct Node{
	int s;
	int d;
	int z;
};

const int Max = 101;
int R,C,m;
int option[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
vector<Node> v[Max][Max];
int answer;

void fishing(int idx){
	for(int i=1;i<=R;i++){
		if(v[i][idx].size()){
			answer += v[i][idx][0].z;
			v[i][idx].clear();
			return;
		}
	}
}

void move(){
	queue<pair<pair<int,int>, Node>> q;
	
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++){
			if(v[i][j].size()){
				q.push({{i,j},v[i][j][0]});
				v[i][j].clear();
			}
		}
	}
	
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int size = q.front().second.z;
		int op = q.front().second.d;
		int speed = q.front().second.s;
		q.pop();
		
		for(int i=0;i<speed;i++){
			if(op == 0 || op == 1){
				int next = y + option[op][0];
				if(next<1 || R <next) op = 1 - op;
				
				y += option[op][0];
			}
			else {
				int next = x + option[op][1];
				if(next<1 || C <next) op = 5 - op;
				
				x += option[op][1];
			}
		}
		
		if(v[y][x].size()){
			if(v[y][x][0].z < size){
				v[y][x].clear();
				v[y][x].push_back({speed, op, size});
			}
		}
		else{
			v[y][x].push_back({speed, op, size});
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C >> m;
	
	for(int i=1;i<=m;i++){
		int r,c,s,d,z;
		cin >> r >> c >> s >> d >> z;
		
		v[r][c].push_back({s,d-1,z});
	}
	
	for(int i=1;i<=C;i++){
		fishing(i);
		move();
	}
	
	cout << answer << endl;
}
