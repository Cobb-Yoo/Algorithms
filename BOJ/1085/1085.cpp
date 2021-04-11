#include <iostream>
using namespace std;

int main(){
	int x,y,w,h;
	int a[4];
	
	cin >> x >> y >> w >> h;
	
	a[0] = w - x;
	a[1] = x;
	a[2] = h - y;
	a[3] = y;
	
	int min=a[0];
	
	for(int i=1;i<4;i++){
		if(min > a[i]) min = a[i];
	}
	
	cout << min << endl;
}
