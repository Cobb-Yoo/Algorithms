#include <iostream>
#include <string>
using namespace std;

int getTime(char a, char b){
	if(a == b) return 0;
	
	if(a > b) {
		char tmp = a;
		a = b;
		b = tmp;
	}
	
	if(b-a > 26-b+a) return 26-b+a;
	else return b-a;
}

int main(){
	string str; cin >> str;
	int len = str.size();
	
	int cnt=0;
	int ans = getTime('A', str[0]);
	
	for(int i=1;i<len;i++){
		int tmp = getTime(str[i-1], str[i]);
		ans += tmp;
	}
	
	cout << ans;
}
