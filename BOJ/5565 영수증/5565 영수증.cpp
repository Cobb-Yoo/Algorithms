#include <iostream>
using namespace std;

int main(){
	int answer;
	cin >> answer;
	
	for(int i=0;i<9;i++){
		int tmp; cin >> tmp;
		answer -= tmp;
	}
	
	cout << answer << endl; 
}
