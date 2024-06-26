#include <iostream>
#include <vector>

using namespace std;

int n, maxRevenue;
struct Outsourcing
{
	int start, duration;
	int revenue;
};
vector<Outsourcing> outsourcings;

void dfs(int sum, int passedDay)
{
	maxRevenue = max(maxRevenue, sum);
	if (passedDay >= n)
		return;
	for (int i = passedDay; i < n; i++)
	{
		Outsourcing now = outsourcings[i];
		if (i + now.duration > n)
			continue;
		dfs(sum + now.revenue, i + now.duration);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		outsourcings.push_back({ i, t, p });
	}

	dfs(0, 0);
	cout << maxRevenue;
	return 0;
}