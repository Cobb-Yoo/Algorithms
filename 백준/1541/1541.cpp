#include <iostream>
#include <string>
using namespace std;

int main(){
	string data;
	string tmp = "";
	int result=0;
	bool m=false;
	
	cin >> data;
	int len = data.length();
	for(int i=0;i<=len;i++){
		if(data[i] == '+'|| data[i] == '-'|| data[i] == '\0'){
			if(m){
				result -= stoi(tmp);
			}
			else{
				result += stoi(tmp);
			}
			
			tmp = "";
			
			if(data[i] == '-'){
				m = true;
			}
		}
		else{
			tmp += data[i];
		}
	}
	
	cout << result << endl;
}
