#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
int answer=0;

void hanoi(int n, int from, int tmp, int to){
	answer++;
	
	if(n == 1) v.push_back({from, to});
	else{
		hanoi(n-1, from, to, tmp);
		v.push_back({from, to});
		hanoi(n-1, tmp, from, to);
	}
}

string getSum(string s1, string s2){
	bool flag = 0;
	
	string result = "";
	
	while(1){
		int sum = 0;
		if(!s1.empty()){
			sum += s1.back()-'0';
			s1.pop_back();
		}
		else break;
		
		if(!s2.empty()){
			sum += s2.back()-'0';
			s2.pop_back();
		}
		
		sum += flag;
		if(sum >= 10){
			flag = 1;
			sum -= 10;
		}
		else flag = 0;
		
		result.push_back(sum+'0');
	}
	
	if(flag) result.push_back('1');
	reverse(result.begin(), result.end());
	
	return result;
}

string getAnswer(string s){
	int num = s.back() - '1';
	s.pop_back();
	s.push_back(num+'0');
	
	return s;
}

int main(){
	int n; cin >> n;
	
	if(n <= 20){
		hanoi(n, 1, 2, 3);
		cout << answer << endl;
		
		for(int i=0;i<v.size();i++){
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}
	else{
		string s="1";
		for(int i=1;i<=n;i++) s = getSum(s,s);
		
		cout << getAnswer(s) << endl;
	}
}
