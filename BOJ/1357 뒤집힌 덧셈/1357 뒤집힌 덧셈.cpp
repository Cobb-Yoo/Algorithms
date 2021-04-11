#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int rev(int n){
	while(n){
		q.push(n%10);
		n /= 10;
	}
	
	n = q.front();
	q.pop();
	
	while(!q.empty()){
		n = n*10 + q.front();
		q.pop();
	}
	
	return n;
}

int main(){
	int x,y;
	cin >> x >> y;
	
	cout << rev(rev(x)+rev(y)) << endl;
}

