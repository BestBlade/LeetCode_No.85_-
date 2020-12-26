/* ------------------------------------------------------------------|
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 

示例 1：


输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
示例 2：

输入：matrix = []
输出：0
示例 3：

输入：matrix = [["0"]]
输出：0
示例 4：

输入：matrix = [["1"]]
输出：1
示例 5：

输入：matrix = [["0","0"]]
输出：0
 

提示：

rows == matrix.length
cols == matrix[0].length
0 <= row, cols <= 200
matrix[i][j] 为 '0' 或 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximal-rectangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*
*
*	执行用时：64 ms, 在所有 C++ 提交中击败了61.37%的用户
*	内存消耗：13.2 MB, 在所有 C++ 提交中击败了26.69%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int res = 0;
    vector<int> left(n);
    vector<int> right(n, n);
    stack<int> pos;

    for (int i = 0; i < n; i++) {
        while (!pos.empty() && heights[i] <= heights[pos.top()]) {
            right[pos.top()] = i;
            pos.pop();
        }
        left[i] = pos.empty() ? -1 : pos.top();
        pos.emplace(i);
    }

    for (int i = 0; i < n; i++) {
        res = max(heights[i] * (right[i] - left[i] - 1), res);
    }
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    vector<int> sum(matrix[0].size(), 0);
    int res = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            sum[j] = (matrix[i][j] == '1') ? 1 + sum[j] : 0;
        }
        res = max(res, largestRectangleArea(sum));
    }
    return res;    
}