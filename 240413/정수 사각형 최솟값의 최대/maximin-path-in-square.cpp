#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[101][101];
long long int dp[101][101];

void init()
{
    for (int i = 1; i <= n; i++)
        fill(dp[i], dp[i] + 100, 200000000000);

    dp[n][n] = 0;
    dp[1][1] = map[1][1];

    for (int y = 1; y <= n; y++)
        dp[y][1] = map[y][1];

    for (int x = 1; x <= n; x++)
        dp[1][x] = map[1][x];
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
            if (y == n && x == n)
                dp[y][x] = max(dp[y - 1][x], dp[y][x - 1]);
            else
                dp[y][x] = min(dp[y - 1][x], dp[y][x - 1]);
        }
    }

    cout << dp[n][n];
    return 0;
}