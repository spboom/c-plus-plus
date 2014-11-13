// templateClasses.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ThreeDArray.h"
#include "PointerTest.h"
#include "NDimArray.h"
#include "Ding.h"
#include <iostream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int* dimSizes = new int[1];
	dimSizes[0] = 2;
	//dimSizes[1] = 5;
	NDimarray<int, 1> Array2D(dimSizes);

	for (int x = 0; x < Array2D.get_dim_size(0); x++)
	{
		//for (int y = 0; y < Array2D.get_dim_size(1); y++)
		{
			int *location = new int[2];
			location[0] = x;
			//location[1] = y;
			Array2D.put(location, x);
			delete[] location;
		}
	}


	for (int x = 0; x < Array2D.get_dim_size(0); x++)
	{
		//for (int y = 0; y < Array2D.get_dim_size(1); y++)
		{
			int *location = new int[1];
			location[0] = x;
			//location[1] = y;
			cout << Array2D.get(location) << " ";
			delete[] location;
		}
		cout << endl;
	}

	string line = "";
	cin >> line;
	return 0;
}

