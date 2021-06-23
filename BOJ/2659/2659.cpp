#include <bits/stdc++.h>
using namespace std;

bool visited[10000];

int getNum(int a,int b, int c, int d){
	int w = 1000*a + 100*b + 10*c + d;
	int x = 1000*b + 100*c + 10*d + a;
	int y = 1000*c + 100*d + 10*a + b;
	int z = 1000*d + 100*a + 10*b + c;
	
	return min({w,x,y,z});
}

void init(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			for(int k=1;k<=9;k++){
				for(int l=1;l<=9;l++){
					int n = getNum(i,j,k,l);
					visited[n] = 1;
				}
			}
		}
	}
}

int main(){
	init();
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	
	int n = getNum(a,b,c,d);
	int cnt = 0;
	
	for(int i=1111;i<=n;i++){
		if(visited[i]) cnt++;
	}
	
	cout << cnt << endl;
}
