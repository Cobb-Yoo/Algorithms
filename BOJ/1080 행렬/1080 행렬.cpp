#include <iostream>
#include <string>
using namespace std;

int n,m;
int answer = 0;
bool arr[51][51];
bool brr[51][51];

void cinarr(){
	string tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		for(int j=0;j<m;j++){
			if(tmp[j] == '0') arr[i][j] = false;
			else arr[i][j] = true;
		}
	}
	
	for(int i=0;i<n;i++){
		cin >> tmp;
		for(int j=0;j<m;j++){
			if(tmp[j] == '0') brr[i][j] = false;
			else brr[i][j] = true;
		}
	}
}

void rvs(int a,int b){
	answer++;
	for(int i=a;i<a+3;i++){
		for(int j=b;j<b+3;j++){
			arr[i][j] = !arr[i][j];
		}
	}
}

void f(){	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i < n-2 && j < m-2 && arr[i][j] != brr[i][j]) rvs(i,j);
		}
	}	
}

bool check(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] != brr[i][j]) return false;
		}
	}
	
	return true;
}

int main(){
	cin >> n >> m;

	cinarr();
	f();
	
	if(check()) cout << answer << endl;
	else cout << -1 << endl;
}
