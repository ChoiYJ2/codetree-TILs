#include <iostream>
#include <vector>

using namespace std;

int n, maxRevenue;
int selection[16];
struct Outsourcing
{
	int start, duration;
	int revenue;
};

vector<Outsourcing> outsourcings;

void dfs(int sum, int passedDay)
{
	if (passedDay == n - 1)
	{
		maxRevenue = max(maxRevenue, sum);
		return;
	}
	for (int i = passedDay; i < n; i++)
	{
		if (selection[i])
			dfs(sum, passedDay + 1);
		Outsourcing now = outsourcings[i];
		for (int day = now.start; day < now.start + now.duration; day++)
			selection[day] = 1;
		dfs(sum + now.revenue, passedDay + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;
		outsourcings.push_back({ i + 1, t, p });
	}

	dfs(0, 0);
	cout << maxRevenue;
	return 0;
}