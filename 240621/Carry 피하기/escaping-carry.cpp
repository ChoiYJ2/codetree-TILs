#include <iostream>

using namespace std;

int n, maxPick;
int nums[21];

void dfs(int sum, int cnt, int idx)
{
	maxPick = max(maxPick, cnt);
	for (int i = idx; i < n; i++)
	{
		int tmp = sum;
		int nowNum = nums[i];
		int flag = 0;
		while (tmp != 0 || nowNum != 0)
		{
			int a = tmp % 10;
			int b = nowNum % 10;
			if (a + b >= 10)
			{
				flag = 1;
				break;
			}
			tmp /= 10;
			nowNum /= 10;
		}
		if (!flag)
			dfs(sum + nums[i], cnt + 1, i + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	dfs(0, 0, 0);
	cout << maxPick;
	return 0;
}