// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381872
/*
Solution:
Modified the kadane's algorithm and used it:

First find the sum of all the elements of the array, initialize curr_sum and max_sum with this value (rather than 0 and INT_MIN in normal kadane's algo)
Iterate through the array and in each iteration:
-> If arr[i]==0, then increment curr_sum by 1 as when flipped 0 it becomes 1
-> Else arr[i]==1, then decrement curr_sum by 1 as when flipped 1 it becomes 0
-> max_sum=max(max_sum,curr_sum)
-> If curr_sum is less than arr_sum then curr_sum=arr_sum

max_sum is the required answer
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int* arr, int n);

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ans = solve(arr, n);

	cout << ans << endl;

	return 0;
}

int solve(int* arr, int n)
{
	int curr_sum = 0, arr_sum = 0, max_sum = 0;

	for (int i = 0; i < n; i++)
	{
		arr_sum += arr[i];
	}
	max_sum = curr_sum = arr_sum;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)
		{
			curr_sum++;
		}
		else
		{
			curr_sum--;
		}
		max_sum = max(max_sum, curr_sum);

		if (curr_sum < arr_sum)
		{
			curr_sum = arr_sum;
		}
	}
	return max_sum;
}