#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 20000000;
const int h = 10000000;
bool arr[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(arr,0,sizeof(arr));
	
	int n, m;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		arr[tmp+h] = 1;
	}
	
	cin >> m;
	for(int i=0;i<m;i++){
		int tmp;
		cin >> tmp;
		
		if(arr[tmp+h]) cout << "1 ";
		else cout << "0 ";
	}
}
