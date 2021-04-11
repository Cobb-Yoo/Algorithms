#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		int s = tmp*tmp;
		
		bool flag = true;
		while(tmp>0){
			if(tmp%10 != s % 10){
				flag = false;
				break;
			}
			tmp /= 10;
			s /= 10;
		}
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
}
