class Node:
	def __init__(self, data):
		self.value = data
		self.left = None
		self.right = None

class binaryTree:
	def __init__(self):
		self.root = None

	def isEmpty(self):
		if self.root is None: 
			return True
		else: 
			return False
	
	def insert(self, data):
		if self.isEmpty():
			self.root = Node(data)
		elif self.find(self.root, data) is not None:
			print("The element {} already exists".format(data))
		else:
			self.add(self.root, data)
	def add(self, node, data):
		if data < node.value:
			if node.left is not None:
				self.add(node.left, data)
			else: node.left = Node(data)
		else:
			if node.right is not None:
				self.add(node.right, data)
			else:
				node.right = Node(data)

	def delete(self, data):
		if self.isEmpty():
			print("Invalid action. The tree is empty.")
		else:
			ref = self.find(self.root, data)
			if ref is None:
				print(f"The node {data} does not exists")
			elif ref.left is None and ref.right is None:		#Case 1. The node has no childs
				parent = self.findParent(self.root, data)
				ref = None
				if data < parent.value: parent.left = None
				else: parent.right = None
			elif ref.left is not None and ref.right is None:	#Case 2: The node has one child: left
				parent = self.findParent(self.root, data)
				if data < parent.value: parent.left = ref.left
				else: parent.right = ref.left
				ref = None
			elif ref.left is None and ref.right is not None:	#Case 2: The node has one child: right
				parent = self.findParent(self.root, data)
				if data < parent.value: parent.left = ref.right
				else: parent.right = ref.right
				ref = None
			elif ref.left is not None and ref.right is not None:#Case 3: The node has two childs
				minimum = self.findMinimumRight(ref.right)
				flag = minimum
				self.delete(minimum.value)
				ref.value = flag.value

	def find(self, node, data): #Returns the node if exists
		if node == None:
			return None
		elif data == node.value:
			return node
		elif data < node.value:
			return self.find(node.left, data)
		else:
			return self.find(node.right, data)

	def findParent(self, node, data): #Returns the node's parent
		if data < node.value: #Goes to the left tree
			if node.left.value == data:
				return node
			return self.findParent(node.left, data)
		else:   #Goes to the right node
			if data == node.right.value:
				return node
			return self.findParent(node.right, data)

	def findMinimumRight(self, current_node):
		while current_node.left is not None:
			current_node = current_node.left
		return current_node

	def search(self, data): #Just a boolean to determine if exists
		if self.isEmpty(): print("The tree is empty. Insert something :)")
		else: self._search(self.root, data)
	def _search(self, node, data):
		if data == node.value:
			print("Element {} exists.".format(data))
		elif data < node.value and node.left is not None:
			self._search(node.left, data)
		elif data > node.value and node.right is not None:
			self._search(node.right, data)
		else:
			print("Element {} does not exists.".format(data))

	def show(self):
		if self.isEmpty():
			print("The tree is empty. Insert something", end="\n")
		else:
			self.inorder() #Inorder displays items in ascending order
			print()

	def inorder(self):
		if self.isEmpty():
			print("The tree is empty. Insert something", end="\n")
		else:
			self._inorder(self.root)
			print()
	def _inorder(self, node): #Displays items as left tree, parent, right tree
		if node is not None:
			self._inorder(node.left)
			print("{} ->".format(node.value), end=" ")
			self._inorder(node.right)
	
	def preorder(self):
		if self.isEmpty():
			print("The tree is empty. Insert something", end="\n")
		else:
			self._preorder(self.root)
			print()
	def _preorder(self, node): #Display items as parent, left tree, right tree
		if node is not None:
			print("{} ->".format(node.value), end=" ")
			self._preorder(node.left)
			self._preorder(node.right)

	def postorder(self):
		if self.isEmpty():
			print("The tree is empty. Insert something", end="\n")
		else:
			self._postorder(self.root)
			print()
	def _postorder(self, node): #Displays items as left tree, rith tree, parent
		if node is not None:
			self._postorder(node.left)
			self._postorder(node.right)
			print("{} ->".format(node.value), end=" ")

	

if __name__ == "__main__":
	tree = binaryTree()

	#Put here a menu or the options you would like your list to do.
	#Functions are insert, delete, inorder, preorder, postorder, search and show

	tree.insert(8)
	tree.insert(4)
	tree.insert(12)
	tree.insert(2)
	tree.insert(6)
	tree.insert(10)
	tree.insert(14)
	tree.insert(1)
	tree.insert(3)
	tree.insert(5)
	tree.insert(7)
	tree.insert(9)
	tree.insert(11)
	tree.insert(13)
	tree.insert(15)
	tree.inorder()
	tree.delete(8)
	tree.inorder()
	tree.postorder()
	tree.preorder()