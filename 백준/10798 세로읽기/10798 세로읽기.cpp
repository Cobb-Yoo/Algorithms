#include <iostream>
#include <string>
using namespace std;

const int MAX = 15;
char arr[MAX][MAX];

int main(){
	string answer = "";
	
	int len = 0;
	for(int i=0;i<5;i++){
		
		cin >> arr[i];
		string s = arr[i];
		int a = s.size();
		len = max(len, a);
	}
	
	for(int i=0;i<len;i++){
		for(int j=0;j<5;j++){
			string tmp = arr[j];
			if(i >= tmp.size()) continue;
			cout << arr[j][i];
		}
	}
	
	cout << answer << endl;
}
