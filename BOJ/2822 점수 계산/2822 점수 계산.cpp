#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}

int main(){
	vector<int> answer;
	vector<pair<int,int>> list;
	
	for(int i=1;i<9;i++){
		int score;
		cin >> score;
		
		list.push_back({i, score});
	}
	
	sort(list.begin(), list.end(), cmp);
	
	for(int i=0;i<5;i++) answer.push_back(list[i].first);
	
	sort(answer.begin(), answer.end());
	
	int sum = 0;
	for(int i=0;i<5;i++){
		sum += list[i].second;
	}
	
	cout << sum << endl;
	for(int i=0;i<5;i++) cout << answer[i] << " ";
}
