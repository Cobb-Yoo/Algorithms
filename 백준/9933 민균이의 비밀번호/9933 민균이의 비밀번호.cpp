#include <iostream>
#include <string>
#include <cstring>
#include <algorithm> 
using namespace std;

bool flag[100];
string srr[100];

int main(){
	memset(flag,0,sizeof(flag));
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> srr[i];
	
	for(int i=0;i<n;i++){
		string tmp = srr[i];
		
		reverse(tmp.begin(), tmp.end());
		
		if(tmp == srr[i]){
			cout << tmp.length() << " " << tmp[tmp.length()/2] << endl;
			return 0;
		}
		
		for(int j=0;j<n;j++){
			if(i==j) continue;
			
			if(tmp == srr[j]){
				cout << tmp.length() << " " << tmp[tmp.length()/2] << endl;
				return 0;
			}
		}
	}
}
