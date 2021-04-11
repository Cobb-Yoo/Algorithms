#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	
	vector<int> v(n);	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	int b,c;
	cin >> b >> c;
	
	long long answer = 0;
	
	for(int i=0;i<n;i++){
		if(v[i] <= b) answer+=1;
		else if(v[i] <= b+c) answer+=2;
		else{
			if((v[i]-b)%c != 0) answer += 1 + (v[i]-b)/c +1;
			else answer += 1 + (v[i]-b)/c;
		}
	}
	
	cout << answer << endl;
}
