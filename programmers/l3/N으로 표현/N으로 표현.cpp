#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    int tmp=0;
    vector<int> arr[8];
    
    for(int i=0;i<8;i++){
        tmp = tmp*10 +1;
        arr[i].push_back(tmp*N);
    }
    
    for(int i=1;i<8;i++){
        for(int j=0;j<i;j++){            
            for(auto op1 : arr[j]){
                for(auto op2 : arr[i-j-1]){
                    arr[i].push_back(op1+op2);
                    arr[i].push_back(op1-op2);
                    arr[i].push_back(op1*op2);
                    if(op2) arr[i].push_back(op1/op2);
                }
            }
        }
        
        int len = arr[i].size();
        for(int j=0;j<len;j++){
            if(arr[i][j] == number) return i+1;
        }
    }
    
    
    return -1;
}
