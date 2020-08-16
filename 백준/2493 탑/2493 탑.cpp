#include <iostream>
#include <stack>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<pair<int,int>> s;
	int n; cin >> n;
	int data;
	
	for(int i=1;i<=n;i++){
		cin >> data;
		while(!s.empty()){
			if(s.top().second > data){
				cout << s.top().first << " ";
				break;
			}
			s.pop();
		}
		if(s.empty()) cout << "0 ";
		s.push({i,data});
	}
}
