#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int n;
int arr[1001];
int d[1001];//±æÀÌ distance 
int v[1001];// °ª? 
vector<int>answer;
 
void go(int index) {
    if (index == -1) {
 
        return;
    }
    answer.push_back(arr[index]);
    go(v[index]);
}
 
 
int main() { 
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    for (int i = 0; i < n; i++) {
        v[i] = -1;
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                v[i] = j;
            }
        }
    }
 
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[i]);
    }
 
    cout << ans << endl;
 
    for (int i = 0; i < n; i++) {
        if (d[i]==ans){
            answer.push_back(arr[i]);
            go(v[i]);
            break;
        }
    }
 
    sort(answer.begin(), answer.end());
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
 
}
