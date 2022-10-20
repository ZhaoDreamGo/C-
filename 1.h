#pragma once
#include<stdio.h>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef string ElemType;

typedef struct BitTree {
    ElemType data;
	BitTree* left, * right;
    BitTree(ElemType x) { data = x;  left = NULL; right = NULL; };
}BitTree,* BiTree; //BiTree 才是代表整个struct BitTree的名字
/*根据我们上面的阐述可以知道：新结构建立的过程中遇到了pNext域的声明，类型是pNode，
要知道pNode表示的是类型的新名字，那么在类型本身还没有建立完成的时候
，这个类型的新名字也还不存在，也就是说这个时候编译器根本不认识pNode。*/

class Solution {
private:
    //根节点
    BiTree mRoot;
    //节点总数
    int size;
    //按前序遍历方式递归创建二叉树
    BiTree create();
    //递归实现前序遍历
    void preOrder(BiTree root);
    //非递归实现前序遍历
    void nonRec_preOrder(BiTree root);
    //递归实现中序遍历
    void inOrder(BiTree root);
    //非递归实现中序遍历
    void nonRec_inOrder(BiTree root);
    //递归实现后序遍历
    void postOrder(BiTree root);
    //非递归实现后序遍历
    void nonRec_postOrder(BiTree root);
    //非递归实现层次遍历
    void nonRec_levelOrder(BiTree root);
    //递归实现摧毁树(前序遍历)
    void destroy(BiTree root);
    //递归得到树的节点数
    int getSize(BiTree root);
    //递归得到树的高度
    int getHeight(BiTree root);
    //得到叶子节点的个数
    int getLeafs(BiTree root);
    //得到度为1的节点个数
    int getOneLeafs(BiTree root);
    //得到满节点个数
    int getFullLeafs(BiTree root);
    //获取第 k 层的节点数
    int getLevelSize(BiTree root, int level);
    //查找指定值的节点
    BiTree findNode(BiTree root, ElemType value);

public:
    //按前序遍历方式递归创建二叉树
    void createTree();
    //递归实现前序遍历
    void preOrder();
    //非递归实现前序遍历
    void nonRec_preOrder();
    //递归实现中序遍历
    void inOrder();
    //非递归实现中序遍历
    void nonRec_inOrder();
    //递归实现后序遍历
    void postOrder();
    //非递归实现后序遍历
    void nonRec_postOrder();
    //递归实现层次遍历
    void nonRec_levelOrder();
    //递归实现摧毁树(前序遍历)
    void destroy();
    //递归得到树的节点数
    int getSize();
    //递归得到树的高度
    int getHeight();
    //得到叶子节点的个数
    int getLeafs();
    //得到度为1的节点个数
    int getOneLeafs();
    //得到满节点个数
    int getFullLeafs();
    //获取第 k 层的节点数
    int getLevelSize(int level);
    //判断是否为完全二叉树
    bool isCompleteTree();
    //查找指定值的节点
    BiTree findNode(ElemType value);
};