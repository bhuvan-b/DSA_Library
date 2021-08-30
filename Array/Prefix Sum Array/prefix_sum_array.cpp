#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(int argc, char const *argv[])
{
	ll n;									// n->Number of elements in the array
	cin >> n;

	ll arr[n];								// arr->Array whose prefix sum is to be calculated

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// Prefix Sum Array:

	ll presum[n];
	presum[0] = arr[0];

	for (int i = 1; i < n; i++)
	{
		presum[i] = presum[i - 1] + arr[i];
	}

	// Print prefix sum array

	for (int i = 0; i < n; i++)
	{
		cout << presum[i] << " ";
	}

	return 0;
}