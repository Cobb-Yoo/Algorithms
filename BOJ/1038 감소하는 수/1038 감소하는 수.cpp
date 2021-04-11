#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000000;

queue<long long> q;
int n;
int idx = 9;
long long arr[MAX+1];

void cal(){
	while(idx <=n){
		if(q.empty()) return;
		
		long long tmp = q.front();
		q.pop();
		
		int num = tmp%10;
		
		for(int i=0;i<num;i++){
			q.push(tmp*10+i);
			arr[++idx] = tmp * 10 + i;
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=1;i<=9;i++) {
		q.push(i);
		arr[i] = i;
	}
	
	cal();
	
	if(!arr[n] && n) cout << -1 << endl;
	else cout << arr[n] << endl;
}
