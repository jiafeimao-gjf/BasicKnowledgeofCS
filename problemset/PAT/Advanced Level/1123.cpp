#include <cstdio>
#include <vector>//��̬����ģ�� 
#include <queue>//˫�˶���ģ�� 
//��ȫ��������ǰn-1����һ���������������һ��Ľڵ㶼����������� 
//�������� 
using namespace std;
vector<int> levelOrder(struct Node* tree);//���������� 
struct Node{ //���Ľ��ṹ������ ��ָ�붨�巨 
	int val;
	struct Node *left,*right;
};
struct Node* leftRotate(struct Node *tree){//�������� 
	printf("%d������\n",tree->val); 
	//���������������ϰ���������ϰ���������������֣�������Ϊ�����ϰ� 
	struct Node *temp = tree->right;//�����������쵼Ȩ 
	tree->right = temp->left;//�������������� 
	temp->left = tree;//�����������׹�Ϊ������ 
	return temp;//���������� 
} 
struct Node* rightRotate(struct Node* tree){//��������
	printf("%d������\n",tree->val);
	struct Node* temp = tree->left;//�����������쵼Ȩ 
	tree->left = temp->right;//�������������� 
	temp->right = tree;//�����������׹�Ϊ������ 
	return temp;//���������� 
}
int getHeight(struct Node *tree){//�ݹ������tree�ڵ�ĸ߶� 
	if(tree == NULL) return 0;//treeΪ�սڵ㣬���ظ߶�Ϊ0���˳��ݹ� 
	int l = getHeight(tree->left);//�ݹ����������ĸ߶� 
	int r = getHeight(tree->right);//�ݹ����������ĸ߶� 
	return l > r ? l + 1 : r + 1;//���ؽϸߵ��Ǹ����� 
}
struct Node* leftRightRotate(struct Node* tree){//������������ 
	printf("%d��������\n",tree->val);
	tree->left = leftRotate(tree->left);//���������� 
	tree = rightRotate(tree);//���Լ����� 
	return tree;
}
struct Node* rightLeftRotate(struct Node* tree){//������������ 
	printf("%d��������\n",tree->val);
	tree->right = rightRotate(tree->right);//���Һ������� 
	tree = leftRotate(tree);//���Լ����� 
	return tree;
}
struct Node* insert(struct Node* tree,int val){//�ݹ���Ҳ����㷨 
	if(tree == NULL){//�սڵ㿪�ٿռ䣬��ֵ������ 
		tree = new struct Node();
		tree->val = val;
		return tree;
	}
	if(tree->val > val){//Ӧ���������� 
		tree->left = insert(tree->left,val);
		//��ȡ���������ĸ߶� 
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		//ֻ��������ҵ� 
		if(l - r >= 2){ //����������ȱ���������2 
			//����Ԫ�ص�ֵС����������ֵ�������������� 
			if(val < tree->left->val) {
				printf("%d����������\n",val);
				tree = rightRotate(tree);
			} 
			//������������������������� 
			else {
				printf("%d������������\n",val);
				tree = leftRightRotate(tree);
			} 
		}
	} else{//Ӧ���������� 
		tree->right = insert(tree->right,val);
		int l = getHeight(tree->left);
		int r = getHeight(tree->right);
		if(r - l >= 2){
			if(val > tree->right->val) {
				printf("%d����������\n",val);
				tree = leftRotate(tree);
			}
			else {
				printf("%d������������\n",val);
				tree = rightLeftRotate(tree);
			}
		}	
	}
	return tree;
}
int isComplete = 1,after = 0;//after��ǵ�һ������Ϊ�յ�ʱ�� 
//���ݲ�����ϵ��£��������ҵ��ص㣬��after��ǵ�һ�����ӻ����Һ���Ϊ�յĽڵ� 
vector<int> levelOrder(struct Node* tree){//������� 
	vector<int> v;
	queue<struct Node*> q;
	q.push(tree);
	while(q.size() != 0){//���в�Ϊ�� 
		//����Ԫ�س��� 
		struct Node* temp = q.front();
		q.pop();
		v.push_back(temp->val);
		
		if(temp->left !=  NULL){//������� 
			if(after) isComplete = 0;
			q.push(temp->left);
		} else{//����Ϊ�գ���ʣ�����нڵ�����Һ��Ӷ�Ϊ�գ�����ǰ״̬������ȫ̬ 
			after = 1;
		}
		if(temp->right != NULL){//�Һ������
			if(after) isComplete = 0;
			q.push(temp->right);
		}else{//������Ϊ�գ���ʣ�����нڵ�����Һ��Ӷ�Ϊ�գ�����ǰ״̬������ȫ̬ 
			after = 1;
		}
	}
	return v;
}
int main(){
	int n = 0;
	scanf("%d",&n);
	struct Node* tree = NULL;
	for(int i = 0;i < n;i++){
		int temp;
		scanf("%d",&temp);
		tree = insert(tree,temp);
	}
	vector<int> v = levelOrder(tree);
	for(int i = 0;i < v.size();i++){
		if(i != 0) printf(" ");
		printf("%d",v[i]);
	}
	printf("\n%s",isComplete?"YES":"NO");
	return 0;
}
