#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	
	while(cin >> t && t != -1){
		
		int tmp = 0;
		vector<int> arr;  
		
		for(int i=1;i<=t/2;i++){
			if(t%i == 0) {
				tmp += i;
				arr.push_back(i);
			}
		}
		
		if(tmp == t) {
			cout << t << " = ";
			for(int i=0;i<arr.size()-1;i++) cout << arr[i] << " + ";
			cout << arr.back() << endl;
		}
		else cout << t << " is NOT perfect.\n";
	}
	return 0;
}
