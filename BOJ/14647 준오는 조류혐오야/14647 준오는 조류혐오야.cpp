#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 500;
int arr[MAX+1][MAX+1];
int ver[MAX+1];
int col[MAX+1];
int n,m;
int cnt;

int have9(int a, int b){
	int num = arr[a][b];
	int count = 0;
	
	while(num > 0){
		if(num%10 == 9) count++;
		num /= 10;
	}
	
	return count;
}

void init(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> arr[i][j];
			cnt += have9(i,j);;
		}
	}
	
	memset(ver,0,sizeof(ver));
	memset(col,0,sizeof(col));
}

int count_ver(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ver[j] += have9(i,j);
		}
	}
	
	int result = 0;	
	for(int i=1;i<=m;i++) result = max(result, ver[i]);
	
	return result;
}

int count_col(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			col[i] += have9(i,j);
		}
	}
	
	int result = 0;
	for(int i=1;i<=n;i++) result = max(result, col[i]);
	
	return result;
}

int main(){
	
	init();
	int v = count_ver();
	int c = count_col();
	
	cout << cnt - max(v,c) << endl;
}


