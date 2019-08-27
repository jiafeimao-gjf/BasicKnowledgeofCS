## 红黑树
> 对原来的平衡二叉树的改进，保证提高插入、删除操作的效率
### 性质
1. 根节点为黑色
2. 所有空的叶子节点算黑色节点
3. 根节点到每个叶子节点（null）的路径中具有相同的黑色节点
4. 红色节点的子节点必须为黑色
5. 每个节点要么是红色，要么是黑色。
6. 新插入的节点为红色。
### 左右旋操作
> R 是 node 的右孩子
> p 是 node 的父亲节点
1. 左旋
- right 顶替 node 的位置（注意node是否是根节点，同时注意node 是）
- right 认 P 为父节点
- node 认 right 为 父节点 （注node是）
- node 认 right 的左孩子 为右孩子
- right.left != null 时， right 的左孩子 认 node 为父节点
- rigth 认 node 为新的左孩子
2. 右旋
- left 顶替 node 的位置
- left 认 新的父节点
- node 认 left 为新的父节点
- node 认 left的右孩子为左孩子- right.right != null 时； 
- left 的右孩子 认 node 为父节点
- left 认 node 为右孩子

### 插入的理解
> S 为 son，F 为 father，G 为 grandpa，U 为 uncle
1. 插入目标节点：
- 查找到合适插入的叶子节点处，插入节点
- 修复插入导致的不平衡
2. 修复插入导致的不平衡：
- case0：F 为 黑色，不用修复
- case1：F 为 红，U 为 红
    - 操作：将F以及U设置为黑，G设为红，并将G看成新插入的节点（即下一轮的S），递归操作。（因为曾祖父（G的F）可能是红色节点）
- case2：F为红色，U为黑色，S为F的右孩子。
    - 操作：对F左旋，F变成下一轮修复目标(F 变成 S)。符合case3, 进入case3处理。
- case3：F为红，uncle 为黑，S为F的左孩子。
    - 操作：将F设置为黑色，G设置为红色，然后对G右旋。
### 删除的理解
1. 删除目标节点node
- node左右子树不为空，递归node的子节点，找到右子树的最小（左）节点Ng，将Ng与node交换，递归处理Ng
- 是否是根节点的处理。
2. 修复删除导致的不平衡
> B为 brother
- case1:  S 、F 是 黑色色，B 为红色
    - 操作：将P设为红色，B为黑色，然后将P左旋，这时S有了新B，用的新的B 进行后序操作
    - 原因：在这种情况下，我们可以得到P必定为黑，并且BL & BR 也都为黑。由于我们想要左旋，而又不能破坏红黑树的平衡，所以，将P设为红，B设为黑。左旋的目的是让S有新的B，从而转化为后面的case 2 or 3 or 4，进行下一步的操作。
- case2: S、F为黑色，B也为黑色，并且BL、BR也都是黑色
    - 操作：将B设为红，并且让F为新的S，进行新一轮的递归
    - 原因：我们的目的就是想让多余的黑往上走，这时候，把这个多余的黑给到P，左边路的黑是不变的，而右边路多了一个，为了平衡，恰好BL BR都是黑，所以我们直接把B设为红就好啦，这样，黑就上浮到了P，将P看作新的起点，递归后面的操作就好啦~！
- case3: S、F 为黑，且B为黑，并且BL为红，BR为黑
    - 操作：将B设为红，BL设为黑，然后B右旋
    - 原因：这个操作是为了转换到case4。B和BL的颜色互换也是为了平衡
