#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	while(cin >> n && n != 0){	
		vector<int> num;
		int zero = 0;
		
		for(int tmp,i=0;i<n;i++){
			cin >> tmp;
			
			if(!tmp) zero++;
			else num.push_back(tmp);
		}
		
		sort(num.begin(), num.end(), cmp);
		
		string first=to_string(num.back());
		num.pop_back();
		string second=to_string(num.back());
		num.pop_back();
		
		while(zero){
			first += '0';
			zero--;
			
			if(!zero) break;
			
			second += '0';
			zero--;
		}
		
		while(!num.empty()){
			if(first.size() > second.size()){
				second += to_string(num.back());
				num.pop_back();
				if(num.empty()) break;
				
				first += to_string(num.back());
				num.pop_back();
			}
			else {
				first += to_string(num.back());
				num.pop_back();
				if(num.empty()) break;
				
				second += to_string(num.back());
				num.pop_back();
			}
		}
		
		cout << stoi(first)+stoi(second) << endl;
	}
}
