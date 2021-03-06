#include <bits/stdc++.h>
using namespace std;

vector<bool> subsetSum(vector<int>& arr, int sum, int n){
	vector<vector<bool> > dp(n+1, vector<bool>(sum+1,false));
	for(int i=0;i<n+1;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp.back();
}

int minSubsetSumDifference(vector<int>& arr, int n){
	int sum=0, minDiff=INT_MAX;
	vector<bool> v;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	v=subsetSum(arr,sum,n);
	for(int i=0; i<v.size()/2;i++){
		if(v[i])
			minDiff=min(minDiff, sum-(2*i));
	}
	return minDiff;
}

int main(void){
	int n,sum;
	cout<<"Size:";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter Elements:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"\nMinimum Subset Sum Difference: "<<minSubsetSumDifference(arr,n);
	return 0;
}
