#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
string str;

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		if(i < m) str += '1';
		else str += '0';
	}
	
	do{
		cout << str << endl;
	}while(prev_permutation(str.begin(), str.end()));
}
