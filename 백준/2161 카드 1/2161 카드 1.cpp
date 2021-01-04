#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main(){
	int n; cin >> n;
	
	for(int i=1;i<=n;i++) q.push(i);
	
	while(!q.empty()){
		cout << q.front() << endl;
		q.pop();
		
		q.push(q.front());
		q.pop();
	}
}
