#include <bits/stdc++.h>
using namespace std;

const int Max = 10000;
int n;
vector<pair<int,int>> v;
bool visited[Max+1];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first > b.first;
}

int main(){
	cin >> n;
	
	for(int d,p,i=0;i<n;i++){
		cin >> p >> d;
		v.push_back({p,d});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int answer = 0;
	
	for(int i=0;i<n;i++){
		for(int j=v[i].second;j>0;j--){
			if(!visited[j]){
				visited[j] = 1;
				answer += v[i].first;
				break;
			}
		}
	}
	
	cout << answer;
}
