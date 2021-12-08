from typing import Optional
import re


class Node:
    def __init__(self):
        self.data = None
        self.next = None


def filter(regex: str, list: Node) -> Optional[Node]:
    new_head = None
    current = None

    while list is not None:

        if re.match(regex, str(list.data)):

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

    found = filter('[0-2]', node2)

    while found is not None:
        print(found.data)
        found = found.next
