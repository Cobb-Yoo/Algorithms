#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	
	int max_a=0, min_a=0; 
	int max_b=0, min_b=0;
	
	int len_a = a.size();
	int len_b = b.size();
	
	for(int i=0;i<len_a;i++){
		if(a[i] == '5'){
			max_a = max_a * 10 + 6;
			min_a = min_a * 10 + 5;
		}else if(a[i] == '6'){
			max_a = max_a * 10 + 6;
			min_a = min_a * 10 + 5;
		}else{
			max_a = max_a * 10 + a[i]-'0';
			min_a = min_a * 10 + a[i]-'0';
		}
	}
	
	for(int i=0;i<len_b;i++){
		if(b[i] == '5'){
			max_b = max_b * 10 + 6;
			min_b = min_b * 10 + 5;
		}else if(b[i] == '6'){
			max_b = max_b * 10 + 6;
			min_b = min_b * 10 + 5;
		}else{
			max_b = max_b * 10 + b[i]-'0';
			min_b = min_b * 10 + b[i]-'0';
		}
	}
	
	cout << min_a + min_b << " " << max_a + max_b << endl;
}
