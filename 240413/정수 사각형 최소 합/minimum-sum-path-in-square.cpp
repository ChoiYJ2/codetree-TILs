#include <iostream>
#include <algorithm>

using namespace std;

int n = 100;
int map[101][101];
long long int dp[101][101];

void init()
{
	for (int i = 0; i < n; i++)
		fill(dp[i], dp[i] + 101, 2000000000);

	dp[0][n - 1] = map[0][n - 1];

	for (int y = 1; y < n; y++)
		dp[y][n - 1] = map[y][n - 1] + dp[y - 1][n - 1];

	for (int x = n - 2; x >= 0; x--)
		dp[0][x] = map[0][x] + dp[0][x + 1];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}

	init();

	for (int y = 1; y < n; y++)
	{
		for (int x = n - 2; x >= 0; x--)
			dp[y][x] = min(dp[y - 1][x], dp[y][x + 1]) + map[y][x];
	}

	cout << dp[n - 1][0];
	return 0;
}