#include <iostream>
#include <string>
using namespace std;

string arr;
string brr;
int lena;
int lenb;
int answer = 0;

void check(int &n) {
	for(int i=n;i<n+lenb;i++) if(arr[i] != brr[i-n]) return;
	n += lenb-1;
	answer++;
}

int main(){
	getline(cin, arr);
	getline(cin, brr);
	
	lena = arr.size();
	lenb = brr.size();
	
	int len = lena - lenb;
	
	if(lena >= lenb) for(int i=0;i<=len;i++) check(i);
	
	cout << answer << endl;
}
