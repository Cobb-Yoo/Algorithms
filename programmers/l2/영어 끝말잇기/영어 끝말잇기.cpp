#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int len = words.size();
    
    vector<string> v;
    v.push_back(words[0]);
    
    for(int i=1;i<len;i++){
        int v_len = v.size();
        
        if(words[i][0] != v[v_len-1][v[v_len-1].size()-1]){ // 끝말잇기의 조건을 확인
            if((i+1)%n == 0) return {n,i/n+1};
            else return {(i+1)%n,i/n+1};
        }
        
        for(int j=0;j<v_len;j++){// 끝말잇기는 되지만 이미 사용한 단어를 재사용하는 것을 확인
            if(words[i] == v[j]){
                if((i+1)%n == 0) return {n,i/n+1};
                else return {(i+1)%n,i/n+1};
            }
        }
        v.push_back(words[i]);
    }

    return {0,0};
}
