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
    Node<T>* search(T);
    Node<T>* getMinimum(Node<T>*);
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
        u->getParent()->setRight(v);
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
    if (root == NULL) {
        root = e;
    } else {
        Node<T>* tmpRoot = root;
        Node<T>* tmp = NULL;
        while (tmpRoot != NULL){
            tmp = tmpRoot;
            if (data > tmpRoot->getData()) tmpRoot = tmpRoot->getRight();
            else tmpRoot = tmpRoot->getLeft();
        }
        e->setParent(tmp);
        if (data > tmp->getData()) tmp->setRight(e);
        else tmp->setLeft(e);
    }
}
template <class T> void BST<T>::del(T data) {
    Node<T>* e = search(data);
    if (e != NULL){
        if (e->getLeft() == NULL)
            Transplant(e, e->getRight());
        else if (e->getRight() == NULL)
            Transplant(e, e->getLeft());
        else {
            Node<T>* min = getMinimum(e->getRight());
            
            if (min->getParent() != e){
                Transplant(min, min->getRight());
                min->setRight(e->getRight());
                min->getRight()->setParent(min);
            }
            Transplant(e, min);
            min->setLeft(e->getLeft());
            min->getLeft()->setParent(min);
        }
    }
}
template <class T> Node<T>* BST<T>::search(T data) {
    Node<T>* tmp = root;
    while (tmp != NULL && data != tmp->getData())
        tmp = data > tmp->getData() ? tmp->getRight() : tmp->getLeft();
    return tmp;
}
template <class T> Node<T>* BST<T>::getMinimum(Node<T>* e) {
    Node<T>* tmp = e;
    while (tmp->getLeft() != NULL) tmp = tmp->getLeft();
    return tmp;
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
    Node<T>* e = search(data);
    if (e != NULL) {
        if (rotateType == "left") leftRotate(e);
        else if (rotateType == "right") rightRotate(e);
    }
}
template <class T> void BST<T>::leftRotate(Node<T>* e){
     if(e != NULL){
        Node<T>* right = e->getRight();
        Node<T>* parent = e->getParent();
        if (right != NULL){
            e->setRight(right->getLeft());
            right->setLeft(e);

            Transplant(e, right);

            right->setParent(parent);
            e->setParent(right);

            if (e->getRight()) e->getRight()->setParent(e); 
        }
    }
}

template <class T> void BST<T>::rightRotate(Node<T>* e){
    if (e != NULL) {
        Node<T>* left = e->getLeft();
        Node<T>* parent = e->getParent();
        if(left != NULL){
            e->setLeft(left->getRight());
            left->setRight(e);

            Transplant(e, left);
            
            left->setParent(parent);
            e->setParent(left);

            if (e->getLeft()) e->getLeft()->setParent(e);
        }
    }
}

int breakIndex(string str) {
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ':') return i;
    return -1;
}
string operationType(string str) {
    return str.substr(0, breakIndex(str));
}
string value(string str) {
    return str.substr(breakIndex(str) + 1, str.length());
}

int main(int argc, char const *argv[]) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    for (int i = 0; i < 100; i++) {
        string dataType, printType; in >> dataType;
        int n, m; 
        in >> n;
        in >> m;
        in >> printType;
        if (dataType == "int") {
            BST<int>* Solution = new BST<int>();
            // Operations
            for (int j = 0; j < n + m; j++) {
                string tmp; in >> tmp;
                string operation = operationType(tmp);
                if (operation == "ins")
                    Solution->insert(stoi(value(tmp)));
                else if (operation == "canc")
                    Solution->del(stoi(value(tmp)));
                else if (operation == "right")
                    Solution->rotate(operation, stoi(value(tmp)));
                else if (operation == "left")
                    Solution->rotate(operation, stoi(value(tmp)));
            }
            Solution->print(printType, out);
            delete Solution;
        } else if (dataType == "double") {
            BST<double>* Solution = new BST<double>();
            // Operations
            for (int j = 0; j < n + m; j++) {
                string tmp; in >> tmp;
                string operation = operationType(tmp);
                if (operation == "ins")
                    Solution->insert(stod(value(tmp)));
                else if (operation == "canc")
                    Solution->del(stod(value(tmp)));
                else if (operation == "right")
                    Solution->rotate(operation, stod(value(tmp)));
                else if (operation == "left")
                    Solution->rotate(operation, stod(value(tmp)));
            } 
            Solution->print(printType, out);
            delete Solution;
        }
    }
    return 0;
}
