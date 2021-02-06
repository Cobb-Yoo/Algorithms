#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> input;
vector<string> answer;
int n;

void solve(){
	for(int tmp,i=1;i<10;i++){
		for(int j=1;j<10;j++){
			if(i==j) continue;
			for(int k=1;k<10;k++){
				if(i==k || j==k) continue;
				
				answer.push_back(to_string(i*100 + j*10 + k)); 
			}
		}
	}
	
	for(int i=0;i<n;i++){
		string str = to_string(input[i][0]);
		
		for(int j=answer.size()-1;j>=0;j--){
			int strike=0, ball=0;
			
			for(int k=0;k<3;k++){
				if(str[k] == answer[j][k]) strike++;
				else if(str[k] == answer[j][(k+1)%3] || str[k] == answer[j][(k+2)%3]) ball++;
			}
			
			if(strike != input[i][1] || ball != input[i][2]) answer.erase(answer.begin()+j);
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int num,j=0;j<3;j++){
			cin >> num;
			tmp.push_back(num);
		}
		input.push_back(tmp);
	}
	
	solve();
	
	cout << answer.size();
}
