#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int avg=0;
	
	int arr[n];
	int list[8001]={0};
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
		avg += arr[i];
		list[arr[i]+4000]++;
	}
	
	sort(arr,arr+n);
	
	if(avg >0 ){
		avg = (avg + 0.5*n)/ n;
	}
	else {
		avg = (avg-0.5*n) / n;
	}
	
	cout << ",,,,,,,,,,\n";
	
	cout << avg << endl;
	cout << arr[n/2] << endl;
	
	int num = -1;
    int cur = 0;
    bool second = false;
    for(int i=0; i <= 8000; i++)
        if (cur < list[i]){
	        cur = list[i];
            num = i;
            second = false;
		}

		else if (cur == list[i] && !second){
			num = i;
			second = true;
		}
	cout << num-4000 << endl;
		
	cout << arr[n-1]- arr[0] << endl;
}
