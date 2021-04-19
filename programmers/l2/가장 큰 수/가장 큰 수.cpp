#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    int len = numbers.size();
    vector<string> arr;

    for(int i=0;i<len;i++){
        arr.push_back(to_string(numbers[i]));
    }

    sort(arr.begin(),arr.end(),cmp);

    string answer = "";
    for(int i=0;i<len;i++) answer += arr[i];

    if(answer[0] == '0') return "0";
    return answer;
}
