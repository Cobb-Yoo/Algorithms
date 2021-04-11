#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<pair<int,int>> v;
	int arr[n];
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		v.push_back({tmp,i});
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0;i<n;i++) arr[v[i].second] = i;
	for(int i=0;i<n;i++) cout << arr[i] << " ";
}
