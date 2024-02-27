#include <iostream>

// Define the structure for a node
struct Node
{
    int data;
    Node *next;
};

// Function to detect and remove a loop in a linked list
void detectAndRemoveLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    // Move slow pointer by one step and fast pointer by two steps
    slow = slow->next;
    fast = fast->next->next;

    // Search for a loop using the Floyd's Cycle-Finding Algorithm
    while (fast != nullptr && fast->next != nullptr)
    {
        if (slow == fast)
        {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    // If a loop is found
    if (slow == fast)
    {
        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // Set the next pointer of the last node in the loop to nullptr
        fast->next = nullptr;
    }
}

// Function to print the linked list
void printList(Node *head)
{
    Node *current = head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main()
{
    // Create a sample linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 3
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};
    head->next->next->next->next->next = head->next->next;
    printList(head);

    // Detect and remove the loop in the linked list
    detectAndRemoveLoop(head);

    std::cout << "Linked List after removing the loop: ";
    printList(head);

    return 0;
}
