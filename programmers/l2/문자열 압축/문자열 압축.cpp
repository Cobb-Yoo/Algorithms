#include <vector>
#include <string>
using namespace std;

int solution(string s){
	int len = s.size();
	int answer = len;
	
	for(int i=1;i<=len/2;i++){
		string result = "";
		string tmp = s.substr(0,i);
		int cnt = 1;
		
		for(int j=i;j<=len;j+=i){
			if(tmp == s.substr(j,i)) cnt++;
			else {
				if(cnt == 1) result += tmp;
				else result += (to_string(cnt) + tmp);
				
				tmp = s.substr(j,i);
				cnt = 1;
			}
		}
		
		if(len/i != 0) result += s.substr((len/i)*i);
		if(answer > result.size()) answer = result.size();
	}
	
	return answer;
}
