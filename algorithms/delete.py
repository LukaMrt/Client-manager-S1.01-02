from typing import Optional


class Node:
    def __init__(self):
        self.data = None
        self.next = None


def delete(list: Node, data: int) -> Optional[Node]:
    """
    pre-cond : date is not None
    post-cond : return a list with values different from given data
    """
    new_head = None
    current = None

    while list is not None:

        if data != list.data:

            if new_head is None:
                new_head = Node()
                current = new_head
            else:
                current.next = Node()
                current = current.next

            current.data = list.data

        list = list.next

    return new_head


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

    list = delete(node2, 4)

    while list is not None:
        print(list.data)
        list = list.next
