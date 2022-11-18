// C++ program for the above approach
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

// Function to find maximum continuous
// maximum sum in the array
int kadane(vector<int> v)
{
	
	// Stores current and maximum sum
	int currSum = 0;
	int maxSum = INT_MIN;

	// Traverse the array v
	for (int i = 0;
		i < (int)v.size(); i++) {

		// Add the value of the
		// current element
		currSum += v[i];

		// Update the maximum sum
		if (currSum > maxSum) {
			maxSum = currSum;
		}

		if (currSum < 0) {
			currSum = 0;
		}
	}

	// Return the maximum sum
	return maxSum;
}

int maxSubmatrixSum(
	vector<vector<int> > A)
{
	int r = A.size();
	int c = A[0].size();

	int maxSum = INT_MIN;

		for(int i=0;i<r;i++){
			for(int s=r;s>i;s--){
					vector<int> v;
				for (int j = 0; j < c; j++) {
				int el = 0;
					for (int k = i; k < s; k++) {
							el+= A[k][j];	
							}
					v.push_back(el);
					}
			maxSum = max(maxSum, kadane(v));
			}
		}
	cout<<maxSum<<endl;

		return maxSum;
}

// Driver Code
int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");
	int r,c;
	in>>r;
	in>>c;
	vector<vector<int>> A(r,vector <int>(c));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
				in>>A[i][j];
		}
	}
	out<<maxSubmatrixSum(A)<<"\n";
	return 0;
}

