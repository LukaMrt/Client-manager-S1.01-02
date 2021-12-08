from typing import Optional


class Node:
    def __init__(self):
        self.data = None
        self.next = None


def merge_sort(head: Node) -> Optional[Node]:
    """
    pre-condition : none
    post-condition : return the list head sorted or None if head is None
    """
    if head is None or head.next is None:
        return head

    fast = head
    slow = head

    while fast.next is not None and fast.next.next is not None:
        fast = fast.next.next
        slow = slow.next

    middle = Node()
    middle.data = slow.next.data
    middle.next = slow.next.next
    slow.next = None

    left = merge_sort(head)
    right = merge_sort(middle)

    sortedlist = merge(left, right)
    return sortedlist


def merge(start: Node, end: Node) -> Optional[Node]:
    """
    pre-condition : none
    post-condition : return None if start and end are None, or start
                            linked to end if start < end, the reverse otherwise
    """
    if start is None:
        return end

    if end is None:
        return start

    if start.data < end.data:
        start.next = merge(start.next, end)
        return start

    end.next = merge(start, end.next)
    return end


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
    
    head = merge_sort(node2)

    while head is not None:
        print(head.data)
        head = head.next
