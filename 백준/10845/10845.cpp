#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<int> arr;
	
	int n;
	cin >> n;
	
	string line;
	for(int i=0;i<n;i++){	
		cin >> line;
		
		if(line == "push"){
			int num;
			cin >> num;
			
			arr.push(num);
		}
		else if(line == "pop"){
			if(!arr.empty()){
				cout << arr.front() << endl;
				arr.pop();
			}
			else{
				cout << -1 << endl;
			}
		}
		else if(line == "size"){
			cout << arr.size() << endl;
		}
		else if(line == "empty"){
			if(!arr.empty()){
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
		else if(line == "front"){
			if(arr.empty()){
				cout << -1 << endl;
			}
			else{
				cout << arr.front() << endl;
			}
		}
		else if(line == "back"){
			if(arr.empty()){
				cout << -1 << endl;
			}
			else{
				cout << arr.back() << endl;
			}
		}
	}
}
