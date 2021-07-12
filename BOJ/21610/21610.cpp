#include <bits/stdc++.h>
using namespace std;

const int Max = 101;
int A[Max][Max];
bool visited[Max][Max];
int option[9][2] = {{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
queue<pair<int,int>> cludes;
int n,m;

void makeCludesByOrder(){
	cludes.push({n,1});
	cludes.push({n,2});
	cludes.push({n-1,1});
	cludes.push({n-1,2});
}

int getAnswer(){
	int tmp=0;
	
	for(int i=1;i<=Max;i++){
		for(int j=1;j<=Max;j++){
			if(A[i][j]) tmp+= A[i][j];
		}
	}
	
	return tmp;
}

int getNextY(int y, int d){
	y = y + option[d][0];
	
	if(y == 0) return n;
	else if(y == n+1) return 1;
	else return y;
}

int getNextX(int x, int d){
	x = x + option[d][1];
	
	if(x == 0) return n;
	else if(x == n+1) return 1;
	else return x;
}

void moveCludes(int d, int s){
	queue<pair<int,int>> q;
	
	while(!cludes.empty()){
		int y = cludes.front().first;
		int x = cludes.front().second;
		cludes.pop();
		
		for(int i=0;i<s;i++){
			y = getNextY(y, d);
			x = getNextX(x, d);
		}
		
		A[y][x] += 1;
		q.push({y,x});
		visited[y][x] = 1;
	}
	
	cludes = q;
}

void checkCludes(){
	
	while(!cludes.empty()){
		int y = cludes.front().first;
		int x = cludes.front().second;
		cludes.pop();
		
		int cnt = 0;
		
		for(int i=2;i<=8;i+=2){
			int ny = y + option[i][0];
			int nx = x + option[i][1];
			
			if(0<ny&&ny<=n && 0<nx&&nx<=n){
				if(A[ny][nx]) cnt++;
			}
		}
		
		A[y][x] += cnt;
	}
}

void makeCludesBucket(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!visited[i][j] && A[i][j] >= 2){
				A[i][j] -= 2;
				cludes.push({i,j});
			}
		}
	}
}

void printing(string str = "start printing "){
	cout << str << "==================\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "end priting==================\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> A[i][j];
		}
	}
	
	int d,s;
	
	makeCludesByOrder();
	for(int i=0;i<m;i++){
		cin >> d >> s;
		moveCludes(d,s);
		//printing("moveCludes");
		
		checkCludes();
		//printing("checkCludes");
		
		makeCludesBucket();
		//printing("makeCludesBucket");
		
		memset(visited,0,sizeof(visited));
	}
	
	int answer = getAnswer();
	cout << answer << endl;
}
