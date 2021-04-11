#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int a;
	cin >> a;
	vector<int> arr;
	
	for(int i=0;i<a;i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(), arr.end());
	
	int b;
	cin >> b;
	
	for(int i=0;i<b;i++){
		int tmp;
		cin >> tmp;
		
		cout << upper_bound(arr.begin(),arr.end(),tmp)-lower_bound(arr.begin(),arr.end(),tmp) << " ";
	}
}
