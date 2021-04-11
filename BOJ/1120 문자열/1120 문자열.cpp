#include <iostream> 
#include <string>
#include <algorithm>
using namespace std;

int getlen(string a, string b, int n){
	int cnt=0;
	int len = a.size();
	
	for(int i=0;i<len;i++) if(a[i] != b[i+n]) cnt++;
	return cnt;
}

int main(){
	int answer = 50;
	string a, b;
	cin >> a >> b;
	
	int len = b.size()-a.size();
	
	for(int i=0;i<=len;i++) answer = min(getlen(a,b,i), answer);
	
	cout << answer << endl;
}
