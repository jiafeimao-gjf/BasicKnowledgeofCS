//1127. ZigZagging on a Tree

// 双端队列实现zigzag层次遍历，按照S型路径遍历输出 
#include <cstdio>
#include <deque>//双端队列

/*
Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15

*/
struct Node//静态二叉树，下标即value 
{
    int l, r;
    Node() {l=r=-1;}
};
Node t[1000];//数组下标为父节点

int post[32];//后序遍历序列,最后一个结点一定是根节点
int in[32];//中序遍历序列,

int build(int pl, int pr, int il, int ir)//根据后序和前序递归建立二叉树 
//          后序左 后序右 中序左 中序右
{
    //12 11 20 17 1 15 8 5
    //12 20 17 11 15 8 5 1
    if (pl > pr) {//该节点为空 
        return -1;
    }
    int p = il;//辅助变量等于
    while(in[p] != post[pr])//没找到相同的元素
        p++;//下一个元素
    int tree = post[pr];//记录相同元素，5
    t[tree].l = build(pl,pr-ir+p-1,il,p-1);//递归建立左子树 
    t[tree].r = build(pr-ir+p,pr-1,p+1,ir);//递归建立右子树 
    return tree;//返回不为空的节点 
}

void zigzag(int root)
{
    bool flag = true;//标记什么？ 标记输出方向：false从左至右,true从右至左 
    std::deque<int> q;
    q.push_front(root);//将根节点压入双端队列前面 
    q.pop_front();//出双端队列 
    printf("%d", root);//输出第一个元素，根节点 
    if (t[root].r != -1) q.push_back(t[root].r);//先右子树 
    if (t[root].l != -1) q.push_back(t[root].l);//再左子树 
    while(!q.empty()) {//队列非空 
        int sz = q.size();
        flag = !flag;
        while(sz--) {
            if (flag) { // right 2 left
                int p = q.front();
                q.pop_front();
                printf(" %d", p);
                if (t[p].r != -1) q.push_back(t[p].r);//右孩子先入队 
                if (t[p].l != -1) q.push_back(t[p].l);
            } else { // left 2 right
                int p = q.back();
                q.pop_back();
                printf(" %d", p);
                if (t[p].l != -1) q.push_front(t[p].l);//左孩子先入队 
                if (t[p].r != -1) q.push_front(t[p].r);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    build(0, n-1, 0, n-1);
    int root = post[n-1];
    zigzag(root);
    return 0;
}
