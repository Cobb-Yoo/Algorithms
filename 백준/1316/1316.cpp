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
		for(int i=1;i<len;i++){//�յڰ� �ٸ��� tmp�� �տ��� ����. 
			if(line.at(i) != line.at(i-1))
				tmp[j++] = line.at(i-1);
		}
		
		for(int i=1;i<len;i++){
			if(line.at(len-1) != line.at(len-i))
				tmp[j] = line.at(len-1);
		}
		
		for(int i=0;i<=j;i++){//����� �͵��� �з� 
			alpha[tmp[i]-'a']++;
		}
		
		for(int i=0;i<26;i++){//Ȯ��. 
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
