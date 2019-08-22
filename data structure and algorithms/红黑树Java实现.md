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
        // 插入新节点
        RBTreeNode parent = root;
        RBTreeNode son = null;          // 子树节点，插入以这棵子树为目标
        if (key <= parent.getKey()) {
            son = parent.getLeft();
        } else {
            son = parent.getRight();
        }

        // 找到插入位置
        while (son != null) {
            parent = son;
            if (key <= parent.getKey()) {
                son = parent.getLeft();
            } else {
                son = parent.getRight();
            }
        }

        // 插入新的节点
        if (key <= parent.getKey()) {
            parent.setLeft(node);
        } else {
            parent.setRight(node);
        }
        node.setParent(parent);

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
                    node =father;
                    father = tmp;
                }
                setBlack(father);
                serRed(grandPa);
                rightRotate(grandPa);
            } else {
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

        if (node.getLeft() != null && node.getRight() != null) {
            RBTreeNode replaceNode = node;
            RBTreeNdde tmp = node.getRight();
            while (tmp != null) {
                replaceNode = tmp;
                tmp = tmp.getLeft();
            }
            int t = replaceNode.getKey();
            repalceNode.setKey(node.getKey());
            node.setkey(t);
            delete(replaceNdoe);
            return;
        }

        RBTreeNode replaceNode = null;
        if (node.getLeft() != null) {
            replaceNode = node.getLeft();
        } else {
            replaceNode = node.getRight();
        }

        RBTreeNode parent = node.getParent();
        if (parent == null) {
            root = replaceNode;
            if (repalceNode != null) {
                replaceNode.setParent(null);
            }
        } else {
            if (replaceNode != null) {
                replaceNode.setParent(null);
            } 
            if (parent.getLeft() == node) {
                parent.setLeft(replaceNode);
            } else {
                parent.setRight(replaceNode);
            }
        }
        if (node.getColor() == BLACK) {
            removeFix(parent,replaceNode);
        }
    }

    // 删除修复
    private void removeFix(RBTreeNode father,RBTreeNode node) {
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

    // 左旋
    private void leftRotate(RBTreeNode node) {
        RBTreeNode right = node.getRight();
        RBTreeNode parent = node.getParent();

        if (parent == null) {
            root = right;
            right.setParent(null);
        } else {
            if (parent.getLeft() != null && parent.getLeft() == node) {
                parent.setLeft(right);
            } else {
                parent.setRight(right);
            }
            right.setParent(parent);
        }

        node.setParent(right);
        node.setRight(right.getLeft);
        if (right.getLeft() != null) {
            right.getLeft().setParent(node);
        }
        right.setLeft(node);
    }

    // 右旋
    private void rightRotate(RBTreeNode node) {
        RBTreeNode left = node.getLeft();
        RBTreeNode parent = node.getLeft();
        if (parent == null) {
            root = left;
            left.setParent(null);
        } else {
            if (parent.getLeft() != null && parent.getLeft() == node  ) {
                parent.setLeft(left);
            } else {
                parent.setRight(left);
            }
            left.setParent(parent);
        }
        node.setParent(left);
        node.setLeft(left.getRight());
        if (left.getRight() != null) {
            left.getRight().setParent(node);
        }
        left.setRight(node);
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
    // 递归中序遍历
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