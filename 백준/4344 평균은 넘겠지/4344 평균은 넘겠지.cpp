#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		
		double avg = 0;
		int arr[m];
		
		for(int j=0;j<m;j++){
			cin >> arr[j];
			avg += arr[j];
		}
		
		avg /= (double)m;
		
		int cnt = 0;
		for(int j=0;j<m;j++) if(avg < arr[j]) cnt++;
		
		printf("%.3f%\n", (double)cnt/m * 100);
	}
}
