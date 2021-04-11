#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	
	vector<int> v(n);
	
	cin >> v[0];
	for(int i=1;i<n;i++){
		cin >> v[i];
		
		if(v[i]) v[i] = v[i-1]+1;
	}
	
	int answer = 0;
	for(int i=0;i<n;i++) answer += v[i];
	
	cout << answer << endl;
}
