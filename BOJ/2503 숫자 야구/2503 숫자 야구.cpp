#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> answer;
bool visited[10]={0,};

void dfs(int idx, string tmp){
	tmp += to_string(idx);
	
	if(tmp.size() == 3){
		answer.push_back(tmp);
		return;
	}
	
	 for(int i=1;i<=9;i++){
        if(!visited[i]){
        	visited[i] = 1;
            dfs(i, tmp);
            visited[i] = 0;
        }
    }
}

pair<int,int> getScore(string s, string num) {
	int strike = 0, ball = 0;
	
	for(int i=0;i<3;i++){
		if(s[i] == num[i]) strike++;
		else if(find(s.begin(), s.end(), num[i]) != s.end()) ball++;
	}
	
	return {strike, ball};
}

int main(){
	for(int i=1;i<=9;i++) {
		visited[i] = 1;
        dfs(i, "");
        visited[i] = 0;
	}
	
	
	for(int i=0;i<10;i++){
		vector<string> tmp;
		int num, s,b;
		cin >> num >> s >> b;
		
		for(int j=0;j<answer.size();j++){
			pair<int,int> score = getScore(answer[j], to_string(num));
			
			if(s == score.first && b == score.second) tmp.push_back(answer[j]);
		}
		
		answer = tmp;
	}
	
	cout << answer.size() << endl;
}
