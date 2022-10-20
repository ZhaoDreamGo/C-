#include"1.h"
#include <iostream>



//private私有函数先序创建二叉树
BiTree Solution::create() {
    BiTree newNode = NULL;
    ElemType value; //此处 ElemType 应该是基本类型数据,若为自定义类型,请重载输入流
    cin >> value;
    //# 表示当前子树为空
    if (value == "#") {
        return NULL;
    }
    else {
        //递归创建左右子树，使用size记录数的节点
        size++;
        newNode = new BitTree(value); //类型不一样所以错了 创建根节点
        newNode->left = create();//创建左节点
        newNode->right = create();//创建右节点
    }
}
//共有函数
void Solution::createTree() {
    size = 0;
    //根节点起~~~~
    mRoot = create();
}


/*
前序遍历(递归 + 非递归)
私有 then 公有*/
void Solution::preOrder(BiTree root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void Solution::preOrder() {
    cout << "The result of the preorder traversal is " << endl;
    preOrder(mRoot);//根节点
    cout << endl;
}
//非递归实现前序遍历
void Solution::nonRec_preOrder(BiTree root) {
    if (root == NULL) {
        return;
    }
    //通过栈
    stack<BiTree> s;
    BiTree p = root;

    while (!s.empty()|| p != nullptr) {
        if (p != nullptr) {
            cout << p->data << endl;//根
            s.push(p);
            p = p->left;//左
        }
        else {
            p = s.top();
            p = p->right;
            s.pop();
        }
    }
}
void Solution::nonRec_preOrder() {
    cout << "The result of the non-recursive preorder traversal is " << endl;
    nonRec_preOrder(mRoot);
    cout << endl;
}


/*
中序遍历(递归 + 非递归)
*/
void Solution::inOrder(BiTree root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void Solution::inOrder() {
    cout << "The result of the in-order traversal is " << endl;
    inOrder(mRoot);
    cout << endl;
}
//非递归实现中序遍历
void Solution::nonRec_inOrder(BiTree root) {
    if (root == NULL) {
        return;
    }
    stack<BiTree> myStack;
    BiTree rt = root;
    while (rt != NULL || !myStack.empty()) {
        while (rt != NULL) {
            myStack.push(rt);
        }
        rt = myStack.top();
        myStack.pop();
        cout << rt->data << " ";
        rt = rt->right;
    }
}
void Solution::nonRec_inOrder() {
    cout << "The result of the non-recursive in-order traversal is " << endl;
    nonRec_inOrder(mRoot);
    cout << endl;
}

/*
后序遍历(递归 + 非递归)
*/
void Solution::postOrder(BiTree root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void Solution::postOrder() {
    cout << "The result of the postorder traversal is " << endl;
    postOrder(mRoot);
    cout << endl;
}
//非递归实现后序遍历,双栈法
/*
    栈 s1 入栈顺序：根节点-> 左节点-> 右节点
    栈 s2 入栈顺序：右节点-> 左节点-> 根节点
    出栈顺序：根节点-> 左节点-> 右节点
*/
void Solution::nonRec_postOrder(BiTree root) {
    if (root == NULL) {
        return;
    }
    stack<BiTree> s1;
    stack<BiTree> s2;
    s1.push(root);
    while (!s1.empty()) {
        BiTree p = s1.top();
        s1.pop();
        s2.push(p);
        if (p->left) {
            s1.push(p->left);
        }
        if (p->right) {
            s1.push(p->right);
        }
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
void Solution::nonRec_postOrder() {
    cout << "The result of the non-recursive postorder traversal is " << endl;
    nonRec_postOrder(mRoot);
    cout << endl;
}

//非递归实现层次遍历
void Solution::nonRec_levelOrder(BiTree root) {
    queue<BiTree> q;
    q.push(root);
    while (!q.empty()) {
        //每层的节点
        int num_level = q.size();
        while (num_level--) {
            BiTree node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
}
void Solution::nonRec_levelOrder() {
    cout << "The result of the non-recursive sequence traversal is " << endl;
    nonRec_levelOrder(mRoot);
    cout << endl;
}


int main()
{
    Solution tree;
    cout << "Please enter the tree in the previous order traversal mode.If the node is empty,use # instead:" << endl;
    tree.createTree();
    cout << &tree << endl;
    tree.preOrder();
    return 0;
}

