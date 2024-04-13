#include <iostream>

using namespace std;

int n;
int map[101][101];
long long int dp[101][101];

void init()
{
	dp[1][1] = map[1][1];

	for (int y = 2; y <= n; y++)
		dp[y][1] = dp[y - 1][1] + map[y][1];

	for (int x = 2; x <= n; x++)
		dp[1][x] = dp[1][x - 1] + map[1][x];
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	init();

	for (int y = 3; y <= n; y++)
	{
		for (int x = 2; x <= n; x++)
			dp[y][x] = max(dp[y - 1][x] + map[y][x], dp[y][x - 1] + map[y][x]);
	}

	cout << dp[n][n];
	return 0;
}