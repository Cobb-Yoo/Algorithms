#include <iostream>
#include <map>
#include <string>
using namespace std;

const int MAX = 100000+1;
int n,m;
map<string, string> maP;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		maP.insert({tmp1,tmp2});
	}
	
	for(int i=0;i<m;i++){
		string tmp; cin >> tmp;
		cout << maP[tmp] << "\n";
	}
}
