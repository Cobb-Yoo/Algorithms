#include <iostream>
using namespace std;

int cnt=0;

void f(int n,int m){
	if(n > m) n^=m^=n^=m;
	
	if(m==1) return;
	else cnt++;

	if(m&1){
		f(n,m/2);
		f(n,m/2+1);
	}else{
		f(n,m/2);
		f(n,m/2);
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	
	f(n,m);
	
	cout << cnt << endl;
}
