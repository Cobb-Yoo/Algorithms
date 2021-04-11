#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<string> v(n);
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	int len = v[0].size();
	
	vector<char> answer;
	for(int i=0;i<len;i++){
		bool flag = true;
		for(int j=0;j<n-1;j++){
			if(v[j][i] != v[j+1][i]) {
				answer.push_back('?');
				flag = false;
				break;	
			}
		}
		
		if(flag) answer.push_back(v[0][i]);
	}
	
	for(int i=0;i<len;i++) cout << answer[i];
}
