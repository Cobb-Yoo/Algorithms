#include <iostream>
#include <string>
#include <vector> 
using namespace std;

int main(){
	int t;
	cin >> t;
	
	for(int T=0;T<t;T++){
		int n;
		vector<pair<string,int>> v;
		cin >> n;
		
		int answer = 1;
		for(int i=0;i<n;i++){
			string a,b;
			cin >> a >> b;
			
			bool flag = true;
			for(int j=0;j<v.size();j++){
				if(v[j].first == b){
					v[j].second++;
					flag = false;
					break;
				}
			}
			
			if(flag) v.push_back({b, 1});
		}
		
		for(int i=0;i<v.size();i++) answer *= v[i].second+1;	
		cout << answer-1 << endl;
	}
}
