// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381864

/*
My approach:

For example, let there be 17 queries , which can be represented in sequence as follows:

1 2 q1 3 q2 q3 4 5 6 7 q4 8 9 q5 10 q6 11,

where qi are the query values of type 2 in order.
Bitwise xor operations are to be performed on all the elements present in the array at the time of that query with the query value.

From the given array, we can observe that:
-> We have to perform xor operation with all the elements before a type-2 query with that query value
-> q1 has to xor-ed with 1 and 2; q2 and q3 have to be xor-ed with 1,2 and 3; q4 to be xor-ed with 1,2,3,4,5,6, and 7
-> We can also see that, we have to do xor with only the previous elements that are already pushed to the array and not with those on right
-> Element 10 is xor-ed only qith q6; element 8 and 9 are xor-ed with q5 and q6; 4,5,6,7 with q4,q5,q6,q7, etc;

Therefore, we can simply iterate in reverse order and do the following operations:
-> If it is a type-1 query, then push the value which is xor of query value and xor_l (which maintains query xor values) into vect (a new array)
-> If it is a type-2 query, then xor_l=xor_l^(type-2 query value)
-> After the whole iteration, we can simply reverse the resultant vector vect, which is the required answer.
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> solve(vector<vector<ll>> &queries);

int main(int argc, char const *argv[])
{

	ll q;
	cin >> q;

	vector<vector<ll>> queries;

	for (int i = 0; i < q; i++)
	{
		ll l, r;
		cin >> l >> r;
		queries.push_back({l, r});
	}

	vector<int> ans = solve(queries);

	// Print answer:

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}


	return 0;
}

vector<int> solve(vector<vector<ll>> &queries)
{
	vector<int> vect;
	ll xor_v;
	bool check = false;

	for (int i = queries.size() - 1; i >= 0; i--)
	{
		if (queries[i][0] == 1)
		{
			if (!check)
			{
				vect.push_back(queries[i][1]);
			}
			else
			{
				vect.push_back(queries[i][1]^xor_v);
			}
		}
		else
		{
			if (!check)
			{
				xor_v = queries[i][1];
				check = true;
			}
			else
			{
				xor_v = xor_v ^ (queries[i][1]);
			}
		}
	}

	for (int i = 0; i < (vect.size() / 2); i++)
	{
		swap(vect[i], vect[vect.size() - i - 1]);
	}

	return vect;
}