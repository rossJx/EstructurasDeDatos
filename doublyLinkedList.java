class Node{
        int number;
        String word;
        Node next, prev;
        public Node(int value)
        {
            prev = null;
            next = null;
            number = value; 
            word = null;
        }
        public Node(String value)
        {
            prev = null;
            next = null;
            number = '\0'; //Number is set to null character to allow
            word = value;  //comparision on conditionals at printing
        }
}

public class doublyLinkedList
{
    Node root;

    public doublyLinkedList(){
        root = null;
    }

    boolean isEmpty()
    {
        if (this.root == null) return true;
        else return false;
    }

    void insertAtEnd(int data)  //Use polymorphism to help in decision
    {                           //of storing either int or char*
        if(isEmpty()){
            root = new Node(data);
            return;
        }
        Node ref = this.root;
        while (ref.next != null) ref = ref.next;
        Node new_node = new Node(data);
        ref.next = new_node;
        new_node.prev = ref;
    }
    void insertAtEnd(String data)
    {                              
        if(isEmpty()){
            this.root = new Node(data);
            return;
        }
        Node ref = this.root;
        while (ref.next != null) ref = ref.next;
        Node new_node = new Node(data);
        ref.next = new_node;
        new_node.prev = ref;
    }

    void insertAtBeginning(int data)
    {
        if(isEmpty()){
            root = new Node(data);
            return;
        }
        else{
            Node new_node = new Node(data);
            root.prev = new_node;
            new_node.next = root;
            root = new_node;
        }
    }
    void insertAtBeginning(String data)
    {
        if(isEmpty()){
            root = new Node(data);
            return;
        }
        else{
            Node new_node = new Node(data);
            root.prev = new_node;
            new_node.next = root;
            root = new_node;
        }
    }

    void insertAtPosition(int position, int data)
    {
        if(position==0) insertAtBeginning(data);
        else if(isEmpty()) System.out.println("Invalid action. The list is empty.");
        else{
            Node ref = root;
            for(int i=0; i<position; i++){
                if(ref == null){
                    System.out.println("Invalid action. The list has no element ["+ i +"] and forward");
                    return;
                }
                ref = ref.next;
            }
            Node new_node = new Node(data);
            if (ref == null) insertAtEnd(data);
            else{
                ref.prev.next = new_node;
                new_node.prev = ref.prev;
                new_node.next = ref;
                ref.prev = new_node;
            }
        }
    }
    void insertAtPosition(int position, String data)
    {
        if(position==0) insertAtBeginning(data);
        else if(isEmpty()) System.out.println("Invalid action. The list is empty.");
        else{
            Node ref = root;
            for(int i=0; i<position; i++){
                if(ref == null){
                    System.out.println("Invalid action. The list has no element ["+ (i+1) +"] and forward");
                    return;
                }
                ref = ref.next;
            }
            Node new_node = new Node(data);
            if (ref == null) insertAtEnd(data);
            else{
                ref.prev.next = new_node;
                new_node.prev = ref.prev;
                new_node.next = ref;
                ref.prev = new_node;
            }
        }
    }

    void deleteAtPosition(int position)
    {
        if(isEmpty()) System.out.println("Invlaid action. The list is empty");
        else if(position == 0) deleteFirstElement();
        else{
            Node ref = root;
            for(int i=0; i<position; i+=1) {
                if(ref.next == null){
                    System.out.println("Invalid action. The list has no element ["+ (i+1) +"] and forward");
                    return;
                }
                ref = ref.next;
            }
            if (ref.next == null) deleteLastElement();
            else{
                ref.prev.next = ref.next;
                ref.next.prev = ref.prev;
            }
        }
    }

    void deleteFirstElement()
    {
        if(isEmpty()) System.out.println("Invalid action. The list is empty");
        else if (root.next == null) root = null;
        else{
            root = root.next;
            root.prev = null;
        }
    }

    void deleteLastElement()
    {
        if(isEmpty()) System.out.println("Invalid action. The list is empty");
        else if (root.next == null) root = null;
        else{
            Node ref = root;
            while(ref.next != null) ref = ref.next;
            ref.prev.next = null;
        }
    }

    void search(int data)
    {
        if(isEmpty()) System.out.println("Invalid action. The list is empty");
        else{
            Node ref = root;
            int count = 0;
            while (true){
                if(ref == null){
                    System.out.println("Sorry. The list has no element "+data);
                    return;
                }
                else if (data == ref.number && ref.number!='\0')
                {
                    System.out.println("Element "+ data +" located at position ["+ count +"]");
                    return;
                }
                ref = ref.next;
                count++;
            }
        }
    }
    void search(String data)
    {
        if(isEmpty()) System.out.println("Invalid action. The list is empty");
        else{
            Node ref = root;
            int count = 0;
            while (true){
                if(ref == null){
                    System.out.println("Sorry. The list has no element "+data);
                    return;
                }
                else if (data == ref.word)
                {
                    System.out.println("Element "+ data +" located at position ["+ count +"]");
                    return;
                }
                ref = ref.next;
                count++;
            }
        }
    }

    void show()
    {
        if(isEmpty()) System.out.println("The list is empty. Insert something");
        else{
            Node ref = this.root;
            System.out.print("| ");
            while (ref.next != null) {
                if (ref.word != null) System.out.print(ref.word+" <-> ");
                else System.out.print(ref.number+" <-> ");
                ref = ref.next;
            }
            if (ref.word != null) System.out.println(ref.word+" |");
            else System.out.println(ref.number+" |");
        }
    }
    public static void main(String[] args) {
        doublyLinkedList list =  new doublyLinkedList();

        list.insertAtEnd("d");
        list.insertAtEnd("e");
        list.insertAtEnd("f");
        list.insertAtEnd("g");
        list.insertAtBeginning("c");
        list.insertAtBeginning("b");
        list.insertAtBeginning("a");
        list.show();
        list.deleteAtPosition(7);
        list.insertAtPosition(7, "a");
        list.deleteAtPosition(1);
        list.show();
        list.deleteAtPosition(5);
        list.show();
        list.deleteAtPosition(0);
        list.show();
        list.insertAtPosition(1, 1);
        list.show();
        list.search(1);

    }
}