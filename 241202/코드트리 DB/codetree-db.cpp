#include <iostream>
#include <map>

using namespace std;

map<string, double> tableOrderByName;
map<double, string> tableOrderByValue;

void init()
{
	// 테이블 초기화(모든 데이터 삭제)
	tableOrderByName.clear();
	tableOrderByValue.clear();
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
		tableOrderByName.insert({ name, value });
		tableOrderByValue.insert({ value, name });
		return 1;
	}
}

double deleteData(string name)
{
	// 데이터 삭제
	if (tableOrderByName.count(name) == 0)
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
	// k번째로 작은 값을 가진 데이터 조회
	int wholeSize = tableOrderByValue.size();
	if (wholeSize < k)
		return "None";
	else
	{
		map<double, string>::iterator target;
		if (wholeSize / 2 >= k)
		{
			target = tableOrderByValue.begin();
			for (int i = 0; i < k; i++)
				target++;
		}
		else
		{
			target = tableOrderByValue.end();
			for (int i = 0; i < (wholeSize - k + 1); i++)
				target--;
		}
		return target->second;
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