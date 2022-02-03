#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	
	string a, b;
	int tmp;
	while(n--){
		cin >> a >> b;
		int len = a.length()-1;
		
		cout << "Distances: ";
		for(int i=0;i<len;i++){
			tmp = b[i] - a[i];
			if(tmp < 0){
				tmp += 26;
			}
			cout << tmp << " ";
		}
		
		tmp = b[len]-a[len];
		if(tmp < 0){
				tmp += 26;
		}
		
		cout << tmp << endl;
	}
}
