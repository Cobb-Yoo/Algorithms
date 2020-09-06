#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n,m,v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> v;
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		
		arr.push_back(num);
	}
	
	int dormammu = n-v+1;
	
	for(int i=0;i<m;i++){
		int num; cin >> num;
		
		if(num <= v-1) cout << arr[num] << "\n";
		else{
			num -= (v-1);
			num %= dormammu;
			num += (v-1);
			
			cout << arr[num] << "\n";
		}
	}
}
