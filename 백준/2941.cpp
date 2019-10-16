#include <iostream>
#include <string>
using namespace std;

int main(){
	string line;
	int count=0;
	int len;
	int i;
	
	cin >> line;
	len = line.length();
	
	for(i =0;i<len;i++){
		
		count++;
		
		if(len - i == 1) break;
		
		switch(line[i]){
			case 'c':
				if(line[i+1]== '=' || line[i+1] == '-') {
					i++;
				}
				break;
			case 'd':
				if(line[i+1] == '-'){
					i++;
				}
				else if(line[i+1] == 'z' && line[i+2] == '='){
					i+=2;
				}
				break;
			case 'l':
				if(line[i+1] == 'j'){
					i++;
				}
				break;
			case 'n':
				if(line[i+1] == 'j'){
					i++;
				}
				break;
			case 's':
				if(line[i+1] == '='){
					i++;
				}
				break;
			case 'z':
				if(line[i+1] == '='){
					i++;
				}
				break;
			default:
				break;
		}
	}
	
	cout << count;
}
