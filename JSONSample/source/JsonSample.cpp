
#include "JsonManeger.h"

#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;
using json = nlohmann::json;
using json_m = JsonManeger;

int main()
{
	json_m::Init();

	json_m::LoadJsonFile("res/sample.json");
	json_m::LoadJsonFile("res/sample1.json");

	json datas = json_m::LoadJsonFile("res/sample.json");
	for (const auto& item : datas)
	{
		if (item["id"] == 1)
		{
			cout << item["height"]	<< endl;
			cout << item["weight"]	<< endl;
			cout << item["type"]	<< endl;
			cout << endl;
			break;
		}
	}

	json datas_1 = json_m::LoadJsonFile("res/sample1.json");
	for (const auto& item : datas_1)
	{
		if (item["id"] == 4)
		{
			cout << item["height"]	<< endl;
			cout << item["weight"]	<< endl;
			cout << item["type"]	<< endl;
			cout << endl;
			break;
		}
	}

	json_m::DeleteJson("res/sample.json");

	cout << boolalpha << json_m::IsJsonFile("res/sample.json") << endl;

	return 0;
}
