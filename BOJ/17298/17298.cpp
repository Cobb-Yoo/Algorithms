#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<int> v;
int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	
	cin >> n;
	
	for(int tmp, i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<int> ans(n, -1);
	
	for(int i=0;i<n;i++){
		while(!s.empty() && v[s.top()] < v[i]){
			ans[s.top()] = v[i];
			s.pop();
		}
		
		s.push(i);
	}
	
	for(int i=0;i<n;i++){
		cout << ans[i] << " ";
	}
}
