// Problem Statement Link: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381866

/*
My approach:

Let the final answer array be ans[n]
-> It is said that at ans[i] the value that should be stored is the product of all the elements of the array arr except arr[i]
-> This means that ans[i]=arr[0]*arr[1]*......*arr[i-1]*arr[i+1]*arr[i+2]*....*arr[n-1]
-> ans[i]=(arr[0]*arr[1]*......*arr[i-1])*(arr[i+1]*arr[i+2]*....*arr[n-1]) i.e., arr[i]= product of all the elements to the left of arr[i] and to the right of arr[i]

Therefore, we can implement the same as follows:
First store the value of product of left elements and then multiply them with product of right elements.

-> Declare an ans array of size n to store final answer
-> For every iteration of i from 0 to (n-1) store product of previous elements (left element) into ans[i]
-> Use a variable (lp) to keep track of the left elements products
-> In every iteration ans[i]=lp and upgrade lp as lp=lp*arr[i]
-> Then iterate in reverse order and repeat the same previous process, except that, rather than only storing the values, we multiply the right product value to the ans elements
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int *solve(int *arr, int n);

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}


	int *ans = solve(arr, n);

	// Print answer:

	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}


	return 0;
}

int *solve(int *arr, int n)
{
	int *ans = new int[n];
	int lp = 1, rp = 1;
	for (int i = 0; i < n; i++)
	{
		ans[i] = lp;
		lp = lp * arr[i];
	}
	for (int i = (n - 1); i >= 0 ; i--)
	{
		ans[i] *= rp;
		rp = rp * arr[i];
	}

	return ans;
}