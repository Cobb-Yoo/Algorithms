#include <iostream>
#include <string>
using namespace std;

string arr[] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
long long brr[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int main(){
	long long answer=0;
	
	string tmp;
	
	for(int i=0;i<2;i++){
		cin >> tmp;
		for(int j=0;j<10;j++){
			if(tmp == arr[j]) answer = answer * 10 + j;
		}
	}
	
	cin >> tmp;
	for(int i=0;i<10;i++){
		if(tmp == arr[i]) answer = answer * brr[i];
	}
	
	cout << answer << endl;
}
