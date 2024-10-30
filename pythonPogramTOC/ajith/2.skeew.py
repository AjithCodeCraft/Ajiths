class Node:
    def __init__(self,key):
        self.left =None
        self.right =None
        self.val = key
        
def create_left_skewed_tree(height):
    root =Node(1)
    current =root
    for i in range(2,height+2):
        current.left = Node(i)
        current = current.left
    return root
# def print_tree(node, level=0):
#     if node is not None:
#         print_tree(node.left, level + 1)
#         print(' ' * 4 * level + '->', node.val)
#         print_tree(node.right, level + 1)

# # Create the left-skewed tree
left_skewed_tree = create_left_skewed_tree(4)

# # Print the tree
# print_tree(left_skewed_tree)
def inorder_traversal(root):
    if root is None:
        return []
    return inorder_traversal(root.left)+[root.val]+ inorder_traversal(root.right)
# result = inorder_traversal(left_skewed_tree)
# print(result)
def sorted_array_to_bst(arr):
  if not arr:
     return None
  mid = len(arr)//2
  root =Node(arr[mid]) 
  root.left =sorted_array_to_bst(arr[:mid])
  root.right =sorted_array_to_bst(arr[mid + 1:])
  return root

def convert_balanced_tree(root):
    inorder_vals = inorder_traversal(root)
    return sorted_array_to_bst(inorder_vals)

def search_tree(root, key):
    comparisons = 0
    current = root
    while current:
        comparisons += 1
        if current.val == key:
            return comparisons
        elif key < current.val:
            current = current.left
        else:
            current = current.right
    return comparisons


left_skewed_tree = create_left_skewed_tree(4)
balanced_tree = convert_balanced_tree(left_skewed_tree)

key1,key2 = 3,5
comparisons_skewed_1 = search_tree(left_skewed_tree,key1)
comparisons_skewed_2 = search_tree(left_skewed_tree,key2)

comparisons_balanced_1 = search_tree(balanced_tree,key1)
comparisons_balanced_2  = search_tree(balanced_tree,key2)


print(f"\nComparisons for {key1} in Left-Skewed Tree: {comparisons_skewed_1}")
print(f"Comparisons for {key2} in Left-Skewed Tree: {comparisons_skewed_2}")

print(f"\nComparisons for {key1} in Balanced Tree: {comparisons_balanced_1}")
print(f"Comparisons for {key2} in Balanced Tree: {comparisons_balanced_2}")
