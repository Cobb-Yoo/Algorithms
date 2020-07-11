#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr['Z'+1];

int main(){
	memset(arr,0,sizeof(arr));
	int alright=0, penalty=0;
	
	int n;
	while(cin >> n && n != -1){
		char problem;
		string result;
		
		cin >> problem >> result;
		
		if(result == "right") {
			alright++;
			penalty += arr[problem]*20 + n;
		}
		else arr[problem]++;
	}
	
	cout << alright << " " << penalty << endl;
}
