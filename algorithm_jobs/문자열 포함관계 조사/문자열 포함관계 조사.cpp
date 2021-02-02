#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	cin >>a >> b;
	
	if(a.size() < b.size()) {
		cout << "NO";
		return 0;
	}
	
	int a_len = a.size();
	int b_len = b.size();
	
	for(int i=0;i<a_len;i++){
		if(a[i] == b[0]){
			int j;
			for(j=i;j<b_len+i;j++){
				if(j >= a_len){
					break;
				}
				else if(a[j] != b[j-i]){
					break;
				}
			}
			
			if(j == b_len+i){
				cout << "YES";
				return 0;
			}
		}
	}
	
	cout << "NO";
}
