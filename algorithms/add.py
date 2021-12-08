class Node:
    def __init__(self):
        self.data = None
        self.next = None


def add(list: Node, node: Node) -> Node:
    """
    pre-condition: node is not None and node.next is None
    post-condition : return the new head
    """
    node.next = list
    return node


if __name__ == '__main__':

    head = None

    node1 = Node()
    node1.data = 1
    head = add(head, node1)

    copy = head
    print("---")
    while copy is not None:
        print(copy.data)
        copy = copy.next

    node2 = Node()
    node2.data = 2
    head = add(head, node2)

    copy = head
    print("---")
    while copy is not None:
        print(copy.data)
        copy = copy.next

    node3 = Node()
    node3.data = 3
    head = add(head, node3)

    copy = head
    print("---")
    while copy is not None:
        print(copy.data)
        copy = copy.next

