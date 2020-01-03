#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num_arr[100];
int oper_arr[4];//+,-,*,/의 순서를 가지고 있음. 
int Max = -1000000001;
int Min = 1000000001;
int result;

void function(int x){
	if(x == n-1){
		Max = max(result, Max);
		Min = min(result, Min);
		return;
	}
	else{
		for(int i=0;i<4;i++){
			if(oper_arr[i] == 0) continue;
			
			int tmp = result;
			
			if(i == 0){
				result += num_arr[x+1];
				oper_arr[i]--;
				function(x+1);
				oper_arr[i]++;
				result = tmp;
			}
			else if(i == 1){
				result -= num_arr[x+1];
				oper_arr[i]--;
				function(x+1);
				oper_arr[i]++;
				result = tmp;
			}
			else if(i == 2){
				result *= num_arr[x+1];
				oper_arr[i]--;
				function(x+1);
				oper_arr[i]++;
				result = tmp;
			}
			else if(i == 3){
				result /= num_arr[x+1];
				oper_arr[i]--;
				function(x+1);
				oper_arr[i]++;
				result = tmp;
			}
		}
	}
}


int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> num_arr[i];
	}
	
	for(int i=0;i<4;i++){
		cin >> oper_arr[i];
	}
	
	result = num_arr[0];
	function(0);
	
	cout << Max << " " << Min << endl;
}
