#include <iostream>
using namespace std;

int main(){
	int arr[1000];
	int cnt = 0;
	int a = 1;
	
	for(int i=0;i<1000;i++){
		arr[i] = a;
		cnt++;
		
		if(cnt == a) {
			a++;
			cnt = 0;
		}
	}
	
	int sum = 0;
	int n,m;
	cin >> n >> m;
	
	for(int i=n-1;i<m;i++) sum += arr[i];
	
	cout << sum << endl;
}
