
#include "JsonManeger.h"

#include <nlohmann/json.hpp>
#include <iostream>

using namespace std;
using json = nlohmann::json;
using json_m = JsonManeger;

int main()
{
	json_m::Init();

	json_m::LoadJsonFile("sample.json");
	json_m::LoadJsonFile("sample1.json");

	json data = json_m::LoadJsonFile("sample.json");
}
