using System;
using System.Collections.Generic;
using System.ComponentModel.Design;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace doublyLinkedList
{
    public class Node
    {
        public Node next, prev;
        public Object item;

        public Node(Object data)
        {
            next = null;
            prev = null;
            item = data;
        }
    }

    public class DoublyLinkedList
    {
        private Node root;

        public bool IsEmpty()
        {
            if (root == null) return true;
            else return false;
        }

        public void InsertAtEnd(Object data)
        {
            if (IsEmpty())
            {
                root = new Node(data);
                return;
            }
            Node reference = root;

            while (reference.next != null) reference = reference.next;

            Node new_node = new Node(data);
            reference.next = new_node;
            new_node.prev = reference;
        }

        public void InsertAtBeginning(Object data)
        {
            if (IsEmpty())
            {
                root = new Node(data);
                return;
            }
            else
            {
                Node new_node = new Node(data);
                root.prev = new_node;
                new_node.next = root;
                root = new_node;
            }
        }

        public void InsertAtPosition(int position, Object data)
        {
            if (position == 0) InsertAtBeginning(data);
            else if (IsEmpty()) Console.WriteLine("Invalid action. The list is empty.");
            else
            {
                Node reference = root;
                for (int i = 0; i < position; i++)
                {
                    if (reference == null)
                    {
                        Console.WriteLine("Invalid action. The list has no element [" + i + "] and forward");
                        return;
                    }
                    reference = reference.next;
                }
                Node new_node = new Node(data);
                if (reference == null) InsertAtEnd(data);
                else
                {
                    reference.prev.next = new_node;
                    new_node.prev = reference.prev;
                    new_node.next = reference;
                    reference.prev = new_node;
                }
            }
        }

        public void DeleteFirstElement()
        {
            if (IsEmpty()) Console.WriteLine("Invalid action. The list is empty");
            else if (root.next == null) root = null;
            else
            {
                root = root.next;
                root.prev = null;
            }
        }

        public void DeleteLastElement()
        {
            if (IsEmpty()) Console.WriteLine("Invalid action. The list is empty");
            else if (root.next == null) root = null;
            else
            {
                Node reference = root;
                while (reference.next != null) reference = reference.next;
                reference.prev.next = null;
            }
        }

        public void DeleteAtPosition(int position)
        {
            if (IsEmpty()) Console.WriteLine("Invlaid action. The list is empty");
            else if (position == 0) DeleteFirstElement();
            else
            {
                Node reference = root;
                for (int i = 0; i < position; i += 1)
                {
                    if (reference.next == null)
                    {
                        Console.WriteLine("Invalid action. The list has no element [" + (i + 1) + "] and forward");
                        return;
                    }
                    reference = reference.next;
                }
                if (reference.next == null) DeleteLastElement();
                else
                {
                    reference.prev.next = reference.next;
                    reference.next.prev = reference.prev;
                }
            }
        }

        public void Search(Object data)
        {
            if (IsEmpty()) Console.WriteLine("Invalid action. The list is empty");
            else
            {
                Node reference = root;
                int count = 0;
                while (true)
                {
                    if (reference == null)
                    {
                        Console.WriteLine("Sorry. The list has no element " + data);
                        return;
                    }
                    else if (data == reference.item)
                    {
                        Console.WriteLine("Element " + data + " located at position [" + count + "]");
                        return;
                    }
                    reference = reference.next;
                    count++;
                }
            }
        }

        public void Show()
        {
            if (IsEmpty()) Console.WriteLine("The list is empty. Insert something");
            else
            {
                Node reference = this.root;
                Console.Write("| ");
                while (reference.next != null)
                {
                    Console.Write(reference.item + " <-> ");
                    reference = reference.next;
                }
                Console.WriteLine(reference.item + " |");
            }
        }

        static void Main()
        {
            DoublyLinkedList list = new DoublyLinkedList();

            /*Put here a menu or the options you would like your list to do.
	        Functions are InsertAtEnd(), InsertAtBeginning(), DeleteFirstElement(), 
            DeleteAtPosition(), Search() and Show()*/

            list.InsertAtEnd("d");
            list.InsertAtEnd("e");
            list.InsertAtEnd("f");
            list.InsertAtEnd("g");
            list.InsertAtBeginning("c");
            list.InsertAtBeginning("b");
            list.InsertAtBeginning("a");
            list.Show();
            list.DeleteAtPosition(7);
            list.InsertAtPosition(7, "a");
            list.DeleteAtPosition(1);
            list.Show();
            list.DeleteAtPosition(5);
            list.Show();
            list.DeleteAtPosition(0);
            list.Show();
            list.InsertAtPosition(1, 1);
            list.DeleteFirstElement();
            list.DeleteLastElement();
            list.Show();
            list.Search(1);

            Console.ReadLine();
        }

    }
}
