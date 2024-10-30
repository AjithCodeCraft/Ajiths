class Node:
    def __init__(self,key):
        self.left =None
        self.right = None
        self.val = key
        
def inorder_iterative(root):
    stack = []
    current = root
    result = []
    
    while current or stack:
        while current:
            stack.append(current)
            current = current.left
            
        current = stack.pop()
        result.append(current.val)
        
        current = current.right
    return result

def postorder_iterative(root):
    if not root:
        return []
    stack1= [root]
    stack2 = []
    result = []
    
    while stack1:
        current = stack1.pop()
        stack2.append(current)
        
        if current.left:
            stack1.append(current.left)
        if current.right:
            stack1.append(current.right)
    
    
    while stack2:
        result.append(stack2.pop().val)
    return result

def create_sample_tree():
    root = Node(1)
    root.left =Node(2)
    root.left.left =Node(3)
    root.left.right = Node(5)


print("Inorder Traversal (Iterative):", inorder_iterative(root))
print("Preorder Traversal (Iterative):", preorder_iterative(root))
print("Postorder Traversal (Iterative):", postorder_iterative(root))