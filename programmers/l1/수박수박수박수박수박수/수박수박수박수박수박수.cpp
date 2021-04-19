#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int i;
    for(i=1;i<=n;i++){
        i&1 ? answer+="¼ö" : answer+="¹Ú";
    }
    return answer;
}
