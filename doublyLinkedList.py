class Node:
    def __init__(self, data):
        self.item = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.root = None

    def isEmpty(self):
        if self.root is None: return True
        else: return False

    def insertAtEnd(self, data):
        if self.isEmpty():       #Empty list. First element inserted
            self.root = Node(data)
            return
        
        ref = self.root
        while ref.next is not None:
            ref = ref.next
        new_node = Node(data)
        ref.next = new_node
        new_node.prev = ref

    def insertAtBeginning(self, data):
        if self.isEmpty():
            self.root = Node(data)
            return
        else:
            new_node = Node(data)
            self.root.prev = new_node
            new_node.next = self.root
            self.root = new_node

    def insertAtPosition(self, position, data): #Manage lists as an array. Start at position 0 ... n-1
        if position == 0:
            self.insertAtBeginning(data)
        elif self.isEmpty():
            print("Invalid action. The list is empty.")
        else:
            ref = self.root
            for element in range(0, position):
                if(ref is None):
                    print("Invalid action. The list has no element {} and forward".format(element))
                    return
                ref = ref.next
            new_node = Node(data)
            if ref is None:
                self.insertAtEnd(data)
            else:
                ref.prev.next = new_node
                new_node.prev = ref.prev
                new_node.next = ref
                ref.prev = new_node

    def deleteFirstElement(self):
        if self.isEmpty():
            print("Invalid action. The list is empty\n")
        elif self.root.next is None:
            self.root = None
        else:
            self.root = self.root.next
            self.root.prev = None

    def deleteLastElement(self):
        if self.isEmpty():
            print("Invalid action. The list is empty\n")
        elif self.root.next is None:
            self.root = None
        else:
            ref = self.root
            while ref.next is not None:
                ref = ref.next
            ref.prev.next = None

    def deleteAtPosition(self, position): #Manage lists as an array. Start at position 0 ... n-1
        if self.isEmpty():
            print("Invalid action. The list is empty\n")
        elif position == 0 :
            self.deleteFirstElement()
        else:
            ref = self.root
            for element in range(0, position):
                if(ref.next is None):
                    print("Invalid action. The list has no element {} and forward".format(element+1))
                    return
                ref = ref.next
            if ref.next is None:
                self.deleteLastElement()
            else:
                ref.prev.next = ref.next
                ref.next.prev = ref.prev

    def search(self, data):
        if self.isEmpty():
            print("Invalid action. The list is empty\n")
        else:
            ref = self.root
            count = 0
            while True:
                if(ref is None):
                    print("Sorry. The list has no element {}".format(data))
                    return
                elif data == ref.item:
                    print("Element {} located at position [{}]".format(ref.item, count))
                    return
                ref = ref.next
                count += 1

    def show(self): #List: | 0 <-> 1 <-> 2 <-> 3 <-> 4 |
        if self.isEmpty():
            print("The list is empty. Insert something :)\n")
        else:
            ref = self.root
            print("|", end=" ")
            while ref.next is not None:
                print(ref.item, end=' <-> ')
                ref = ref.next
            print(ref.item, end=" |\n")
        
    def __str__(self):
        if self.isEmpty():
            print("The list is empty. Insert something :)\n")
        else:
            ref = self.root
            string = "| "
            while ref.next is not None:
                string = string + str(ref.item) + " <-> "
                ref = ref.next
            string = string + str(ref.item) + " |"
        return string

if __name__ == "__main__":
    list = DoublyLinkedList()

    #Put here a menu or the options you would like your list to do.

    list.insertAtEnd('d')
    list.insertAtEnd('e')
    list.insertAtEnd('f')
    list.insertAtEnd('g')
    list.insertAtBeginning('c')
    list.insertAtBeginning('b')
    list.insertAtBeginning('a')
    print(list)
    list.deleteAtPosition(7)
    list.deleteAtPosition(1)
    print(list)
    list.deleteAtPosition(5)
    list.show()
    list.deleteAtPosition(0)
    list.show()
    list.insertAtPosition(1, 1)
    print(list)
    list.search(1)