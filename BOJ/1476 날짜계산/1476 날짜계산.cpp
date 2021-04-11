#include <iostream> 
using namespace std;

int e,s,m;

int main(){
	cin >> e >> s >> m;
	int answer = 1;
	
	while(1){
		if((answer-e)%15==0 && (answer-s)%28 == 0 && (answer-m)%19==0) break;
		answer++;
	}
	
	cout << answer << endl;
}
