#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
char option[] = {'a','e','i','o','u'};
vector<char> arr;

bool check(string s){
	int cnt = 0;
	
	for(int i=0;i<s.size();i++){
		for(int j=0;j<5;j++){
			if(s[i] == option[j]) {
				cnt++;
				break;
			}
		}
	}
	int dnt = s.size() - cnt;
	if(cnt >= 1 && dnt >= 2) return 1;
	else return 0;
}

void f(string s, int begin){
	
	if(s.size() == l){
		if(check(s)) cout << s << endl;
		return;
	}
	
	for(int i=begin;i<c;i++){
		f(s+arr[i], i+1);
	}
}

int main(){
	cin >> l >> c;
	
	for(int i=0;i<c;i++){
		char tmp;
		cin >> tmp;
		
		arr.push_back(tmp);
	}
	
	sort(arr.begin(),arr.end());
	
	f("", 0);
}
