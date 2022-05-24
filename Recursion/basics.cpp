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
// APPROACH: 1 BY LOOPING and check duplicates by comparing adjacents(because we do the sort first)
void help(int idx, vector<int>& nums, vector<int>& path, vector<vector<int>>& ans) {
    ans.push_back(path);
    for (int i = idx;i < nums.size();i++) {
        if (i != idx && nums[i] == nums[i - 1]) continue;
        path.push_back(nums[i]);
        help(i + 1, nums, path, ans);
        path.pop_back();
    }
}

//39. Combination Sum: (all unique integers)
//# Get unique combinations of candidates where the chosen numbers sum to target 
//# The same number may be chosen from candidates an unlimited number of times.
void dfs(int i, int sum, vector<int>& candidates, vector<int>& path, int target, vector<vector<int>>& ans) {
    if (target == sum) {
        ans.push_back(path);
        return;
    }
    if (i >= candidates.size() || sum > target) return;

    for (int j = i;j < candidates.size();j++) {
        path.push_back(candidates[j]);
        dfs(j, sum + candidates[j], candidates, path, target, ans);
        path.pop_back();
    }
}
//40. Combination Sum II (duplicates allowed)
//# All unique combinations in candidates where the candidate numbers sum to target.
//# Each number in candidates may only be used once in the combination.
// APPROACH: BY LOOPING and check duplicates by comparing adjacents(because we do the sort first)
void dfs(int idx, int sum, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& ans) {
    if (target == sum) {
        ans.push_back(path);
        return;
    }
    for (int i = idx;i < candidates.size();i++) {
        if (i > idx && candidates[i] == candidates[i - 1]) continue;
        if (sum + candidates[i] > target) break;
        path.push_back(candidates[i]);
        dfs(i + 1, sum + candidates[i], target, candidates, path, ans);
        path.pop_back();
    }
}
