/*************************************************************************
	> File Name: LeetCode102.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  2/29 15:20:25 2020
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int getDepth(struct TreeNode *root) {
     if (root == NULL) return 0;
     else {
        int n = getDepth(root->left);
        int m = getDepth(root->right);
        return (n > m ? n : m) + 1;
     }
 }

 void getCnt(struct TreeNode *root, int k, int *cnt) {
     if (root == NULL) return ;
     cnt[k] += 1;
     getCnt(root->left, k + 1, cnt);
     getCnt(root->right, k + 1, cnt);
     return ;
 }

 void getResult(struct TreeNode *root, int k, int *cnt, int **ret) {    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;//cnt清零了
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);
    return ;
 }
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){//返回值是二维数组 return[ [  ] ];
    int depth = getDepth(root);
    int *cnt = (int *)calloc(sizeof(int), depth);//cnt为初始化第二纬度
    int **ret = (int **)malloc(sizeof(int *) * depth);
    getCnt(root, 0, cnt);//记录每层有几个节点
    for (int i = 0; i < depth; i ++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]); 
        cnt [i] = 0;//cnt[i]中记录每层节点数， 用完清零，节省空间
    }
    getResult(root, 0, cnt, ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}
