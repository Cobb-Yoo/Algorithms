#include <iostream>
#include <deque>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	deque<int> arr;
	for(int i=1;i<=n;i++){ // init
		arr.push_front(i);
	}
	
	for(;;){
		if(arr.size() == 1) break;
		
		arr.pop_back();
		int tmp = arr.back();
		arr.pop_back();
		
		arr.push_front(tmp);
	}
	
	cout << arr.front() << endl;
}
