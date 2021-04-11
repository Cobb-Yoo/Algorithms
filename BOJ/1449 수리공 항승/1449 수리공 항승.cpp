#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[1001];
vector<int> v;
int answer = 0;
int n, m;

void taping(int t){
	if(arr[t]) return;
	
	answer++;
	for(int i=t;i < min(t+m, 1001);i++) arr[i] = true;
}
 
int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	
	for(int i=0;i<n;i++) taping(v[i]);
	
	cout << answer << endl;
}
