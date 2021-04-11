#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n,m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		string tmp; cin >> tmp;
		
		for(int j=0;j<tmp.size();j++){
			v[i] |= 1 << (tmp[j]-'a');
		}
	}
	
	int mask = 0x3ffffff;
	
	int flag;
	char ch;
	
	while(m--){
		cin >> flag >> ch;
		
		if(flag == 1) mask &= ~(1 << (ch - 'a'));
		else mask |= (1 << (ch - 'a'));
		
		int cnt = 0;
		for(int i=0;i<n;i++){
			if((mask & v[i]) == v[i]) cnt++;
		}
		cout << cnt << "\n";
	}
	
	
}
