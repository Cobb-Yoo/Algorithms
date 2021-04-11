#include <iostream>
using namespace std;

char arr[2200][2200];
int n;

void init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			arr[i][j] = ' ';
		}
	}
}

void function(int num, int a, int b){
	if(num == 1){
		arr[a][b] = '*';
		return;
	}
	else{
		num /= 3;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i==1 && j==1) continue;
				else function(num,a+(num*i),b+(num*j));
			}
		}
	}
}

int main(){
	cin >> n;
	
	init();
	function(n,0,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
}
