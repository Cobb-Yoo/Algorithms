#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n+1]={0};
	int tmp[n+1]={0};
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}

	int MAX=0;
	
	for(int i=1;i<=n;i++){
		int max=0;
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j]){
				if(max < tmp[j])
					max = tmp[j];
			}
		}
		tmp[i] = max + 1;
		if(MAX < tmp[i])
			MAX = tmp[i];
	}
	
	cout << "test ";
	for(int i=0;i<=n;i++){
		cout << tmp[i] << ' ';
	}
	cout << endl;
	
	cout << MAX << endl;
}
