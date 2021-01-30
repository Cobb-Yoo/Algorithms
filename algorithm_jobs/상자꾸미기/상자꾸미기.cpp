#include <iostream>
using namespace std;

int arr[1001];

int main(){
	int n; cin >> n;
	int cnt = 0;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		if(arr[tmp] == 0 || arr[tmp] == 1) {
			arr[tmp]++;
			cnt++;
		}
	}
	
	if(cnt < 6) cout << "NO";
	else cout << "YES";
}
