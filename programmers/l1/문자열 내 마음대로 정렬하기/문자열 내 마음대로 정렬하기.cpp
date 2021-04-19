#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int c;
bool cmp(string a, string b){
    if(a[c] == b[c]) return a < b;
    return a[c] < b[c];
}

vector<string> solution(vector<string> strings, int n) {
    c = n;
    sort(strings.begin(),strings.end(),cmp);
    return strings;
}
