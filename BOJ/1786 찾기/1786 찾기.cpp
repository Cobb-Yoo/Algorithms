#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

string base, hook;

vector<int> getPi(){
	int len = hook.size();
	vector<int> pi(len, 0);
	
	int begin = 1;
	int matched = 0;
	
	while(begin + matched < len){
		if(hook[begin+matched] == hook[matched]){
			matched++;
			pi[begin+matched-1] = matched;
		}
		else{
			if(matched == 0) begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

vector<int> kmp(){
	int matched = 0;
	
	vector<int> pi = getPi();
	vector<int> result;
	
	int b_len = base.size();
	int h_len = hook.size();
	
	for(int i=0;i<b_len;i++){
		while(matched > 0 && base[i] != hook[matched])
			matched = pi[matched-1];
			
		if(base[i] == hook[matched]){
			matched++;
			if(matched == h_len){
				result.push_back(i-h_len+2);
				matched = pi[matched-1];
			}
		}
	}
	return result;
}

int main(){
	getline(cin, base);
	getline(cin, hook);
	
	vector<int> v = kmp();
	int len = v.size();
	cout << len << endl;
	for(int i=0;i<len;i++){
		cout << v[i] << "\n";
	}
}
