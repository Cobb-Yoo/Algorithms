#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,s,r;
bool broken[11];
vector<int> w;

int main(){
	cin >> n >> s >> r;
	
	for(int tmp,i=0;i<s;i++){
		cin >> tmp;
		broken[tmp] = 1;
	}
	
	for(int tmp,i=0;i<r;i++){
		cin >> tmp;
		w.push_back(tmp);
	}
	
	sort(w.begin(), w.end());
	
	int ans = s;
	
	for(int i=0;i<r;i++){
		if(broken[w[i]]){
			broken[w[i]] = 0;
			ans--;
		}
		else if(broken[w[i]-1]){
			broken[w[i]-1] = 0;
			ans--;
		}
		else if(broken[w[i]+1]){
			broken[w[i]+1] = 0;
			ans--;
		}
	}
	
	cout << ans;
}
