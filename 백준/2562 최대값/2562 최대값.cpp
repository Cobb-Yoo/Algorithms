#include <iostream> 
using namespace std;

int main(){
	int max = 0;
	int a;
	for(int i=1;i<10;i++){
		int n;
		cin >> n;
		if(max < n) {
			max = n;
			a = i;
		}
	}
	
	cout << max << endl << a << endl;
}
