#include <iostream>
using namespace std;

int main(){
	int sum=0;
	
	for(int tmp,i=0;i<5;i++){
		cin >> tmp;
		sum += tmp*tmp;
	}
	
	cout << sum%10;
}
