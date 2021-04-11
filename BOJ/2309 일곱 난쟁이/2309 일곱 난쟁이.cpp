#include <iostream>
#include <algorithm> 
using namespace std;

int data[9];
int arr[7];

int main(){
	
	int tmp = 0;
	for(int i=0;i<9;i++) {
		cin >> data[i];
		tmp += data[i];
	}	
	tmp -= 100;
	
	for(int i=0;i<8;i++){
		for(int j=i+1;j<9;j++){
			if(tmp == data[i]+data[j]) {
				int cnt = 0;
				for(int k=0;k<9;k++){
					if(k==i || k==j) continue;
					arr[cnt++] = data[k];
				}
				
				goto end_loop;
			}
		}
	}
	
	end_loop:
	sort(arr,arr+7);
	for(int i=0;i<7;i++) cout << arr[i] << endl;
}
