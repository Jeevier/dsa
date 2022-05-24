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

//Recursion

// 78. Subsets : Get all unique subsets(all elements are unique)
// APPROACH:1 BY LOOPING and Pick/Not Pick
void printSub(int idx, vi& arr, vi& path, vvi& ans) {
    ans.pb(path);
    for (int i = idx;i < arr.size();i++) {
        path.pb(arr[i]);
        printSub(i + 1, arr, path, ans);
        path.pop_back();
    }
}
// APPROACH:2 BY Pick and Not Pick
void printSub(int idx, vi& arr, vi& path, vvi& ans) {
    if (idx == arr.size()) {
        ans.pb(path);
        return;
    }
    path.pb(arr[idx]);
    printSub(idx + 1, arr, path, ans);
    path.pop_back();
    printSub(idx + 1, arr, path, ans);
}

// 90. Subsets II : Get all unique subsets(duplicates allowed)
// APPROACH: 1 BY LOOPING and check duplicates by comparing adjacents
void help(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
    ans.push_back(path);
    for (int i = idx;i < nums.size();i++) {
        if (i != idx && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        help(i + 1, nums, path, ans);
        path.pop_back();
    }
}

