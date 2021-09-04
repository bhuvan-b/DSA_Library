// Problem: Count all sub - arrays having sum divisible by k
// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381867
/*
Solution Approach:

Let the sum of a subarray (from index a to b) be X,
then X = (sum of subarray from index 0 to b) - (sum of subarray from index 0 to a-1) = M - N
X = ((q1*k)+r1) - ((q2*k)+r2) where q1 is the quotient and r1 is the remainder when M is divided by k, same with q2,r2 and N

X = (q1-q2)k + (r1-r2)

If X is the sum of a subarray which is divisible by k then, (q1-q2)k + (r1-r2) should be divisible by k,
i.e., r1-r2=0 -> r1=r2

Therefore, we need to find all the subarrays (index starting from 0) whose remainder is the same and take the sum of (nC2) of each possible remainder,
where n is the number of times a particular remainder occured when divided by k.
Sum is the final answer. Here we take nC2, as we need number of combinations of two subarrays (starting with index 0) having same remainder.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(vector<int> &arr, int k);

int main(int argc, char const *argv[])
{
	ll t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> arr(n);

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}


		int ans = solve(arr, k);
		cout << ans << endl;
	}
	return 0;
}

int solve(vector<int> &arr, int k)
{
	ll sum = 0;
	int ans = 0;
	map<int, int> mp;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		mp[((sum % k) + k) % k]++;			// Given the constraints that arr[i] can be negative, the sum can be negative, therefore taking modulus twice
	}

	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		int val = i->second;
		if (val > 1)
		{
			ans += (val * (val - 1)) / 2;
		}
	}
	ans += mp[0]; 						// Adding the number of elements of array divisible by k

	return ans;
}