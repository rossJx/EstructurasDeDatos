public class binaryTree
{
    private Node root;
        
    public binaryTree()
    {
        root = null;
    }

    boolean isEmpty()
    {
        if(root==null ) return true;
        else return false;
    }
    void insert(int data)
    {
        if(isEmpty()) root = new Node(data);
        else if(find(root, data) != null)
            System.out.println("The element "+data+" already exists.\n");
        else insert(root, data);
    }
    void insert(Node node, int data)
    {
        if(data < node.value)
        {
            if( node.left != null ) insert(node.left, data);
            else{
                node.left = new Node(data);
            }
        }
        else
        {
            if( node.right != null ) this.insert(node.right, data);
            else node.right = new Node(data);
        }
    }

    void remove(int data)
    {
        if(isEmpty()) System.out.println("Invalid action. The tree is empty.\n");
        else
        {
            Node ref = find(root, data);
            if(ref == null) System.out.println("The node "+data+" does not exists.");
            else if(ref.left == null && ref.right == null)
            {
                Node parent = findParent(root, data);
                ref = null;
                if(data < parent.value) parent.left = null;
                else parent.right = null;
            }
            else if(ref.left != null && ref.right == null)
            {
                Node parent = findParent(root, data);
                if(data < parent.value) parent.left = ref.left;
                else{
                    parent.right = ref.left;
                    ref = null;
                }
            }
            else if(ref.left == null && ref.right != null)
            {
                Node parent = this.findParent(root, data);
                if(data < parent.value) parent.left = ref.right;
                else{
                    parent.right = ref.right;
                    ref = null;
                }
            }
            else if(ref.left != null && ref.left != null)
            {
                Node minimum = findMinimumRight(ref.right);
                Node flag = minimum;
                remove(minimum.value);
                ref.value = flag.value;
            }
        }
    }

    Node find(Node node, int data)
    {
        if( node == null ) return null;
        else if(data == node.value) return node;
        else if(data < node.value) return find(node.left, data);
        else return find(node.right, data);
    }

    Node findParent(Node node, int data)
    {
        if(data < node.value)
        {
            if(node.left.value == data) return node;
            return findParent(node.left, data);
        }
        else{
            if(data == node.right.value) return node;
            return findParent(node.right, data);
        }
    }

    Node findMinimumRight(Node node)
    {
        while(node.left != null)
            node = node.left;
        return node;
    }

    void search(int data)
    {
        if(isEmpty()) System.out.println("The tree is empty. Insert something :)");
        else search(root, data);
    }
    void search(Node node, int data)
    {
        if(data == node.value) System.out.println("Element "+data+" exists.");
        else if(data < node.value && node.left != null) 
            search(node.left, data);
        else if(data > node.value && node.right != null) 
            search(node.right, data);
        else System.out.println("Element "+data+" does not exists.");
    }

    void show()
    {
        if(isEmpty()) System.out.println("The tree is empty. Insert something");
        else inorder();
    }
    void inorder()              //Displays items as left tree, parent, rigth tree
    {
        if(isEmpty()) System.out.println("The tree is empty. Insert something");
        else{
            inorder(root);
            System.out.println();
        }
    }
    void inorder(Node node)    //Use Polymorphism to allow recursive methods
    {
        if (node != null)
        {
            inorder(node.left);
            System.out.print(node.value+" -> ");
            inorder(node.right);
        }
    }

    void preorder()              //Displays items as parent, left tree, rigth tree
    {
        if(isEmpty()) System.out.println("The tree is empty. Insert something");
        else{
            preorder(root);
            System.out.println();
        }
    }
    void preorder(Node node)    //Use Polymorphism to allow recursive methods
    {
        if (node != null)
        {
            System.out.print(node.value+" -> ");
            preorder(node.left);
            preorder(node.right);
        }
    }

    void postorder()              //Displays items as left tree, rigth tree, parent
    {
        if(isEmpty()) System.out.println("The tree is empty. Insert something");
        else{
            postorder(root);
            System.out.println();
        }
    }
    void postorder(Node node)    //Use Polymorphism to allow recursive methods
    {
        if (node != null)
        {
            postorder(node.left);
            postorder(node.right);
            System.out.print(node.value+" -> ");
        }
    }
    
    public static void main(String args[])
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
    }
}

class Node
{
    public int value;
    public Node left, right;
    
    public Node(int data)
    {
        value = data;
    }
}