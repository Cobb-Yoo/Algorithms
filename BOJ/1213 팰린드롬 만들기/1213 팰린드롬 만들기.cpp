#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string str;
int arr[26];
string a = "";
string b = "";
char flag_c;

bool check_palindrome(){
	int mid = a.size()/2;
	int len = a.size();
	for(int i=0;i<mid;i++){
		if(a[i] != a[len-1-i]) return 0;
	}
	return 1;
}

int main(){
	bool flag = 0;
	string answer = "";
	cin >> str;
	
	int len = str.size();
	
	for(int i=0;i<len;i++){
		arr[str[i]-'A']++;
	}
	
	for(int i=0;i<26;i++){
		while(arr[i]){
			if(arr[i] == 1 && flag) {
				cout << "I'm Sorry Hansoo";
				exit(0);
			}
			else if(arr[i] == 1){
				flag = 1;
				flag_c = 'A'+i;
				arr[i]--;
				continue;
			}
			else{
				a += 'A'+i;
				arr[i]--;
			}
			
			if(arr[i]>0) {
				b+= 'A'+i;
				arr[i]--;
			}
		}
	}
	
	if(flag) a += flag_c;
	
	int b_len = b.size();
	for(int i=b_len-1;i>=0;i--){
		a += b[i];
	}
	
	if(check_palindrome()) cout << a << endl;
	else {
		cout << "I'm Sorry Hansoo" << endl;
	}
	
	
}
