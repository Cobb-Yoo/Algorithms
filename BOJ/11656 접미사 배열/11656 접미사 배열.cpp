#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string s; cin >> s;
	
	vector<string> answer;
	int len = s.size();
	for(int i=0;i<len;i++) answer.push_back(s.substr(i,len));
	
	sort(answer.begin(),answer.end());
	
	for(int i=0;i<len;i++) cout << answer[i] << "\n";
}
