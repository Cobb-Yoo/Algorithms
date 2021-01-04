#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector<int> p;
vector<int> m;

bool cmp(int a, int b){
	return a > b;
}


int main(){
	int n; cin >> n;
	
	ll answer = 0;
	for(int i=0;i<n;i++){
		int tmp; cin >> tmp;
		
		if(tmp == 1){
			answer+=1;
			continue;
		}
		
		if(tmp>0) p.push_back(tmp);
		else m.push_back(tmp);
	}
	
	sort(p.begin(), p.end(), cmp);
	sort(m.begin(), m.end());
	
	
	int plen = p.size();
	int mlen = m.size();
	
	if((plen&1)){
		for(int i=0;i<plen-1;i+=2){
			answer += p[i]*p[i+1];
		}
		answer += p[plen-1];
	}
	else{
		for(int i=0;i<plen;i+=2){
			answer += p[i]*p[i+1];
		}
	}
	
	if((mlen&1)){
		for(int i=0;i<mlen-1;i+=2){
			answer += m[i]*m[i+1];
		}
		answer += m[mlen-1];
	}
	else{
		for(int i=0;i<mlen;i+=2){
			answer += m[i]*m[i+1];
		}
	}
	
	cout << answer << endl;
}
