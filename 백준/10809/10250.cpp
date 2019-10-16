#include <iostream>
using namespace std;

int delluna(int h,int w,int n){
	int count=0;
	int i,j;
	
	for(i=1;i<=w;i++){
		for(j=1;j<=h;j++){
			if(++count == n)break;
			
		}
		if(count == n)break;
	}
	
	return 100*j+i;
	
	
}

int main(){
	int t;
	int h,w;
	int n;
	 
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> h >> w >> n;
	
		cout << delluna(h,w,n) << endl;
	}
}
