#include <iostream>
#include <queue>
using namespace std;

char arr[65][65];
queue<char> arr_queue;

void func(int n,int a,int b){
	int num = arr[a][b];
	
	for(int i=a;i<a+n;i++){
		for(int j=b;j<b+n;j++){
			if(arr[i][j] != num){
				arr_queue.push('(');
				func(n/2,a,b);
				func(n/2,a,b+n/2);
				func(n/2,a+n/2,b);
				func(n/2,a+n/2,b+n/2);
				arr_queue.push(')');
				return;
			}
		}
	}
	arr_queue.push(num);
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	
	func(n,0,0);
	
	while(!arr_queue.empty()){
		cout << arr_queue.front();
		arr_queue.pop();
	}
}
