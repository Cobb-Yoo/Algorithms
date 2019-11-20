#include <iostream>
#include <deque>
using namespace std;

int main(){
	deque<int> arr;
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		string line;
		cin >> line;
		
		if(line=="push_back"){
			int num;
			cin >> num;
			
			arr.push_back(num);
		}
		else if(line == "push_front"){
			int num;
			cin >> num;
			
			arr.push_front(num);
		}
		else if(line == "pop_front"){
			if(arr.empty()) cout << -1 << endl;
			else {
				cout << arr.front() << endl;
				arr.pop_front();
			}
		}
		else if(line == "pop_back"){
			if(arr.empty()) cout << -1 << endl;
			else {
				cout << arr.back() << endl;
				arr.pop_back();
			}			
		}
		else if(line == "size"){
			cout << arr.size() << endl;
		}
		else if(line == "empty"){
			if(arr.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if(line == "front"){
			if(arr.empty()) cout << -1 << endl;
			else cout << arr.front() << endl;
		}
		else if(line == "back"){
			if(arr.empty()) cout << -1 << endl;
			else cout << arr.back() << endl;
		}
	}
}
