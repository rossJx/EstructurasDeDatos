#include <iostream>

using namespace std;

class Node 
{
    public:
        int value;
        Node *left, *right; 

        Node(int data)
        {
            left = nullptr;
            right = nullptr;
            value = data;
        } 
};

class binaryTree
{
    public:
        Node *root;
        
        binaryTree()
        {
            root = nullptr;
        }

        bool isEmpty()
        {
            if(this->root==nullptr ) return true;
            else return false;
        }

        void insert(int data)
        {
            if(this->isEmpty()) root = new Node(data);
            else if(this->find(root, data) != nullptr)
                cout << "The element "<<data<<" already exists.\n";
            else this->insert(root, data);
        }
        void insert(Node *node, int data)
        {
            if(data < node->value)
            {
                if( node->left != nullptr ) this->insert(node->left, data);
                else{
                    node->left = new Node(data);
                }
            }
            else
            {
                if( node->right != nullptr ) this->insert(node->right, data);
                else node->right = new Node(data);
            }
        }

        void remove(int data)
        {
            if(this->isEmpty()) cout << "Invalid action. The tree is empty.\n";
            else
            {
                Node *ref = this->find(root, data);
                if(ref == nullptr) cout << "The node "<<data<<" does not exists.\n";
                else if(ref->left == nullptr && ref->right == nullptr)
                {
                    Node *parent = this->findParent(root, data);
                    ref = nullptr;
                    if(data < parent->value) parent->left = nullptr;
                    else parent->right = nullptr;
                }
                else if(ref->left != nullptr && ref->right == nullptr)
                {
                    Node *parent = this->findParent(root, data);
                    if(data < parent->value) parent->left = ref->left;
                    else{
                        parent->right = ref->left;
                        ref = nullptr;
                    }
                }
                else if(ref->left == nullptr && ref->right != nullptr)
                {
                    Node *parent = this->findParent(root, data);
                    if(data < parent->value) parent->left = ref->right;
                    else{
                        parent->right = ref->right;
                        ref = nullptr;
                    }
                }
                else if(ref->left != nullptr && ref->left != nullptr)
                {
                    Node *minimum = this->findMinimumRight(ref->right);
                    Node *flag = minimum;
                    this->remove(minimum->value);
                    ref->value = flag->value;
                }
            }
        }

        Node *find(Node *node, int data)
        {
            if( node == nullptr ) return nullptr;
            else if(data == node->value) return node;
            else if(data < node->value) return this->find(node->left, data);
            else return this->find(node->right, data);
        }

        Node *findParent(Node *node, int data)
        {
            if(data < node->value)
            {
                if(node->left->value == data) return node;
                return this->findParent(node->left, data);
            }
            else{
                if(data == node->right->value) return node;
                return this->findParent(node->right, data);
            }
        }

        Node *findMinimumRight(Node *node)
        {
            while(node->left != nullptr)
                node = node->left;
            return node;
        }

        void search(int data)
        {
            if(this->isEmpty()) cout << "The tree is empty. Insert something :)\n";
            else this->search(root, data);
        }
        void search(Node *node, int data)
        {
            if(data == node->value) cout << "Element "<<data<<" exists.\n";
            else if(data < node->value && node->left != nullptr) 
                this->search(node->left, data);
            else if(data > node->value && node->right != nullptr) 
                this->search(node->right, data);
            else cout << "Element "<<data<<" does not exists.\n";
        }

        void show()
        {
            if(this->isEmpty()) cout << "The tree is empty. Insert something\n";
            else
            {
                this->inorder();
            }
        }
        void inorder()              //Displays items as left tree, parent, rigth tree
        {
            if(this->isEmpty()) cout << "The tree is empty. Insert something\n";
            else{
                this->inorder(this->root);
                cout << endl;
            }
        }
        void inorder(Node *node)    //Use Polymorphism to allow recursive methods
        {
            if (node!=nullptr)
            {
                this->inorder(node->left);
                cout << node->value << " -> ";
                this->inorder(node->right);
            }
        }

        void preorder()             //Displays items as parent, left tree, rigth tree
        {
            if(this->isEmpty()) cout << "The tree is empty. Insert something\n";
            else{
                this->preorder(this->root);
                cout << endl;
            }
        }
        void preorder(Node *node)    //Use Polymorphism to allow recursive methods
        {
            if (node!=nullptr)
            {
                cout << node->value << " -> ";
                this->preorder(node->left);
                this->preorder(node->right);
            }
        }

        void postorder()                //Displays items as left tree, rigth tree, parent
        {
            if(this->isEmpty()) cout << "The tree is empty. Insert something\n";
            else{
                this->postorder(this->root);
                cout << endl;
            }
        }
        void postorder(Node *node)      //Use Polymorphism to allow recursive methods
        {
            if (node!=nullptr)
            {
                this->postorder(node->left);
                this->postorder(node->right);
                cout << node->value << " -> ";
            }
        }
};

int main()
{
    binaryTree *tree = new binaryTree();

    cout << tree->isEmpty() <<endl;

    //Put here a menu or the options you would like your list to do.
	//Functions are insert, remove, inorder, preorder, postorder, search and show

    tree->insert(8);
    tree->insert(4);
    tree->insert(12);
    tree->insert(2);
    tree->insert(6);
    tree->insert(10);
    tree->insert(14);
    tree->insert(1);
    tree->insert(3);
    tree->insert(5);
    tree->insert(7);
    tree->insert(9);
    tree->insert(11);
    tree->insert(13);
    tree->insert(15);
    tree->show();
    tree->remove(2);
    tree->remove(4);
    tree->remove(6);
    tree->remove(8);
    tree->remove(10);
    tree->remove(12);
    tree->remove(14);
    tree->remove(16);
    tree->inorder();
    tree->preorder();
    tree->postorder();
    
    //cin.get(); //Pauses the program, so the results can be seen on Windows OS.
    return 0;
}