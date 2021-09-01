// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381865

/*
Approach:
Find number of times the given array can come upto index z (found by z / n)
Sum till index z from index 0: ((z/n) * presum[n-1]) + presum[z%n]

Therefore for Sum from l to r: ( ((r/n) * presum[n-1]) + presum[r%n] ) - ( (((l-1)/n) * presum[n-1]) + presum[(l-1)%n] )
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> solve(ll arr[], ll n, vector<vector<ll>> &queries, ll q);

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	ll arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	ll q;
	cin >> q;

	vector<vector<ll>> queries;

	for (int i = 0; i < q; i++)
	{
		ll l, r;
		cin >> l >> r;
		queries.push_back({l, r});
	}

	vector<int> ans = solve(arr, n, queries, q);

	// Print answer:

	for (int i = 0; i < q; i++)
	{
		cout << ans[i] << endl;
	}


	return 0;
}

vector<int> solve(ll arr[], ll n, vector<vector<ll>> &queries, ll q)
{
	int M = 1000000007;
	vector<int> ans;
	vector<long long int> vect(n + 1);
	vect[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		vect[i] = (vect[i - 1] + arr[i - 1]) % M;
	}

	for (int i = 0; i < q; i++)
	{
		ll l = queries[i][0] - 1;
		ll r = queries[i][1];

		ll temp = (((((((r / n) % M) * vect[n]) % M) + vect[r % n]) % M) - ((((((l / n) % M) * vect[n]) % M) + vect[l % n]) % M));
		temp = (temp + M) % M;

		ans.push_back((int)temp);
	}
	return ans;
}

// Time Complexity: O(N+Q)
// Space Complexity: O(N)