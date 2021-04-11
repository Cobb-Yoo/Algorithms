#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	
	string tmp;
	map<string, int> mp;
	string arr[n+1];
	
	for(int i=1;i<=n;i++){
		cin >> tmp;
		mp.insert({tmp, i});
		arr[i] = tmp;
	}
	
	for(int i=0;i<m;i++){
		cin >> tmp;
		
		if(tmp[0] >= 'A') cout << mp[tmp] << '\n';
		else cout << arr[stoi(tmp)] << '\n';
	}
}
