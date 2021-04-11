#include <iostream>
using namespace std;

bool map[100][100];

int main(){
	int t; cin >> t;
	
	while(t--){
		int answer = 0;
		int n,m;
		cin >> n >> m;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> map[i][j];
			}
		}
		
		for(int i=0;i<m;i++){
			int empty = n-1;
			
			for(int j=n-1;j>=0;j--){
				if(map[j][i]){
					if(empty-j == 0) empty--;
					else {
						answer += empty-j;
						empty--;
					}
				}
			}
		}
		
		cout << answer << endl;
	}
}
