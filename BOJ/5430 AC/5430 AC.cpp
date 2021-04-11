#include <deque> 
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	while(n--){
		deque<int> dq;
		string cmder;
		int arr_size;
		string tmp;
		
		cin >> cmder;
		cin >> arr_size;
		cin >> tmp;
		
		int len = tmp.size();
		
		string tmp_string="";
		for(int i=1;i<len;i++){ //������ ���� 
			if(tmp[i] == ',' || tmp[i] == ']'){
				if(!tmp_string.empty()){
					dq.push_back(stoi(tmp_string));
					tmp_string.clear();
				}
			}else{
				tmp_string += tmp[i];
			}
		}
		
		len = cmder.size();
		
		bool env = 1; // �Ϲݻ��� 
		
		for(int i=0;i<=len;i++){
			if(i == len){ //��� 
				cout << "[";
				while(!dq.empty()){
					if(env){
						cout << dq.front();
						dq.pop_front();
					}else{
						cout << dq.back();
						dq.pop_back();
					}
						
					if(!dq.empty()) cout << ",";
				}
				cout << "]\n";
				break;
			}
			
			if(cmder[i] == 'R') env ^= 1;
			else if (cmder[i] == 'D'){
				if(dq.empty()) {
					cout << "error\n";
					break;	
				}
				
				if(env){
					dq.pop_front();
				}else{
					dq.pop_back();
				}
			}
		}
	}
}
