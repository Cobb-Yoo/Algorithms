#include <iostream>
using namespace std;

int main(){
	int t,m,n,x,y;	
	cin >> t;
	
	for(int i=0;i<t;i++){
        int flag=1;
		cin >> m >> n >> x >> y;
		for(int j=0;j<m;j++){
		    if((n*j+y-x)%m == 0) {
                cout << n*j+y << endl;
                flag=0;
                break;
            }
        }
        if(flag) cout << -1 << endl;
	}
}
