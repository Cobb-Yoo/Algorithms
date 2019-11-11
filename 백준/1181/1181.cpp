#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	if(a.length() != b.length()){
		return a.length() < b.length();
	}
	return a < b;
}

main(){
	int n;
	cin >> n;
	
	string arr[n+1];
	arr[0] = " ";
	for(int i=1;i<=n;i++){
		cin >>arr[i];
	}
	
	sort(arr+1, arr+n+1, cmp);
	
	for(int i=1;i<=n;i++){
		if(arr[i] != arr[i-1])
			cout << arr[i] << endl;
	}
}
