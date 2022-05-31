#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define e endl
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
//Arrays

//41. First Missing Positive

 int firstMissingPositive(vector<int>& nums) {
        //range of ans : 1 - n+1
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n) nums[i]=n+1; // having them in range
        }
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            if(num>n) continue;
            if(nums[num-1]>0) nums[num-1]=(-1)*nums[num-1]; //mark them -ve(0-based indexing)
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0) return i+1; //first positve number is our answer
        }
        return n+1;
    }