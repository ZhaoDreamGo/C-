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
}BitTree,* BiTree; //BiTree ���Ǵ�������struct BitTree������
/*������������Ĳ�������֪�����½ṹ�����Ĺ�����������pNext���������������pNode��
Ҫ֪��pNode��ʾ�������͵������֣���ô�����ͱ���û�н�����ɵ�ʱ��
��������͵�������Ҳ�������ڣ�Ҳ����˵���ʱ���������������ʶpNode��*/

class Solution {
private:
    //���ڵ�
    BiTree mRoot;
    //�ڵ�����
    int size;
    //��ǰ�������ʽ�ݹ鴴��������
    BiTree create();
    //�ݹ�ʵ��ǰ�����
    void preOrder(BiTree root);
    //�ǵݹ�ʵ��ǰ�����
    void nonRec_preOrder(BiTree root);
    //�ݹ�ʵ���������
    void inOrder(BiTree root);
    //�ǵݹ�ʵ���������
    void nonRec_inOrder(BiTree root);
    //�ݹ�ʵ�ֺ������
    void postOrder(BiTree root);
    //�ǵݹ�ʵ�ֺ������
    void nonRec_postOrder(BiTree root);
    //�ǵݹ�ʵ�ֲ�α���
    void nonRec_levelOrder(BiTree root);
    //�ݹ�ʵ�ִݻ���(ǰ�����)
    void destroy(BiTree root);
    //�ݹ�õ����Ľڵ���
    int getSize(BiTree root);
    //�ݹ�õ����ĸ߶�
    int getHeight(BiTree root);
    //�õ�Ҷ�ӽڵ�ĸ���
    int getLeafs(BiTree root);
    //�õ���Ϊ1�Ľڵ����
    int getOneLeafs(BiTree root);
    //�õ����ڵ����
    int getFullLeafs(BiTree root);
    //��ȡ�� k ��Ľڵ���
    int getLevelSize(BiTree root, int level);
    //����ָ��ֵ�Ľڵ�
    BiTree findNode(BiTree root, ElemType value);

public:
    //��ǰ�������ʽ�ݹ鴴��������
    void createTree();
    //�ݹ�ʵ��ǰ�����
    void preOrder();
    //�ǵݹ�ʵ��ǰ�����
    void nonRec_preOrder();
    //�ݹ�ʵ���������
    void inOrder();
    //�ǵݹ�ʵ���������
    void nonRec_inOrder();
    //�ݹ�ʵ�ֺ������
    void postOrder();
    //�ǵݹ�ʵ�ֺ������
    void nonRec_postOrder();
    //�ݹ�ʵ�ֲ�α���
    void nonRec_levelOrder();
    //�ݹ�ʵ�ִݻ���(ǰ�����)
    void destroy();
    //�ݹ�õ����Ľڵ���
    int getSize();
    //�ݹ�õ����ĸ߶�
    int getHeight();
    //�õ�Ҷ�ӽڵ�ĸ���
    int getLeafs();
    //�õ���Ϊ1�Ľڵ����
    int getOneLeafs();
    //�õ����ڵ����
    int getFullLeafs();
    //��ȡ�� k ��Ľڵ���
    int getLevelSize(int level);
    //�ж��Ƿ�Ϊ��ȫ������
    bool isCompleteTree();
    //����ָ��ֵ�Ľڵ�
    BiTree findNode(ElemType value);
};