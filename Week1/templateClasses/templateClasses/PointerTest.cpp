#include "stdafx.h"
#include "PointerTest.h"
#include "Ding.h"
#include <vector>
#include <memory>

using namespace std;

PointerTest::PointerTest()
{
	vector<unique_ptr<Ding>> dingen;
	for (int i = 0; i < 10; i++)
	{
		dingen.push_back(unique_ptr<Ding> { new Ding });
	}
}


PointerTest::~PointerTest()
{
}
