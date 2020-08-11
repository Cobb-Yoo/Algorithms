#include <iostream>
using namespace std;

char map[100][100];
int n;

int col(){
	int result = 0;
	
	for(int i=0;i<n;i++){
		int cnt = 0;
		
		for(int j=0;j<n;j++){
			if(map[i][j] == '.') cnt++;
			else if(map[i][j] == 'X' && cnt >= 2){
				result++;
				cnt = 0;
			}
			else if(map[i][j] == 'X'){
				cnt = 0;
			}
		}
		
		if(cnt >= 2) result++;
	}
	
	return result;
}

int row(){
	int result = 0;
	
	for(int i=0;i<n;i++){
		int cnt = 0;
		
		for(int j=0;j<n;j++){
			if(map[j][i] == '.') cnt++;
			else if(map[j][i] == 'X' && cnt >= 2){
				result++;
				cnt = 0;
			}
			else if(map[j][i] == 'X'){
				cnt = 0;
			}
		}
		
		if(cnt >= 2) result++;
	}
	
	return result;
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> map[i];
	
	cout << col() << " " << row() << endl;
}
