#include <iostream>
using namespace std;

int N, r, c;
int x, y, ans;

void solve(int x, int y,int n) {
    if (x == r && y == c) {
        cout << ans << "\n";
        return;
    }

    if (r < x + n && r >= x && c < y + n && c >= y) {
        solve(x, y, n / 2);
        solve(x, y + n / 2, n / 2);
        solve(x + n / 2, y, n / 2);
        solve(x + n / 2, y + n / 2, n / 2);
    }

    else ans += n*n;
}

int main(){
    cin >> N >> r >> c;
    solve(0, 0, (1 << N));
    return 0;
}
