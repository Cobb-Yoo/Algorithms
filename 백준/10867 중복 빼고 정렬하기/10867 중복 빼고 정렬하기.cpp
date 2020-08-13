#include <iostream>
#include <cstring>
using namespace std;

bool arr[2001];

int main(){
	memset(arr,0,sizeof(arr));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int tmp; cin >> tmp;
		arr[tmp+1000] = 1;
	}
	
	for(int i=0;i<=2000;i++){
		if(arr[i]) cout << i-1000 << " ";
	}
}
