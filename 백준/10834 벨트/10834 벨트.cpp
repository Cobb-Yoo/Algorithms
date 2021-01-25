#include <iostream>
using namespace std;

int main(){
	int m; cin >> m;
	
	float torque = 1;
	bool rotation = 0;
	float a,b;
	bool c;
	
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		
		if(c) rotation = !rotation;
		
		torque = (torque/a)*b;
	}
	
	cout << rotation << " " << torque << endl;
}
