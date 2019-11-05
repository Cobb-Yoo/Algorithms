#include <iostream>
#define MAX 8
using namespace std;

int arr[MAX];
bool sel[MAX];
int m,n;

void dfs(int a, int b){
	if(b == n) {
		for(int i=0;i<=m;i++)
			if(sel[i]) printf("%d ",i+1);
		printf("\n");
	}
	
	for(int i=a;i<m;i++){
		if(!sel[i] && b < n+1){
			sel[i] = true;
			dfs(i,b+1);
			sel[i] = false;
		}
	}
}

int main(){
	cin >> m >> n;
	
	dfs(0,0);
}
