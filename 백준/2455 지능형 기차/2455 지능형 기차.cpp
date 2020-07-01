#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int people = 0;
	int answer = 0;
	
	for(int i=0;i<4;i++){
		int a, b;
		cin >> a >> b;
		
		people = people - a + b;
		answer = max(answer, people);
	}
	
	cout << answer;
}
