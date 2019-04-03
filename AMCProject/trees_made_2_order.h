//
//  trees_made_2_order.h
//  AMCProject
//
//  Created by ios on 2019/3/7.
//  Copyright © 2019 ios. All rights reserved.
//

#ifndef trees_made_2_order_h
#define trees_made_2_order_h

typedef struct treeNode {
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;

/* 中序遍历 */
void printTreeWithInOrder(TreeNode* root) {
    if (root == NULL) return;
    printf("(");
    printTreeWithInOrder(root->left);
    printf(")X(");
    printTreeWithInOrder(root->right);
    printf(")");
}

/* 左子树为空时，右子树变化;
 右子树变化完成，右子树节点-1给左子树，左右子树成初始状态
 左子树变化完成，左子树变空，右子树变成初始状态且总节点树+1 */
void getLeaf(TreeNode* node) {
    if (node->left == NULL && node->right == NULL) return; /* node是个叶子结点 */
    if (node->right != NULL)
        getLeaf(node->right);
    else
        getLeaf(node->left);
}

void createNode(TreeNode* node, const int i) {
    if (i == 1) return;
    getLeaf(node);
}

void trees_made_2_order() {
#ifdef PRINT_FLAG
    printf("problem Trees Made to Order problemCode=1062\n");
    printf("please input an int(1~500000000):\n");
#endif
    while(1) {
        int n;
        scanf("%d", &n);
        
        if (n == 0) break;
        TreeNode* tree = (TreeNode*)malloc(sizeof(TreeNode));
        tree->left = NULL;
        tree->right = NULL;
        int i;
        for (i = 1;i < n; n++) {
            createNode(tree, i);
            printTreeWithInOrder(tree);
        }
    }
}

#endif /* trees_made_2_order_h */
