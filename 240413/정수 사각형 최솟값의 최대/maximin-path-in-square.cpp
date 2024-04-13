#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
long long int map[101][101];
long long int dp[101][101];

void init()
{
    for (int i = 1; i <= n; i++)
        fill(dp[i], dp[i] + 100, 200000000000);

    dp[1][1] = map[1][1];

    for (int y = 2; y <= n; y++)
        dp[y][1] = min(dp[y - 1][1], map[y][1]);

    for (int x = 2; x <= n; x++)
        dp[1][x] = min(dp[1][x - 1], map[1][x]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];
    }

    init();

    for (int y = 2; y <= n; y++)
    {
        for (int x = 2; x <= n; x++)
        {
            long long int tmp1 = min(dp[y - 1][x], map[y][x]);
            long long int tmp2 = min(dp[y][x - 1], map[y][x]);
            dp[y][x] = max(tmp1, tmp2);
        }
    }

    cout << dp[n][n];
    return 0;
}