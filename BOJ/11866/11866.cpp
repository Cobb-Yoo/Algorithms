#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	queue<int> arr;
	for(int i=1;i<=n;i++) arr.push(i);
	
	cout << '<';
	for(;;){
		if(arr.size() == 1) break;
		
		for(int i=0;i<m-1;i++){
			arr.push(arr.front());
			arr.pop();
		}
		cout << arr.front();
		arr.pop();
		
		if(!arr.empty()){
			cout << ", ";
		}
	}
	cout << arr.front();
	cout << '>' << endl;
}
