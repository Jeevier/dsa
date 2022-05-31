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



//Bit Manipulation

//1461. Check If a String Contains All Binary Codes of Size K

//APPROACH 1: 
//1.There are 2^k binary codes in size of k from 0 to 2^k-1;
//2.We can generate all the substring of size k and put them in set;
//3.Check if size of set is 2^k or not, if yes return true else false;
//TC:O(nk) SC:O(nk)

//APPROACH 2: Rolling Hash Technique
//1.Generating the substring is somewhat time consuming as it is done in O(nk) time;
//2.We can hash a substring by its decimal value and generate a hash from hash of previous substring
//https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/2092553/Explaining-the-Rolling-Hash-Method-or-Guide
//TC:O(n) SC:(2^k) , In space only storing numbers
bool hasAllCodes(string s, int k) {
    if (s.size() < k) return false;
    int total = 1 << k, allOnes = total - 1, hash = 0;
    unordered_set<int> um;
    for (int i = 0;i < s.size();i++) {
        hash = (((hash << 1) & allOnes) | (s[i] - '0'));
        if (i >= k - 1 && um.find(hash) == um.end()) {
            um.insert(hash);
            if (total == um.size()) break;
        }
    }
    return false;
}

//29. Divide Two Integers(divide two numbers without mod, div,multi)
//APPROACH:1 
//Subtract dividend by divisor till dividend is greater than divisor and increment quotient
//It gives TLE

//APPROACH:2 
//Quotient is a number and we can represent in binary
// Suppose
// 29=(9)*3 +2
// 29=(2^3 + 2^0)*3 +2
// 29-(2^3)*3= (2^0)*3 +2
// https://leetcode.com/problems/divide-two-integers/discuss/1516367/Complete-Thinking-Process-or-Intuitive-Explanation-or-All-rules-followed-or-C%2B%2B-code
int divide(int A, int B) {
    if (A == INT_MIN && B == -1) return INT_MAX;
    long int a = abs(A), b = abs(B), res = 0;
    for (int x = 31; x >= 0; x--)
        if (a - (b << x) >= 0)
            res += 1 << x, a -= b << x;
    return (A > 0) == (B > 0) ? res : -res;
}