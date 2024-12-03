#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, double> tableOrderByName;
map<double, string> tableOrderByValue;
vector<double> vectorValue;
map<double, int> indexes;

void init()
{
	// 테이블 초기화(모든 데이터 삭제)
	tableOrderByName.clear();
	tableOrderByValue.clear();
	vectorValue.clear();
	indexes.clear();
}

int insertData(string name, double value)
{
	// 새 데이터 추가
	if ((tableOrderByName.count(name) != 0 && tableOrderByName[name] != 0) || (tableOrderByValue.count(value) != 0 && tableOrderByValue[value] != ""))
		return 0;
	else
	{
		tableOrderByName[name] = value;
		tableOrderByValue[value] = name;
		vectorValue.push_back(value);
		indexes.insert({ value, vectorValue.size() - 1 });
		return 1;
	}
}

void updateIndex()
{
	indexes.clear();
	for (int i = 0; i < vectorValue.size(); i++)
	{
		double now = vectorValue[i];
		indexes[now] = i;
	}
	return;
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

		updateIndex();
		int offset = indexes[value];
		vectorValue.erase(vectorValue.begin() + offset);
		updateIndex();
		return value;
	}
}

string rankData(double k)
{
	sort(vectorValue.begin(), vectorValue.end());
	int wholesize = vectorValue.size();

	if (wholesize < k)
		return "None";
	else
	{
		int idx = k - 1;
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