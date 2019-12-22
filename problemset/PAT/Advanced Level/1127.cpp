//1127. ZigZagging on a Tree

// ˫�˶���ʵ��zigzag��α���������S��·��������� 
#include <cstdio>
#include <deque>//˫�˶���

/*
Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15

*/
struct Node//��̬���������±꼴value 
{
    int l, r;
    Node() {l=r=-1;}
};
Node t[1000];//�����±�Ϊ���ڵ�

int post[32];//�����������,���һ�����һ���Ǹ��ڵ�
int in[32];//�����������,

int build(int pl, int pr, int il, int ir)//���ݺ����ǰ��ݹ齨�������� 
//          ������ ������ ������ ������
{
    //12 11 20 17 1 15 8 5
    //12 20 17 11 15 8 5 1
    if (pl > pr) {//�ýڵ�Ϊ�� 
        return -1;
    }
    int p = il;//������������
    while(in[p] != post[pr])//û�ҵ���ͬ��Ԫ��
        p++;//��һ��Ԫ��
    int tree = post[pr];//��¼��ͬԪ�أ�5
    t[tree].l = build(pl,pr-ir+p-1,il,p-1);//�ݹ齨�������� 
    t[tree].r = build(pr-ir+p,pr-1,p+1,ir);//�ݹ齨�������� 
    return tree;//���ز�Ϊ�յĽڵ� 
}

void zigzag(int root)
{
    bool flag = true;//���ʲô�� ����������false��������,true�������� 
    std::deque<int> q;
    q.push_front(root);//�����ڵ�ѹ��˫�˶���ǰ�� 
    q.pop_front();//��˫�˶��� 
    printf("%d", root);//�����һ��Ԫ�أ����ڵ� 
    if (t[root].r != -1) q.push_back(t[root].r);//�������� 
    if (t[root].l != -1) q.push_back(t[root].l);//�������� 
    while(!q.empty()) {//���зǿ� 
        int sz = q.size();
        flag = !flag;
        while(sz--) {
            if (flag) { // right 2 left
                int p = q.front();
                q.pop_front();
                printf(" %d", p);
                if (t[p].r != -1) q.push_back(t[p].r);//�Һ�������� 
                if (t[p].l != -1) q.push_back(t[p].l);
            } else { // left 2 right
                int p = q.back();
                q.pop_back();
                printf(" %d", p);
                if (t[p].l != -1) q.push_front(t[p].l);//��������� 
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
