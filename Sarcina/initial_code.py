import numpy as np
import itertools

class Node(object):

    def __init__(self, id, level, action, state, value, reward, parent, children=None):
        self.id = id
        self.level = level
        self.parent = parent
        self.action = action
        self.state = state
        self.value = value
        self.children = list() if children is None else children

def dfs(node):
    path = list()
    def recurse(n):
        path.append(n)
        if not n.children:
            yield path
        for child in n.children:
            for x in recurse(child):
                yield x

        path.pop()
    for v in recurse(node):
        yield path

def Add_Nodes(level, actions):
    global root
    global idk
    global childs
    childs_new = []
    for child in childs:
      for a in range(6):
          idk += 1
          v = np.random.randint(0,100)
          s = np.random.randint(0,100)
          child.children.append( Node(idk, level+1, a, s, v, child, None) )
      childs_new += child.children
    childs = childs_new

idk = 0
childs = []
root = None
actions = 6
levels = 6
root = Node(idk, 0, 0, 0, 0, None, None)
childs.append(root)

for i in range(levels):
  Add_Nodes(i, actions)
max_path_value = 0
maxpath = None

for path in dfs(root):    
    path_str = ""
    for n in path:
          path_str +=  "{}({}), ".format(n.id, n.value)
    path_value = sum(n.value for n in path)
    print("{} : {}".format(path_value, path_str))

    if max_path_value < path_value:
      max_path_value = path_value
      maxpath = "{} : {}".format(path_value, path_str)

print("Maximum path:\n", maxpath, "\n")  