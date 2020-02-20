#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
	cin.sync_with_stdio(false);
    
	queue<int> arr;
	int n;
	string tmp;
	
	cin >> n;
	
	while(n--){
		cin >> tmp;
		
		if(tmp == "push"){
			int tmp_n;
			cin >> tmp_n;
			arr.push(tmp_n);
		}
		else if(tmp == "pop"){
			if(!arr.empty()){
				cout << arr.front() << "\n";
				arr.pop();
			}else{
				cout << "-1\n";
			}
		}
		else if(tmp == "size"){
			cout << arr.size() << "\n";
		}
		else if(tmp == "empty"){
			cout << arr.empty() << "\n";
		}
		else if(tmp == "front"){
			if(!arr.size()){
				cout << "-1\n";
			}
			else{
				cout << arr.front() << "\n";
			}
		}
		else if(tmp == "back"){
			if(!arr.size()){
				cout << "-1\n";
			}
			else{
				cout << arr.back() << "\n";
			}
		}
	}
}
