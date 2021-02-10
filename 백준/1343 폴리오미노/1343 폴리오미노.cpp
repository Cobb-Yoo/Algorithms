#include <iostream>
#include <string>
using namespace std;

int main(){
	string str; cin >> str;
	
	int len = str.size();
	int arr[501] = {0};
	int brr[501] = {0};
	int idx = 0;
	
	for(int i=0;i<len;i++){
		if(str[i] == 'X') arr[idx]++;
		else if(str[i-1] == 'X' && str[i] == '.') {
			if(arr[idx]%2){
				cout << -1;
				return 0;
			}
			idx++;
		}
	}
	
	if(arr[idx]%2){
		cout << -1;
		return 0;
	}
	
	int idx_b=0;
	for(int i=0;i<len;i++){
		if(str[i] == 'X'){
			for(int j=0;j<arr[idx_b]/4;j++){
				cout << "AAAA";
			}
			for(int j=0;j<arr[idx_b]%4;j++){
				cout << "B";
			}
			i += arr[idx_b++]-1;
		}
		else cout << '.';
	}
}
