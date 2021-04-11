#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[10] = {0};
	
	while(1){
		arr[n%10]++;
		if(n/10 == 0) break;
		n/=10;
	}
	
	int num = 0;
	for(int i=0;i<10;i++) if(i!=9 && i!=6) num = max(num,arr[i]);
	
	cout << max(num, (arr[9]+arr[6]+1)/2) << endl;
}
