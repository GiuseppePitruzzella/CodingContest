#include <iostream>
#include <fstream>
using namespace std;

template <class T> class Node {
    T data;
    Node<T> *parent, *left, *right;
public:
    Node(T e) : data(e) {
        parent = left = right = NULL;
    }
    // Set
    void setParent(Node<T>* e) { parent = e; }
    void setRight(Node<T>* e) { right = e; }
    void setLeft(Node<T>* e) { left = e; }

    // Get
    Node<T>* getParent() { return parent; }
    Node<T>* getRight() { return right; }
    Node<T>* getLeft() { return left; }
    T getData() { return data; }
};
template <class T> class BST {
    Node<T>* root;
    void Transplant(Node<T>*, Node<T>*);
    void PreOrder(Node<T>*, ofstream&);
    void InOrder(Node<T>*, ofstream&);
    void PostOrder(Node<T>*, ofstream&);
public:
    BST() { root = NULL; }
    void insert(T);
    void del(T);
    void search(T);
    void getMinimum(Node<T>*);
    void print(string, ofstream&);
    void rotate(string, T);
    void leftRotate(Node<T>*);
    void rightRotate(Node<T>*);
};
// template <class T> void BST<T>::
template <class T> void BST<T>::Transplant(Node<T>* u, Node<T>* v) {
    if (u->getParent() == NULL)
        root = v;
    else if (u == u->getParent()->getRight())
        u->getParent()->setLeft(v);
    else u->getParent()->setLeft(v);

    if (v != NULL) v->setParent(u->getParent());
}
template <class T> void BST<T>::PreOrder(Node<T>* e, ofstream& out) {
    if (e != NULL) {
        out << e->getData() << " ";
        PreOrder(e->getLeft(), out);
        PreOrder(e->getRight(), out);
    }
}
template <class T> void BST<T>::InOrder(Node<T>* e, ofstream& out) {
    if (e != NULL) {
        InOrder(e->getLeft(), out);
        out << e->getData() << " ";
        InOrder(e->getRight(), out);
    }
}
template <class T> void BST<T>::PostOrder(Node<T>* e, ofstream& out) {
    if (e != NULL) {
        PostOrder(e->getLeft(), out);
        PostOrder(e->getRight(), out);
        out << e->getData() << " ";
    }
}
template <class T> void BST<T>::insert(T data) {
    Node<T>* e = new Node<T>(data);
    if (root != NULL) {
        Node<T>* tmp = root, parent = NULL;
        while (tmp) {
            parent = tmp;
            tmp = data < tmp->getData() ? tmp->getLeft() : tmp->getRight();
        }

        e->setParent(parent);
        if (data > parent->getLeft()) parent->setRight(e);
        else parent->setLeft(e);
    } else root = e;
}
template <class T> void BST<T>::del(T data) {
    Node<T>* e = search(x);
    if (e) {
        if (e->getLeft() == NULL)
            Transplant(e, e->getRight());
        else if (e->getRight() == NULL)
            Transplant(e, e->getLeft());
        else {
            Node<T>* min = getMinimum(e->getRight());
            if (min->getParent() != e) {
                Transplant(min, min->getRight());
                min->setRight(e->getRight());
                min->getRight()->setParent(min)
            }
            Transplant(e, min);
            min->setLeft(e->getLeft());
            min->getLeft()->setParent(min);
        }
    }
}
template <class T> void BST<T>::print(string printType, ofstream& out) {
    if (printType == "preorder") 
        PreOrder(root, out);
    else if (printType == "inorder")
        InOrder(root, out);
    else if (printType == "postorder")
        PostOrder(root, out);
    out << endl;
}
template <class T> void BST<T>::rotate(string rotateType, T data) {
    Node<T>* e = new Node<T>(data);
    if (e) {
        if (rotateType == "left") 
            leftRotate(e);
        else if (rotateType == "right")
            rightRotate(e);
    }
}
template <class T> void BST<T>::leftRotate(Node<T>* e) {
    if (e) {
        Node<T>* right = e->getRight();
        Node<T>* parent = e->getParent();
        if (right) {
            e->setRight(right->getLeft());
            right->setLeft(e);
            Transplant(e, right);

            right->setParent(parent);
            e->setParent(right);

            if (e->getRight()) e->getRight()->setParent(e);
        }
    }
}
template <class T> void BST<T>::rightRotate(Node<T>* e) {
    if(e != NULL) {
        Node<T>* left = e->getLeft();
        Node<T>* parent = e->getParent();
        if(left != NULL) {
            e->setLeft(left->getRight());
            left->setRight(e);

            Transplant(e, left);
            
            left->setParent(parent);
            e->setParent(left);

            if (e->getLeft()) e->getLeft()->setParent(e);
        }
    }
}
