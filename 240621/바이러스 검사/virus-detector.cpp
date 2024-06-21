#include <iostream>

using namespace std;

int n;
int restaurantCustomers[1000001];
int coverage_jang, coverage_won;
int minInspectors;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> restaurantCustomers[i];
	cin >> coverage_jang >> coverage_won;
	for (int i = 0; i < n; i++)
	{
		minInspectors++;
		restaurantCustomers[i] -= coverage_jang;
		if (restaurantCustomers[i] <= 0)
			continue;
		minInspectors += (restaurantCustomers[i] / coverage_won);
		if (restaurantCustomers[i] % coverage_won != 0)
			minInspectors++;
	}
	cout << minInspectors;
	return 0;
}