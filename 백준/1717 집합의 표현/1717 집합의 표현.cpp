#include <iostream>
#include <queue> 
using namespace std;

queue<int> q;
int arr[1000001];

int find(int n){
	if(arr[n] < 0) {
		while(!q.empty()){
			arr[q.front()] = n;
			q.pop();
		}
		return n;
	}
	else {
		q.push(n);
		return n = find(arr[n]);
	}
}

void unioon(int a, int b){
	if(find(a) == find(b)) return;
	
	if(arr[a] < arr[b]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	arr[a] += arr[b];
	arr[b] = a;
}

int main(){
	//0 : 합집합 
	//1 : 포함 확인 연산
	
	int n,m;
	cin >> n >> m;
	
	
	for(int i=0;i<=n;i++) arr[i] = -1;
	
	for(int i=0;i<m;i++){
		int flag, a, b;
		
		cin >> flag >> a >> b;
		
		if(flag == 1) {
			if(a == b) cout << "YES\n";
			else if(find(a)==find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			if(a == b) continue;
			unioon(a, b);
		}
	}
}
