from typing import Optional


class Node:
    def __init__(self):
        self.data = None
        self.next = None


def search(data: int, list: Node) -> Optional[Node]:
    while list is not None:
        if list.data == data:
            return list
        list = list.next

    print("user not found")
    return None


if __name__ == '__main__':
    node1 = Node()
    node2 = Node()
    node3 = Node()
    node4 = Node()
    node5 = Node()

    node1.data = 1
    node2.data = 2
    node3.data = 3
    node4.data = 4
    node5.data = 5

    node2.next = node1
    node1.next = node3
    node3.next = node5
    node5.next = node4
    node4.next = None

    found = search(3, node2)

    if found is not None:
        print(found.data)
