#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 10000000;
bool arr[MAX];
bool visited[MAX];
bool sel[7];
int answer = 0;

void init(){
    arr[0] = arr[1] = 1;
    for(int i=2;i*i<MAX;i++){
        if(!arr[i]){
            for(int j=i+i;j<MAX;j+=i){
                arr[j] = 1;
            }
        }
    }
}

void f(int n,string s, string tmp){
    if(tmp != "" && visited[stoi(tmp)] == 0){
        int num = stoi(tmp);
        visited[num] = 1;
        if(!arr[num]) answer++;
    }

    int len = s.size();

    for(int i=0;i<len;i++){
        if(sel[i]) continue;

        sel[i] = 1;
        f(n+1, s, tmp+s[i]);
        sel[i] = 0;
    }
}

int solution(string numbers) {
    init();

    f(0,numbers,"");

    return answer;
}
