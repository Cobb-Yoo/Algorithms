#include <iostream>
using namespace std;

int main(){
	int n,m,k;
	
	cin >> n >> m >> k;
	
	int answer = 0;
	int limit = n + m - k;
	
	while(true){
		int female = answer * 2;
		int men = answer;
		if(limit < female+men || female > n || men > m) break;
		answer++;
	}
	
	cout << answer-1 << endl;
}
