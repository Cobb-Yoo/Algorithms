#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int numbers = budgets.size();

    sort(budgets.begin(),budgets.end());

    for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
        if(*itr > (M / numbers)) return M/numbers;
        else{
            M -= *itr;
            numbers--;
        }
    }

    return budgets.back();
}
