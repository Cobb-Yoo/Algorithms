#include <iostream>
using namespace std;

int main(){
	int n, answer=0;
	cin >> n;
	
	for(int tmp,i=0;i<5;i++){
		cin >> tmp;
		if(n == (tmp%10)) answer++;
	}
	
	cout << answer;
}
