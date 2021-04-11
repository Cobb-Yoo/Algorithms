#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int> arr;
	
	int n,m;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> m;
		if(!m && arr.empty()){
			cout << "0\n";
		}
		else if(!m){
			cout << arr.top() << "\n";
			arr.pop();
		}
		else{
			arr.push(m);
		}
	}
}
