#include <bits/stdc++.h>
using namespace std;

const int Max = 100;
string cMap[Max];
int tMap[Max][Max];
int h,w;
bool flag;

void solve(){
	for(int i=0;i<h;i++){
		int cnt = 0;
		flag = 0;
		
		for(int j=0;j<w;j++){	
			if(cMap[i][j] == 'c'){
				flag = 1;
				cnt = 0;
			}
			else if(flag){
				cnt++;
			}
			
			if(flag) tMap[i][j] = cnt;
			else tMap[i][j] = -1;
		}
	}
}

void printing(){
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cout << tMap[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	
	cin >> h >> w;
	
	for(int i=0;i<h;i++){
		cin >> cMap[i];
	}
	
	solve();
	printing();
}
