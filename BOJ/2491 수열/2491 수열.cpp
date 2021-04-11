#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100001;
int cl_arr[MAX];
int decl_arr[MAX];
int n;
int arr[MAX];

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	
	memset(cl_arr,0,sizeof(cl_arr));
	memset(decl_arr,0,sizeof(decl_arr));
	
	cl_arr[0] = decl_arr[0] = 1;
	int m=1;
	
	for(int i=1;i<n;i++){
		if(arr[i-1] < arr[i]){
			cl_arr[i] = cl_arr[i-1]+1;
			decl_arr[i] = 1;
			
			m = max(cl_arr[i], m);
		}
		else if(arr[i-1] > arr[i]){
			decl_arr[i] = decl_arr[i-1]+1;
			cl_arr[i] = 1;
			
			m = max(decl_arr[i], m);
		}
		else{
			decl_arr[i] = decl_arr[i-1]+1;
			cl_arr[i] = cl_arr[i-1]+1;
			
			m = max(cl_arr[i], m);
			m = max(decl_arr[i], m);
		}
	}
	
	cout << m << endl;
}
