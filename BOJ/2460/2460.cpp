#include <bits/stdc++.h>
using namespace std;

int bus;

int main(){
	int in, out;
	int answer = 0;
	for(int i=0;i<10;i++){
		cin >> out >> in;
		
		bus -= out;
		bus += in;
		
		answer = max(answer, bus);
	}
	
	cout << answer << endl;
}
