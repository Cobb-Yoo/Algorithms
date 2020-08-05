#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<string,vector<int>>> data;
int n;

bool cmp(pair<string,vector<int>> a, pair<string,vector<int>> b){
	if(a.second[0] == b.second[0]){
		if(a.second[1] == b.second[1]){
			if(a.second[2] == b.second[2]){
				return a.first < b.first;
			}
			return a.second[2] > b.second[2];
		}
		return a.second[1] < b.second[1];
	}
	return a.second[0] > b.second[0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		string name;
		vector<int> score(3);
		
		cin >> name;
		for(int i=0;i<3;i++) cin >> score[i];
		
		data.push_back({name, score});
	}
	
	sort(data.begin(), data.end(), cmp);
	
	for(int i=0;i<n;i++) cout << data[i].first << "\n";
}
