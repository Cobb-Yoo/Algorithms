#include <bits/stdc++.h>
using namespace std;

map<string,int> Map;

int main(){
	string str;
	float total=0;
	
	cout << fixed;
	cout.precision(4);
	
	while(getline(cin, str)){
		//if(str == "gg") break;
		Map[str]++;
		total++;
	}
	
	for(auto iter:Map){
		cout << iter.first << " " << (float)iter.second/total*100 << endl;
	}
	
}
