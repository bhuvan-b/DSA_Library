// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870
/*
Solution:

For these kind of problems we can make use of Kadane's Algorithm, which is a dynamic programming algorithm.
Kadane's algorithm is used to find out the maximum sum contiguous subarray of the given array.

Algorithm:

Initialize curr_sum = 0 and max_sum = INT_MIN

We iterate throughout the array and in each iteration:
-> Add arr[i] to curr_sum
-> max_sum=max(max_sum,curr_sum)
-> Make curr_sum=0 if curr_sum is negative

max_sum is the maximum sum
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

long long solve(ll arr[], int n);

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	ll arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	ll ans = solve(arr, n);

	cout << ans << endl;

	return 0;
}

ll solve(ll arr[], int n)
{
	ll curr_sum = 0, max_sum = INT_MIN;

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