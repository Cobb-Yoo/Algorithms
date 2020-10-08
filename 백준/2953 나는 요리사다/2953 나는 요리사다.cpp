#include <iostream>
using namespace std;

int main(){
	int idx;
	int m = 0;
	
	for(int i=1;i<=5;i++){
		int sum = 0;
		for(int j=0;j<4;j++){
			int tmp; cin >> tmp;
			
			sum += tmp;
		}
		
		if(m < sum){
			idx = i;
			m = sum;
		}
	}
	
	cout << idx << " " << m << endl;
}
