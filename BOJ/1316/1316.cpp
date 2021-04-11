#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int cal(string line){
	char tmp[100]={"\n"};
	int alpha[26]={0};
	int j=0;
	int len = line.length();
	
	if(line.length()!=1){
		for(int i=1;i<len;i++){//앞뒤가 다르면 tmp에 앞에꺼 저장. 
			if(line.at(i) != line.at(i-1))
				tmp[j++] = line.at(i-1);
		}
		
		for(int i=1;i<len;i++){
			if(line.at(len-1) != line.at(len-i))
				tmp[j] = line.at(len-1);
		}
		
		for(int i=0;i<=j;i++){//저장된 것들을 분류 
			alpha[tmp[i]-'a']++;
		}
		
		for(int i=0;i<26;i++){//확인. 
			if(alpha[i] > 1){
				return 0;
			}
		}
	}
	
	return 1;
}

int main(){
    string line;
    int n,count=0;
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        cin >> line;
        count += cal(line);
    }
    
    cout << count;
}
