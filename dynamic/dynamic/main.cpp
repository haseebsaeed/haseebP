#include <iostream>
#include <time.h>

using namespace std;

int isSubsetSum(int * set, int n, int sum)
{
	bool** arr = new bool*[sum+1];
	for (int i = 0; i <= sum; ++i)
		arr[i] = new bool[n+1];

	for (int i = 0; i <= n; i++)
		arr[0][i] = true;

	for (int i = 1; i <= sum; i++)
		arr[i][0] = false;

	for (int i = 1; i <= sum; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = arr[i][j - 1];

			if (i >= set[j - 1])
				arr[i][j] =(arr[i][j] || arr[i - set[j - 1]][j - 1]);
		}
	}
	return arr[sum][n];
}

void createRandomSet(int *set, int n)
{
	srand(time(0));
	int random_integer;
	int random_sign;
	for (int i = 0; i < n; i++) {
		random_integer = rand();
		random_sign = (rand() % 2);
		if (random_sign == 0)
		{
//			random_integer = -random_integer;
		}
		set[i] = random_integer;
	}
}

int main()
{
	//int n;
	//int sum;

	//cout << "Enter set size: ";
	//cin >> n;
	//cout << "Enter sum: ";
	//cin >> sum;

	//int * set;
	//set = new int[n];

//	createRandomSet(set, n);

	int set[] = { 435, 23, 3, 34, 4, 12, 5, 2 ,23 , 35 ,456 ,234};
	int n = 12;
	int sum = 474;


	cout << endl << "Your set contains: ";
	for (int i = 0; i < n; i++) {
		cout << set[i] << " ";
	}
	cout << endl << "Sum: " << sum;
	cout << endl;
	if (isSubsetSum(set, n, sum) == true)
		cout << "Subset Found";
	else
		cout << "Subset Not Found";
	return 0;
}