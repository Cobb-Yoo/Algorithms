#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[100001] ={0};
	int top = -1;
	
	int tmp;
	
	for(int i=0;i<n;i++){
		cin >> tmp;
		if(tmp != 0) arr[++top] = tmp;
		else top--;
	}
	
	int sum = 0;
	
	for(int i=0;i<=top;i++){
		sum += arr[i];
	}
	
	top == -1? cout << 0 << endl:cout << sum << endl;
}
