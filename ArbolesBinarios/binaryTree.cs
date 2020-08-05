using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace binaryTree
{
    class Node
    {
        public int value;
        public Node left, right;

        public Node(int data)
        {
            value = data;
        }
    }

    public class binaryTree
    {
        private Node root;

        public binaryTree()
        {
            root = null;
        }

        bool isEmpty()
        {
            if (root == null) return true;
            else return false;
        }
        void insert(int data)
        {
            if (isEmpty()) root = new Node(data);
            else if (find(root, data) != null)
                Console.WriteLine("The element " + data + " already exists.");
        else insert(root, data);
        }
        void insert(Node node, int data)
        {
            if (data < node.value)
            {
                if (node.left != null) insert(node.left, data);
                else
                {
                    node.left = new Node(data);
                }
            }
            else
            {
                if (node.right != null) this.insert(node.right, data);
                else node.right = new Node(data);
            }
        }

        void remove(int data)
        {
            if (isEmpty()) Console.WriteLine("Invalid action. The tree is empty.");
        else
            {
                Node reference = find(root, data);
                if (reference == null) Console.WriteLine("The node " + data + " does not exists.");
            else if (reference.left == null && reference.right == null)
                {
                    Node parent = findParent(root, data);
                    reference = null;
                    if (data < parent.value) parent.left = null;
                    else parent.right = null;
                }
                else if (reference.left != null && reference.right == null)
                {
                    Node parent = findParent(root, data);
                    if (data < parent.value) parent.left = reference.left;
                    else
                    {
                        parent.right = reference.left;
                        reference = null;
                    }
                }
                else if (reference.left == null && reference.right != null)
                {
                    Node parent = this.findParent(root, data);
                    if (data < parent.value) parent.left = reference.right;
                    else
                    {
                        parent.right = reference.right;
                        reference = null;
                    }
                }
                else if (reference.left != null && reference.left != null)
                {
                    Node minimum = findMinimumRight(reference.right);
                    Node flag = minimum;
                    remove(minimum.value);
                    reference.value = flag.value;
                }
            }
        }

        Node find(Node node, int data)
        {
            if (node == null) return null;
            else if (data == node.value) return node;
            else if (data < node.value) return find(node.left, data);
            else return find(node.right, data);
        }

        Node findParent(Node node, int data)
        {
            if (data < node.value)
            {
                if (node.left.value == data) return node;
                return findParent(node.left, data);
            }
            else
            {
                if (data == node.right.value) return node;
                return findParent(node.right, data);
            }
        }

        Node findMinimumRight(Node node)
        {
            while (node.left != null)
                node = node.left;
            return node;
        }

        void search(int data)
        {
            if (isEmpty()) Console.WriteLine("The tree is empty. Insert something :)");
            else search(root, data);
        }
        void search(Node node, int data)
        {
            if (data == node.value) Console.WriteLine("Element " + data + " exists.");
            else if (data < node.value && node.left != null)
                    search(node.left, data);
                else if (data > node.value && node.right != null)
                    search(node.right, data);
                else Console.WriteLine("Element " + data + " does not exists.");
        }

        void show()
        {
            if (isEmpty()) Console.WriteLine("The tree is empty. Insert something");
            else inorder();
        }
        void inorder()              //Displays items as left tree, parent, rigth tree
        {
            if (isEmpty()) Console.WriteLine("The tree is empty. Insert something");
            else
                {
                    inorder(root);
                    Console.WriteLine();
                }
        }
        void inorder(Node node)    //Use Polymorphism to allow recursive methods
        {
            if (node != null)
            {
                inorder(node.left);
                Console.Write(node.value + " -> ");
                inorder(node.right);
            }
        }

        void preorder()              //Displays items as parent, left tree, rigth tree
        {
            if (isEmpty()) Console.WriteLine("The tree is empty. Insert something");
        else
            {
                preorder(root);
                Console.WriteLine();
            }
        }
        void preorder(Node node)    //Use Polymorphism to allow recursive methods
        {
            if (node != null)
            {
                Console.Write(node.value + " -> ");
                preorder(node.left);
                preorder(node.right);
            }
        }

        void postorder()              //Displays items as left tree, rigth tree, parent
        {
            if (isEmpty()) Console.WriteLine("The tree is empty. Insert something");
            else
                {
                    postorder(root);
                    Console.WriteLine();
                }
            }
        void postorder(Node node)    //Use Polymorphism to allow recursive methods
        {
            if (node != null)
            {
                postorder(node.left);
                postorder(node.right);
                Console.Write(node.value + " -> ");
            }
        }
   
        static void Main(string[] args)
        {
            binaryTree tree = new binaryTree();

            //Put here a menu or the options you would like your list to do.
            //Functions are insert, remove, inorder, preorder, postorder, search and show

            tree.insert(8);
            tree.insert(4);
            tree.insert(12);
            tree.insert(2);
            tree.insert(6);
            tree.insert(10);
            tree.insert(14);
            tree.insert(1);
            tree.insert(3);
            tree.insert(5);
            tree.insert(7);
            tree.insert(9);
            tree.insert(11);
            tree.insert(13);
            tree.insert(15);
            tree.show();
            tree.remove(1);
            tree.remove(3);
            tree.remove(5);
            tree.remove(7);
            tree.remove(13);
            tree.remove(15);
            tree.remove(9);
            tree.remove(11);
            tree.inorder();
            tree.preorder();
            tree.postorder();

            Console.ReadLine();
        }
    }
}
