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
//46. Permutations: (all integers are unique)
//Given an array nums of distinct integers, return all the possible permutations.
//APPROACH 1: With visited array
void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, vector<bool>& vis) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }
    for (int i = 0;i < nums.size();i++) {
        if (!vis[i]) {
            path.push_back(nums[i]);
            vis[i] = true;
            backtrack(nums, ans, path, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
}
//APPROACH 2: By swapping original array
void perNew(int idx, vi& arr, vvi& ans) {
    if (idx == arr.size()) {
        ans.pb(arr);
        return;
    }
    for (int i = idx;i < arr.size();i++) {
        swap(arr[idx], arr[i]);
        perNew(idx + 1, arr, ans);
        swap(arr[idx], arr[i]);
    }
}

//47. Permutations II (contains duplicates)
//All possible unique permutations in any order.
//APPROACH: make freq map and use it for generating permutation
void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& path, unordered_map<int, int>& um) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }
    for (auto& it : um) {
        int num = it.first;
        int count = it.second;
        if (count == 0) continue;
        path.push_back(num);
        it.second -= 1;
        backtrack(nums, ans, path, um);
        path.pop_back();
        it.second = count;
    }
}

//51. N-Queens 
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

//APPROACH: Try all combinations , it is very much like pick and not pick approach, in this, we pick
// (i,j) cell and check if it is possible to put queen on that cell or not
//To check if it good cell, one way is to check both diagonally and axially. but another approach is
//like using visted array and we make it by taking benefit of symmetry.
//we don't need to check in all eigth direction , just in direction in which we have previously visited
// a particular 45deg diagonal can be identified if it passes through(row,col) cell by(row+col) 
// a particular 135deg diagonal can be identified if it passes through(row,col) cell by (n-1+col-row) 
// vector<int> flag_col(n,1),flag_45(2*n-1,1),flag_135(2*n-1,1);
void solve(int row, vector<vector<string>>& ans, vector<string>& grid, int n,
    vector<int>flag_col, vector<int>flag_45, vector<int>flag_135)
{
    if (row == n) { ans.push_back(grid); return; }

    for (int col = 0;col < n;i++) {
        if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) { // if good cell
            flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0; // mark visited
            grid[row][col] = 'Q';
            solve(row + 1, ans, grid, n, flag_cal, flag_45, flag135);
            flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1; // mark unvisited while backtracking
            grid[row][col] = '.';
        }
    }
}
//APPROACH:(LESS OPTIMISATION) checking in all three direction
void solve(std::vector<std::vector<std::string> >& res, std::vector<std::string>& nQueens, int row, int& n) {
    if (row == n) {
        res.push_back(nQueens);
        return;
    }
    for (int col = 0; col != n; ++col)
        if (isValid(nQueens, row, col, n)) {
            nQueens[row][col] = 'Q';
            solveNQueens(res, nQueens, row + 1, n);
            nQueens[row][col] = '.';
        }
}
bool isValid(std::vector<std::string>& nQueens, int row, int col, int& n) {
    //check if the column had a queen before.
    for (int i = 0; i != row; ++i)
        if (nQueens[i][col] == 'Q')
            return false;
    //check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (nQueens[i][j] == 'Q')
            return false;
    //check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (nQueens[i][j] == 'Q')
            return false;
    return true;
}

