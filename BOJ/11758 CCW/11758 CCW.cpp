#include <iostream>
using namespace std;

int main(){
	int x[3];
	int y[3];
	
	for(int i=0;i<3;i++){
		cin >> x[i] >> y[i];
	}
	
	int a[2] = {y[1]-y[0],x[1]-x[0]};
	int b[2] = {y[2]-y[0],x[2]-x[0]};
	
	int result = a[0]*b[1] - a[1]*b[0];
	
	if(result > 0) cout << -1;
	else if (result < 0) cout << 1;
	else cout << 0;
}
