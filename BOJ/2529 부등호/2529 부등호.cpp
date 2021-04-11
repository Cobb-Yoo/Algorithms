#include <iostream>
#include <vector> 
using namespace std;

int T;
char arr[10];

void maxAnswer(){
	int n=0,top=9;
	
	for(int i=0;i<T;i++){
		if(arr[i] == '>'){
			for(int j=top-n;j <= top;j++) cout << j;
			top = top - n - 1;
			n = 0;
		}else n++;
	}
	
	for(int i=top-n;i <= top;i++) cout <<i;
	cout << endl;
}

void minAnswer(){
	int n=0,top=0;
	
	for(int i=0;i<T;i++){
		if(arr[i] == '<'){
			for(int j=top+n;j >= top;j--) cout << j;
			top = top + n + 1;
			n = 0;
		}else n++;
	}
	
	for(int i=top+n;i >= top;i--) cout <<i;
	cout << endl;
}

int main(){
	cin >> T;
	
	for(int i=0;i<T;i++) cin >> arr[i];

	maxAnswer();
	minAnswer();
}
