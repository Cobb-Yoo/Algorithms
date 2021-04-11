#include <iostream>
#define MAX 8
using namespace std;

int arr[MAX];
int m,n;

void dfs(int a, int b){
	if(b == n) {
		for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	
	else
		for(int i=0;i<m;i++){
			arr[b] = i+1;
			dfs(i,b+1);	
		}
}

int main(){
	cin >> m >> n;
	
	dfs(0,0);
}
