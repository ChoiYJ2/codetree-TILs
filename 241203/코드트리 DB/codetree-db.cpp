#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

map<string, double> tableOrderByName;
map<double, string> tableOrderByValue;
vector<double> vectorValue;
bool check[1000000000];

void init()
{
	// 테이블 초기화(모든 데이터 삭제)
	tableOrderByName.clear();
	tableOrderByValue.clear();
	vectorValue.clear();
}

int insertData(string name, double value)
{
	// 새 데이터 추가
	if ((tableOrderByName.count(name) != 0 && tableOrderByName[name] != 0) || (tableOrderByValue.count(value) != 0 && tableOrderByValue[value] != ""))
	{
		return 0;
	}
	else
	{
		tableOrderByName[name] = value;
		tableOrderByValue[value] = name;
		vectorValue.push_back(value);
		return 1;
	}
}

double deleteData(string name)
{
	// 데이터 삭제
	if (tableOrderByName.count(name) == 0 || (tableOrderByName.count(name) != 0 && tableOrderByName[name] == 0))
		return 0;
	else
	{
		double value = tableOrderByName[name];
		tableOrderByName[name] = 0;
		tableOrderByValue[value] = "";
		return value;
	}
}

string rankData(double k)
{
	int cnt = 0;
	memset(check, false, sizeof(check));
	for (int i = 0; i < vectorValue.size(); i++)
	{
		if (vectorValue[i] == 0 || check[(int)vectorValue[i]])
		{
			cnt++;
			vectorValue[i] = 0;
			continue;
		}

		check[(int)vectorValue[i]] = true;
		if (tableOrderByValue.count(vectorValue[i]) != 0 && tableOrderByValue[vectorValue[i]] != "")
			continue;
		cnt++;
		vectorValue[i] = 0;
	}

	sort(vectorValue.begin(), vectorValue.end());
	int wholeSize = vectorValue.size() - cnt;

	if (wholeSize < k)
		return "None";
	else
	{
		int idx = cnt + k - 1;
		double value = vectorValue[idx];
		return tableOrderByValue[value];
	}
}

double sumData(double k)
{
	// 특정 값 이하의 데이터 합 계산
	double sum = 0;
	map<double, string>::iterator start = tableOrderByValue.begin();
	map<double, string>::iterator end = tableOrderByValue.end();
	for (map<double, string>::iterator now = start; now != end; now++)
	{
		if (now->second == "")
			continue;
		if (now->first > k)
			break;
		sum += now->first;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	for (int turn = 0; turn < q; turn++)
	{
		string order;
		cin >> order;
		if (order == "init")
			init();
		else if (order == "insert")
		{
			string name;
			double value;
			cin >> name >> value;
			int res = insertData(name, value);
			cout << res << "\n";
		}
		else if (order == "delete")
		{
			string name;
			cin >> name;
			double res = deleteData(name);
			cout << res << "\n";
		}
		else if (order == "rank")
		{
			double k;
			cin >> k;
			string res = rankData(k);
			cout << res << "\n";
		}
		else if (order == "sum")
		{
			double k;
			cin >> k;
			double res = sumData(k);
			cout << res << "\n";
		}
	}
	return 0;
}