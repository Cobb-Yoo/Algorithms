#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int> > v(n);
    vector<int> answer(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }


    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int idx = v[i].second;
        int tmp = cnt;

        answer[idx] = tmp;
   
        wh     cnt++;
ile (i < n && v[i].first == v[i + 1].first) {
            ++i;
            idx = v[i].second;
            answer[idx] = tmp;
        }
    }

    for (auto a : answer) cout << a << " ";

}
