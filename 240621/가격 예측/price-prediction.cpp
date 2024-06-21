#include <iostream>

using namespace std;

int w, n;
int price[16];
int nowStocks;

int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> price[i];

	for (int day = 0; day < n; day++)
	{
		if (day == n - 1)
		{
			w += nowStocks * price[day];
			continue;
		}
		if (nowStocks > 0)
		{
			w += nowStocks * price[day];
			nowStocks = 0;
		}
		if (price[day] < price[day + 1])
		{
			nowStocks = w / price[day];
			w -= nowStocks * price[day];
		}
	}
	cout << w;
	return 0;
}