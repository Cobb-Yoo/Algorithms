#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 987654321;

bool arr[MAX];

int main(){
	long long n;
	cin >> n;
	
	memset(arr,1,sizeof(arr));
	
	for(int i=2;i*i <=n;i++){
		if(arr[i]){
			for(int j=i+i;j<=n;j+=i){
				arr[j] = 0;
			}
		}
	}
}
