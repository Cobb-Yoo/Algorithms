#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	stack<int> arr;
	char list[1000000];
	int list_count=0;
	arr.push(0);
	int tos=0;
	int top_point=1;
	bool flag=true;
	int num;
	
	for(int i=0;i<n;i++){
		cin >> num;
		
		if(tos < num){
			for(int j=top_point;j<=num;j++){
				arr.push(j);
				list[list_count++] = '+';
			}
			
			top_point = arr.top()+1;
			
			arr.pop();
			list[list_count++] = '-';
			tos=arr.top();
		}
		else if(tos == num){
			arr.pop();
			list[list_count++] = '-';
			tos=arr.top();
		}
		else if(tos > num){
			if(arr.top() != num){
				flag=false;
				break; 
			}
		}
	}
	
	if(flag){
		for(int i=0;i<list_count;i++) cout << list[i] << "\n";
	}
	else{
		cout << "NO\n";
	}
	
}
