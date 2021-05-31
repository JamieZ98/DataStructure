#include <iostream>
using namespace std;
#define MAXSIZE 100000

void solution(int n, int* a)
{
	int thissum = 0;
	int result[3] = { 0 };
	int left = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		thissum += a[i];
		if (thissum > result[0])
		{
			result[0] = thissum;
			result[1] = left;
			result[2] = i;
		}
		else if (thissum < 0)
		{
			thissum = 0;
			if (i < n - 1)
			{
				left = i + 1;
			}
		}
	}
	cout << "最大子列和为：" << result[0] << endl;
	cout << "首尾元素下标分别为：" << result[1] << "，" << result[2];
}

int main()
{
	int n;
	int a[MAXSIZE];
	cin >> n;
	solution(n, a);
	return 0;
}

