#include <iostream>
using namespace std;

int n;
int arr[15];
int brr[15];

void dfs(int cnt, int end){
	if(end == 6){
		for(int i=0;i<6;i++) cout<< brr[i] << " ";
		cout << endl;
		return;
	}
	
	for(int i=cnt;i<n;i++){
		brr[end] = arr[i];
		dfs(i+1,end+1);
	}
}

int main(){
	while(cin >> n && n != 0){
		for(int i=0;i<n;i++) cin >> arr[i];
		
		dfs(0,0);
		cout << endl;
	}
}
