#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
int n,m,k;

void printing(){
	for(int i=0;i<n+m;i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	cin >> n >> m >> k;	
	
	for(int i=0;i<n;i++) v.push_back('a');
	for(int i=0;i<m;i++) v.push_back('z');
	
	for(int i=0;i<k-1;i++){
		next_permutation(v.begin(),v.end());
	}
	
	printing();
}
