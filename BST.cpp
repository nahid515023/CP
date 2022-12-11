#include<iostream>
using namespace std;

class BST {

    struct node {
        int data;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        if(find(root, x)!=NULL){
            cout<<"Find"<<endl;
        }
        else{
            cout<<"Not find"<<endl;
        }
    }
    void Max()
    {
        cout<<findMax(root)->data<<endl;
    }
    void Min()
    {
        cout<<findMin(root)->data<<endl;
    }
};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    cout<<"1 Display Tree."<<endl;
    cout<<"2 Insert value."<<endl;
    cout<<"3 Remove value."<<endl;
    cout<<"4 Show Maximum value."<<endl;
    cout<<"5 Show Minimum value."<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"------------------------------------------------"<<endl;
    while(1)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            t.display();
        }
        else if(n==2)
        {
            cout<<"Enter a value :";
            int x;
            cin>>x;
            t.insert(x);
        }
        else if(n==3)
        {
           cout<<"Enter a value :";
           int x;
           cin>>x;
           t.remove(x);
       }
       else if(n==4)
       {
        t.Max();
    }
    else if(n==5)
    {
        t.Min();
    }
    else if(n==0)
    {
        break;
    }
    else{
        cout<<"Wrong value insert. Try again.."<<endl;
        cout<<"1 Display Tree."<<endl;
        cout<<"2 Insert value."<<endl;
        cout<<"3 Remove value."<<endl;
        cout<<"4 Show Maximum value."<<endl;
        cout<<"5 Show Minimum value."<<endl;
        cout<<"0 Exit"<<endl<<endl;
    }
}




return 0; 
}