#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int n;
	while(cin >> n && n != 0){
		vector<int> v;
		stack<int> s;
		ll area = 0;
		
		for(int tmp,i=0;i<n;i++){
			cin >> tmp;
			v.push_back(tmp);
		}
		
		for(int i=0;i<n;i++){
			while(!s.empty() && v[s.top()] > v[i]){
				ll height = v[s.top()];
				ll width = i;
				s.pop();
				
				if(!s.empty()) width = i - s.top() -1;
				if(width*height > area) area = width*height;
			}
			s.push(i);
		}
		
		while(!s.empty()){
			ll height = v[s.top()];
			int idx = s.top();
			s.pop();
			ll width = n;
			
			if(!s.empty()) width = n - s.top() -1;	
			
			if(width*height > area) area = width*height;
		}
		
		cout << area << endl;
	}
}
