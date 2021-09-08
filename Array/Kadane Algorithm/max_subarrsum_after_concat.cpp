// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381873
/*
Solution:

Case 1: If the value of k is 1:
		Then the answer is the maximum sum subarray which can be found by kadane's algorithm
Case 2: If k>1 and the sum of elements of whole array is less than 0 then:
		The answer is the maximum sum subarray (kadane's algorithm) of an array formed by joining two arrays
		As including those arrays whose sum is less than 0 would decrease the value of answer
Case 3: If k>1 and sum of array elements is greater than 0:
		We do the calculation in 3 steps:
		1-> Calculate the sum of those elements of 1st array of k concatenanted arrays which are included in the final subarray of k concatenated arrays
		Find the maximum sum of elements of the subarray which ends at last element of the raw array and add it to answer

		2-> Calculate the sum of all the elements of k-2 arrays (as we are separately calculating the sum of 1st array and last array)
		answer=arr_sum*(k-1)

		3-> Calculate the sum of those elements of last array of k concatenanted arrays which are included in the final subarray of k concatenated arrays
		Find the maximum sum of elements of the subarray which starts with first element of the raw array and add it to answer
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(vector<int> &arr, int n, int k);

int main()
{
	ll t;
	cin >> t;

	while (t--)
	{
		ll n, k;
		cin >> n >> k;

		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		ll ans = solve(arr, n, k);
		cout << ans << endl;
	}
}

ll solve(vector<int> &arr, int n, int k)
{
	ll arr_sum = 0, curr_sum = 0, max_sum = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		arr_sum += arr[i];
	}

	// case 1:
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			curr_sum += arr[i];
			max_sum = max(max_sum, curr_sum);

			if (curr_sum < 0)
			{
				curr_sum = 0;
			}
		}
		return max_sum;
	}
	// case 2:
	else if (arr_sum < 0)
	{
		curr_sum = 0;
		for (int i = 0; i < n; i++)
		{
			curr_sum += arr[i];
			max_sum = max(max_sum, curr_sum);

			if (curr_sum < 0)
			{
				curr_sum = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			curr_sum += arr[i];
			max_sum = max(max_sum, curr_sum);

			if (curr_sum < 0)
			{
				curr_sum = 0;
			}
		}
		return max_sum;
	}
	// case 3:
	else
	{
		ll ans = 0;
		max_sum = INT_MIN;
		curr_sum = 0;

		for (int i = n - 1; i >= 0 ; i--)
		{
			curr_sum += arr[i];
			max_sum = max(max_sum, curr_sum);
		}
		ans += max_sum;

		if (arr_sum > 0)
		{
			ans += (arr_sum * (k - 2));
		}

		max_sum = ans;
		curr_sum = ans;
		for (int i = 0; i < n; i++)
		{
			curr_sum += arr[i];
			max_sum = max(max_sum, curr_sum);
		}
		ans = max(max_sum, curr_sum);

		return ans;
	}
}