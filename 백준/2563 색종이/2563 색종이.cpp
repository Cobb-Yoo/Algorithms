#include <iostream>
#include <cstring>
using namespace std;

bool map[100][100];

int main(){
	memset(map,0,sizeof(map));
	int n;
	int answer = 0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		
		for(int i=a;i<a+10;i++){
			for(int j=b;j<b+10;j++){
				map[i][j] = 1;
			}
		}
	}
	
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(map[i][j]) answer++;
		}
	}
	
	cout << answer << endl;
}
