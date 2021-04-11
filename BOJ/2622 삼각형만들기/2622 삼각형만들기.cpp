#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	int answer = 0;
	
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			int k = n-i-j;
			
			if(k < j) break;
			
			if(k < i+j) answer++;
		}
	}
	
	cout << answer << endl;
}