- case4：S 是黑色，F 红或黑，且B为黑色，BR为红色，BL为任意颜色
    -  操作：将F的颜色给B，将P设为黑色，将BR设为黑，对F左旋，最后将S设置为root以结束循环
    - 原因：这是最复杂的一种情况了。我们将P的颜色给到B，然后将P左旋，这时候，不管P初始是什么颜色，对于左边路来说，都多了一个黑色，为了保证颜色平衡，正好把S中多余的那个黑丢掉啦！但是左旋带来了一些后遗症，首先是BL变成了P的儿子，而这里我们不关心BL的颜色，所以，必须要把P设置为黑色，这样即使BL为红色也不会破坏红黑树，还有一点，不管P的初始颜色，左旋之后，右边路少了一个黑，为了补回来，我们让BR由红变黑就好啦！这就是完整的操作，**精髓在于通过左旋P来消除多余的那个黑色，但由于左旋带来的后遗症需要相应的`改变颜色`措施来弥补。**


## 红黑树 Java 实现

```java

import java.util.Objects;

// 节点类型定义

public class RBTreeNode {
    // 节点颜色标记
    private final static Boolean RED = false;
    private final static Boolean BLACK = true;
    // 节点的值
    private int key;
    // 节点的颜色
    private boolean color;
    // 左右子节点、双亲节点的引用
    private RBTreeNode left;
    private RBTreeNode right;
    private RBTreeNode parent;

    public RBTreeNode(int key) {
        this.key = key;
        this.color = RED;// 新的节点为红色节点
    }
    // get set 函数 
    public int getKey() {
        return key;
    }

    public void setKey(int key){
        this.key = key;
    }

    public boolean getColor() {
        return color;
    }

    public void setColor(boolean color) {
        this.color = color;
    }

    public RBTreeNode getLeft() {
        return left;
    }

    public void setLeft(RBTreeNode left) {
        this.left = left;
    }

    public RBTreeNode getRight() {
        return right;
    }

    public void setRight(RBTreeNode right) {
        this.right = right;
    }

    public RBTreeNode getParent() {
        return parent;
    }

    public void setParent(RBTreeNode parent) {
        this.parent = parent;
    }

    // 重写toString函数
    @Override
    public String toString(){
        return "RBTreeNode {" +
                ",key = " + key +
                ",color = " +color + 
                "}";
    }
}

public class RBTree {
    RBTreeNode root;
    private final static REB = false;
    private final static BLACK = true;

    // 二分查找目标节点
    public RBTreeNode query(int key) {
        RBTreeNode tmp = root;
        while(tmp != null) {
            if (tmp.getKey() == key) {
                return tmp;
            } else if (tmp.getKey() > key) {
                tmp = tmp.getLeft();
            } else {
                tmp = tmp.getRight();
            }
        }
        return null;
    }

    // 插入新的节点
    public void insert(int key) {
        RBTreeNode node =  new RBTreeNode(key);
        // 红黑树为空，初始化根节点
        if (root == null) {
            root = node;
            node.setColor(BLACK);
            return;
        }

        RBTreeNode parent = root;
        RBTreeNode son = null;          // 子树节点，插入以这棵子树为目标
        // 插入进一步划分子树
        if (key <= parent.getKey()) {
            son = parent.getLeft();
        } else {
            son = parent.getRight();
        }

        // 找到插入位置，位置都在叶子节点处
        while (son != null) {
            parent = son;
            if (key <= parent.getKey()) {
                son = parent.getLeft();
            } else {
                son = parent.getRight();
            }
        }

        // 插入新的节点，parent 认新的孩子节点
        if (key <= parent.getKey()) {
            parent.setLeft(node);
        } else {
            parent.setRight(node);
        }
        node.setParent(parent);// node 认 父节点

        // 红黑树插入修复
        insertFix(node);
    }

    // 红黑树插入修复
    private void insertFix(RBTreeNode node) {
        RBTreeNode father,grandPa;
        // 插入节点的父节点存在（插入节点不是根节点），且插入节点的父节点为红色
        while ((father = node.getParent()) != null && father.getcolor() == RED) {
            grandPa = father.getParent();
            if (grandPa.getLeft() == father) {// 插入节点的爸爸是爷爷的左儿子
                RBTreeNode Uncle = grandPa.getRight();
                if (uncle != null && uncle.getColor() == RED) {
                    setBlack(father);
                    setBlack(uncle);
                    setRed(grandPa);
                    continue;
                }
                if (node == father.getRight()) {
                    LeftRotate(father);         // 左旋操作
                    RBTreeNode tmp = node;
                    node = father;
                    father = tmp;
                }
                setBlack(father);
                serRed(grandPa);
                rightRotate(grandPa);
            } else {    // 插入节点的爸爸是爷爷的右儿子
                RBTreeNode uncle = grandPa.getLeft();
                if (uncle != null && uncle.getColor() == RED) {
                    setBlack(father);
                    setBlack(uncle);
                    setRed(grandPa);
                    node = grandPa;
                    continue;
                }
                if (node == father.getLeft()) {
                    rightRotate(father);
                    RBTreeNode tmp = node;
                    node = father;
                    father = tmp;
                }
                setBlack(father);
                setRed(grandPa);
                leftRotate(grandPa);
            }
        }
        setBlack(root);
    }

    // 删除值为key的节点
    public void delete(int key) {
        delete(query(key));
    }

    private void delete(RBTreeNode node) {
        if (node == null) {
            return;
        }

        // 节点删除转换
        if (node.getLeft() != null && node.getRight() != null) {
            RBTreeNode replaceNode = node;
            RBTreeNdde tmp = node.getRight();// 右子树
            // 找到右子树的最左节点
            while (tmp != null) {
                replaceNode = tmp;
                tmp = tmp.getLeft();
            }
            // 删除节点转换，由当前节点转换成右子树的最左非空节点
            int t = replaceNode.getKey();
            repalceNode.setKey(node.getKey());
            node.setkey(t);
            // 递归删除，问题转换
            delete(replaceNode);
            return;
        }

        RBTreeNode replaceNode = null;
        if (node.getLeft() != null) {
            replaceNode = node.getLeft();
        } else {
            replaceNode = node.getRight();
        }

        RBTreeNode parent = node.getParent();
        if (parent == null) { // node 为root
            root = replaceNode;
            if (repalceNode != null) {
                replaceNode.setParent(null);
            }
        } else {
            if (replaceNode != null) {
                replaceNode.setParent(null);
            } 
            if (parent.getLeft() == node) {// node is left
                parent.setLeft(replaceNode);
            } else { // node is right
                parent.setRight(replaceNode);
            }
        }
        if (node.getColor() == BLACK) {
            removeFix(parent,replaceNode);
        }
    }

    // 删除修复
    private void removeFix(RBTreeNode father,RBTreeNode node) {
        // 节点为黑，才需要进行修复，保证满足性质
        while ((node == null || node.getColor() == BLACK) && node != root) {
            if (father.getLeft() == node) {
                RBTreeNode brother = father.getRight();
                if (brother != null && brother.getColor() == RED) {
                    setRed(father);
                    setBlack(brother);
                    leftRotate(father);
                    brother = father.getRight();
                }
                if (brother == null || (isBlack(brother.getLeft()) && isBlack(brother.getRight()))) {
                    setRed(brother);
                    node = father;
                    father = node.getParent();
                    continue;
                }
                if (isRed(brother.getLeft())) {
                    setBlack(brother.getLeft());
                    setRed(brother);
                    rightRotate(brother);
                    brother = brother.getParent();
                }

                brother.setColor(father.getColor());
                setBlack(father);
                setBlack(brother.getRight());
                leftRotate(father);
                node = root;// 跳出循环
            } else {
                RBTreeNode brother = father.getLeft();
                if (brother != null && brother.getColor() == RED) {
                    setRed(father);
                    setBlack(brother);
                    rightRotate(father);
                    brother = father.getLeft();
                }
                if (brother == null || (isBlack(brother.getLeft()) && isBlack(brother.getRight()))) {
                    setRed(brother);
                    node = father;
                    father = node.getParent();
                    continue;
                }
                if (isRed(brother.getRight())) {
                    setBlack(brother.getRight());
                    setRed(brother);
                    leftRotate(brother);
                    brother = brother.getParent();
                }

                brother.setColor(father.getColor());
                setBlack(father);
                setRed(brother);
                rightRotate(father);
                node = root;// 跳出循环
            }
        }
        if (node != null) {
            node.setColor(BLACK);
        }
    }

    private boolean isBlack(RBTreeNode node) {
        if (node == null) {
            return true;
        }
        return node.getColor() == BLACK;
    }

    private boolean isRed(RBTreeNode node) {
        if (node == null) {
            return false;
        }
        return node.getColor() == RED;
    }

    // 左旋，node 是左旋的目标节点，right是node的右孩子，一共六步：
    /*
        1、right 顶替 node 的位置
        2、right 认 父节点
        3、node 认 right 为 父节点 
        4、node 认 right 的左孩子 为右孩子
        5、right.left != null 时； right 的左孩子 认 node 为父节点
        6、rigth 认 node 为新的左孩子
    */
    private void leftRotate(RBTreeNode node) {
        RBTreeNode right = node.getRight();     // 左旋目标节点的右孩子 right
        RBTreeNode parent = node.getParent();   // 左旋目标节点的父节点 parent

        if (parent == null) {       // 当前node节点我为根节点
            root = right;           // 1、更新根节点为right
            right.setParent(null);  // 2、新的根节点的父节点为空
        } else {        // 不是根节点
            if (parent.getLeft() != null && parent.getLeft() == node) { // node是左孩子
                parent.setLeft(right); // 1、将right设置成左孩子
            } else {        // node是右孩子
                parent.setRight(right);// 1、将right设置成右孩子
            }
            right.setParent(parent);// 2、左旋操作：parent 变成 right 的父节点
        }

        node.setParent(right); // 3、左旋操作：right 变成 node 的新父节点
        node.setRight(right.getLeft);// 4、左旋操作：right的左孩子 变成 node的右孩子
        if (right.getLeft() != null) { // right 是否有左孩子
            right.getLeft().setParent(node);// 5、
        }
        right.setLeft(node); // 6、
    }

    // 右旋，node 是右旋的目标节点，left是node的左孩子，一共六步：
    /*
        1、left 顶替 node 的位置
        2、left 认 新的父节点
        3、node 认 left 为新的父节点
        4、node 认 left的右孩子为左孩子
        5、right.right != null 时； left 的右孩子 认 node 为父节点
        6、ledt 认 node 为右孩子
    */
    private void rightRotate(RBTreeNode node) {
        RBTreeNode left = node.getLeft();
        RBTreeNode parent = node.getLeft();
        if (parent == null) {// 是否是根节点
            root = left;            // 1
            left.setParent(null);   // 2
        } else {
            if (parent.getLeft() != null && parent.getLeft() == node ) { // node是否是左孩子
                parent.setLeft(left);   // 1
            } else {
                parent.setRight(left);  // 1
            }
            left.setParent(parent);     // 2
        }
        node.setParent(left);           // 3
        node.setLeft(left.getRight());  // 4
        if (left.getRight() != null) { // left 是否有右孩子
            left.getRight().setParent(node); //5
        }
        left.setRight(node); // 6
    }

    // 设置节点为黑色
    private void setBlack(RBTreeNode node) {
        node.setColor(BLACK);
    }

    // 设置节点为红色
    private void setRed(RBTreeNode node) {
        node.setColor(RED);
    }
    // 中序遍历红黑树
    public void inOrder() {
        inOrder(root);
    }
    // 递归中序遍历遍历输出
    private void inOrder(RBTreeNode node) {
        if (node == null) {
            return;
        }
        inOrder(node.getLeft());
        System.out.println(node);
        inOrder(node.getRight());
    }
 }
```