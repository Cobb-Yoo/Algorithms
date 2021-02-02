#include <iostream>
#include <cstring>
using namespace std;

bool arr[246912+1];

void init(){
	memset(arr,1,sizeof(arr));
	arr[1] = 0;
	for(int i=2;i*i<=246912;i++){
		if(arr[i]){
			for(int j=i+i;j<=246912;j+=i){
				arr[j] = 0;
			}
		}
	}
}

int main(){
	init();
	
	int c;
	while(cin >> c && c){
		int c2 = c*2;
		
		int cnt = 0;
		
		for(int i=c+1;i<=c2;i++) if(arr[i]) cnt++;
		
		cout << cnt << endl;
	}
}
