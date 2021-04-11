#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
bool cmp(int a, int b){
	return a > b;
}
int main() {
	int m, n; 
	int num; 
	int cnt = 0; 
	vector<int> v1, v2; 
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v1.push_back(num);
	}
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v2.push_back(num);
	}
 
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
 
	if(v2[0] > v1[0]) cout << -1;
	else{
		while(v2.size()){
			int idx=0;
			for(int i=0;i<v2.size();i++){
				if(idx == v1.size()) break;
				
				if(v1[idx]>= v2[i]){
					idx++;
					v2.erase(v2.begin()+i);
					i--;
				}
			}
			cnt++;
		}
		cout << cnt;
	}
}
