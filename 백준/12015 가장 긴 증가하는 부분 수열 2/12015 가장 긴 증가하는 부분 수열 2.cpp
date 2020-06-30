#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> v;
	v.push_back(0);
	int cnt = 0;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		if(tmp > v.back()) {
			v.push_back(tmp);
			cnt++;
		}
		else{
			vector<int>::iterator low = lower_bound(v.begin(), v.end(), tmp);
			*low = tmp;
		}
	}
	
	cout << cnt << endl;
}
