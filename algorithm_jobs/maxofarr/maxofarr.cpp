#include <iostream>
using namespace std;

int main(){
	int Max = 0,y,x;
	for(int tmp,i=1;i<10;i++){
		for(int j=1;j<10;j++){
			cin >> tmp;
			
			if(Max < tmp){
				Max = tmp;
				y = i;
				x = j;
			}
		}
	}
	cout << Max << endl << y << " " << x;
}
