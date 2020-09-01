#include <iostream>
using namespace std;

const int MAX = 1024;
int map[MAX+1][MAX+1];
int num[MAX+1][MAX+1];
int n,m;

void initNum(){
	num[1][1] = map[1][1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == 1 && j == 1) continue;
			else if(i == 1){
				num[i][j] = map[i][j] + num[i][j-1];
			}
			else if(j == 1){
				num[i][j] = map[i][j] + num[i-1][j];
			}
			else{
				num[i][j] = map[i][j] + num[i-1][j] + num[i][j-1] - num[i-1][j-1];
			}
		}
	}
}

int getNum(int a, int b, int x, int y){
	int result = num[x][y];
	
	if(a == 1 && b == 1) return result;
	
	if(a == 1){
		result -= num[x][b-1];
	}
	else if(b == 1){
		result -= num[a-1][y];
	}
	else{
		result -= (num[x][b-1] + num[a-1][y] - num[a-1][b-1]);
	}
	
	return result;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> map[i][j];
		}
	}
	
	initNum();
	
	for(int i=0;i<m;i++){
		int a,b,x,y;
		cin >> a >> b >> x >> y;
		
		cout << getNum(a,b,x,y) << "\n";
	}
}
