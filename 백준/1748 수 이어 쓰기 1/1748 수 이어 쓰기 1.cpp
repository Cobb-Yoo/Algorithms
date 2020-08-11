#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	int answer = 0;
	int flag = 1;
	int cnt = 10;
	
	for(int i=1;i<=n;){
		if(n >= cnt){
			answer += (cnt-i)*flag;
			flag++;
			i = cnt;
			cnt *= 10;
		}
		else if(n < cnt){
			answer += (n-i+1)*flag;
			break;
		}
	}
	
	cout << answer << endl;
}
