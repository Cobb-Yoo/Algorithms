#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
 
const int MAX = 4000;
int arr[MAX+1][MAX+1];
 
int main(){
    string s1, s2;
    cin>>s1>>s2;
    
    int answer=0;
    memset(arr,0,sizeof(arr));
    
    for(int i=1; i<=s1.size();i++){
        for(int j=1;j<=s2.size();j++){
            if(s1[i-1]==s2[j-1]){
                arr[i][j]=arr[i-1][j-1]+1;
                
                answer=max(answer,arr[i][j]);
            }
        }
    }
    
    cout << answer << endl;
}
