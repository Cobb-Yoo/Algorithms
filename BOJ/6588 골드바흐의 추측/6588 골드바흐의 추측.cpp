#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool arr[1000001];
vector<int> v;

void check(int n){
	for(int i=0;;i++){
		if(arr[n-v[i]]){
			cout << n << " = " << v[i] << " + " << n-v[i] << "\n";
			return;
		}
	}
	
	cout << "Goldbach's conjecture is wrong.\n";
}

void init(){
	memset(arr,1,sizeof(arr));
	
	for(int i=2;i*i<=1000000;i++){
		if(arr[i]){
			for(int j=i+i;j<=1000000;j+=i){
				arr[j] = 0;
			}
		}
	}
	
	for(int i=2;i<=1000000;i++){
		if(arr[i]) v.push_back(i);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	
	int n;
	
	while(cin >> n && n != 0){
		check(n);
	}
}
