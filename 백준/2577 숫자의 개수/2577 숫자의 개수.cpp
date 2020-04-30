#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	
	cin >> a >> b >> c;
	
	long long s = a * b * c;
	int arr[10]= {0};
	
	while(s!=0){
		arr[s%10]++;
		s /= 10;
	}
	
	for(int i=0;i<10;i++){
		cout << arr[i] << endl;
	}
}
