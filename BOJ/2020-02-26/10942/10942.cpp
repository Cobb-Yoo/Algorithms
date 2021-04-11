#include <iostream>
using namespace std;

int arr[2001];
bool check(int begin, int end){
	int m = (begin + end) / 2 ;

	for(int i=begin;i<=m;i++){
		if(arr[i] != arr[end+begin-i]) return 0;
	}
	return 1;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	cin >> n;
	
	int a, b;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		cout << check(a-1,b-1) << endl;
	}
}
