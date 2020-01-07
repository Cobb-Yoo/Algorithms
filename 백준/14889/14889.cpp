#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool used[21];
int arr[21][21];
int ans = 99999999;


void dfs(int player, int cnt){
    if (cnt == n/2){
    	vector<int> start, link;
		
		for(int i=0;i<n;i++){
			if(used[i]) start.push_back(i);
			else link.push_back(i);
		}
		
		int start_abli=0, link_abli=0;
		for(int i=0;i<cnt;i++){
			for(int j=i+1;j<cnt;j++){
				start_abli += arr[start[i]][start[j]] + arr[start[j]][start[i]];
				link_abli += arr[link[i]][link[j]] + arr[link[j]][link[i]];
			}
		}
		
		ans = min(ans, abs(start_abli - link_abli));
		return;
	}

    for (int i = player+1; i < n; i++){
        if (used[i] == false){
            used[i] = true;
            dfs(i, cnt + 1);
            used[i] = false;
        }
    }
}


int main()
{
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    dfs(0,0);

    cout << ans << "\n";

    return 0;
}
