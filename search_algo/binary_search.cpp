#include <iostream>

using namespace std;

int main()
{
	int arr[] = {2, 3, 5, 6, 7, 8, 10, 11, 15, 17}; // Sorted array
	int key = 11;
	int min = 0;
	int max = 9;
	int mid;
	bool flag = false;

	while (min == max)
	{

		mid = (min + max) / 2;

		if (arr[mid] == key)
		{
			flag = true;
		}
		else if (arr[mid] < key)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}

	if (flag == true)
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}

	return 0;
}