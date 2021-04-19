#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());

    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}
