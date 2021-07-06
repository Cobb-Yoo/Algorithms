#include <bits/stdc++.h>
using namespace std;

const int Max = 1001;
bool graph[Max][Max];
int tmp;

void solve(int A,int B,int C){
	queue<pair<int,int>> q;
	q.push({A,B});
	graph[A][B] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int z = tmp -x-y;
		q.pop();
		
		if(x==y && y==z){
			cout << 1;
			exit(0);
		}
		
		int nx[] = {x,x,y};
		int ny[] = {y,z,z};
		
		for(int i=0;i<3;i++){
			int a = nx[i];
			int b = ny[i];
			
			if(a<b) b -= a, a += a;
			else if(a > b) a -= b, b +=b;
			else continue;
			
			int c = tmp -a-b;
			
			int X = min({a,b,c});
			int Y = max({a,b,c});
			
			if(!graph[X][Y]){
				q.push({X,Y});
				graph[X][Y] = 1;
			}
		}
	}
	cout << 0;
}

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	tmp = a+b+c;
	int idx = tmp/3;
	
	if(tmp%3) {
		cout << 0;
		exit(0);
	}
	
	solve(a,b,c);
}
