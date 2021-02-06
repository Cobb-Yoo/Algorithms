#include <iostream>
using namespace std;

int map[5][5];
bool visited[5][5];
pair<int,int> arr[25];

bool check(){
	int cnt=0;
	
	for(int i=0;i<5;i++){
		int row = 0;
		int col = 0;
		
		for(int j=0;j<5;j++){
			if(visited[i][j]) row++;
			if(visited[j][i]) col++;
		}
		
		if(row==5) cnt++;
		if(col==5) cnt++;
	}
	
	int a=0,b=0;
	
	for(int i=0;i<5;i++){
		if(visited[i][i]) a++;
		if(visited[4-i][i]) b++;
	}
	
	if(a==5) cnt++;
	if(b==5) cnt++;
	
	if(cnt >= 3) return 1;
	else return 0;
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> map[i][j];
			arr[map[i][j]] = {i,j};
		}
	}
	
	int i;
	for(i=1;i<=25;i++){
		int num; cin >> num;
		visited[arr[num].first][arr[num].second] = 1;
		if(check()) break;
	}
	
	cout << i << endl;
}

