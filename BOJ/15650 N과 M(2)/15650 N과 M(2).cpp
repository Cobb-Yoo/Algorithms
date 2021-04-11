#include <iostream>
using namespace std;
int n,m;

int arr[9];

void f(int begin, int cnt){
	arr[cnt] = begin;
	
	if(cnt == m-1){
		for(int i=0;i<m;i++) cout << arr[i] << " ";
		cout << endl;
		
		return;
	}
	
	for(int i=begin+1;i<=n;i++){
		f(i, cnt+1);
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) f(i, 0);
}
