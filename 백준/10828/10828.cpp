#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	string line;
	int num;
	int top = -1;
	
	int arr[10000];
	
	for(int i=0;i<n;i++){
		cin >> line;
		
		if(line == "push") {
			cin >> num;
			arr[++top] = num;
		}
		else if(line == "pop") {
			if(top > -1 ){
				 cout << arr[top--] << endl;
			}
			else cout << -1 << endl;
		}
		else if(line == "size"){
			cout << top+1 << endl;
		}
		else if(line == "empty"){
			if(top == -1) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if(line == "top"){
			if(top != -1) cout << arr[top] << endl;
			else cout << -1 << endl;
			
		}
		else break;
	}
}
