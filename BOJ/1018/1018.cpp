#include <iostream>
#include <string>
using namespace std;

string arr[51];
int result = 50;
int hor,val;

int white(int a,int b){
	int cnt=0;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j%2){
				if(i%2){
					if(arr[a+i][b+j] == 'W') continue;
					else cnt++;
				}
				else{
					if(arr[a+i][b+j] == 'B') continue;
					else cnt++;
				}
			}
			else{
				if(i%2){
					if(arr[a+i][b+j] == 'B') continue;
					else cnt++;
				}
				else{
					if(arr[a+i][b+j] == 'W') continue;
					else cnt++;
				}
			}
		}
	}
	return cnt;
}

int black(int a, int b){
	int cnt=0;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(j%2){
				if(i%2){
					if(arr[a+i][b+j] == 'B') continue;
					else cnt++;
				}
				else{
					if(arr[a+i][b+j] == 'W') continue;
					else cnt++;
				}
			}
			else{
				if(i%2){
					if(arr[a+i][b+j] == 'W') continue;
					else cnt++;
				}
				else{
					if(arr[a+i][b+j] == 'B') continue;
					else cnt++;
				}
			}
		}
	}
	return cnt;
}


void check(int a,int b){
	for(int i=0;i+7<val;i++){
		for(int j=0;j+7<hor;j++){
			result = min(result, min(white(i,j),black(i,j)));
		}
	}
}

int main(){
	cin >> val >> hor;
	
	for(int i=0;i<val;i++){
		cin >> arr[i];
	}
	
	check(0,0);
	
	cout << result << endl;
}
