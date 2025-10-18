from typing import Any, Optional

class Node:
    def __init__(
        self,
        key,
        val,
        left: Optional["Node"] = None, 
        right: Optional["Node"] = None):
        self.key = key
        self.val = val
        self.left = left
        self.right = right


class LRUCache:
    def __init__(self, cap):
        self.max_entries = cap
        # map key to node containing value in deque
        self.hash_map: dict[Any, Node] = {}

        # sentinel nodes that denote start and end of deque
        self.front = Node(-1, -1)
        self.back = Node(-1, -1)
        self.front.right = self.back
        self.back.left = self.front

    def _delete(self, node: Node):
        node_l = node.left
        node_r = node.right
        node_l.right = node_r
        node_r.left = node_l
        del self.hash_map[node.key]

    def insert(self, key, val):
        if key in self.hash_map:
            # if found, delete current node since we arent using it anymore
            self._delete(self.hash_map[key])
        
        # create new node and put it to the front
        new_node = Node(key, val, self.front, self.front.right)
        self.front.right.left = new_node
        self.front.right = new_node
        self.hash_map[key] = new_node

        # delete back node if capacity is hit
        if len(self.hash_map) > self.max_entries:
            self._delete(self.back.left)

    
    def check(self, key):
        # if not found, return None
        if key not in self.hash_map:
            return None

        # else, return value
        node = self.hash_map[key]
        ans = node.val

        # put searched value to the front
        self.insert(node.key, node.val)

        return ans

    def __repr__(self):
        out_str = []
        curr = self.front.right
        while curr != self.back:
            out_str.append(f"({str(curr.key)}, {str(curr.val)})")
            curr = curr.right
        return f"Cache: {' -> '.join(out_str)}"