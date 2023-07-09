#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Node.h"
using namespace std;

// Function to insert a node in the circular linked list
void insert(Node** start, const string& name)
{
    // If the list is empty, create a single node
    // circular and doubly linked list
    if (*start == nullptr) {
        Node* new_node = new Node;
        new_node->name = name;
        new_node->next = new_node->previous = new_node;
        *start = new_node;
        return;
    }

    // If list is not empty

    /* Find the last node */
    Node* last = (*start)->previous;

    // Create a new node dynamically
    Node* new_node = new Node;
    new_node->name = name;

    // Start will be the next of the new_node
    new_node->next = *start;

    // Make the new node previous of start
    (*start)->previous = new_node;

    // Make the last node previous of the new node
    new_node->previous = last;

    // Make the new node next of the last node
    last->next = new_node;
}

// Function to delete a given node from the circular linked list
void deleteNode(Node** start, const string& name, int& numDrawn)
{
    // If the list is empty
    if (*start == nullptr)
    {
        cout << "Your night watchers are dead!" << endl;
        return;
    }

    // Find the required node
    // Declare two pointers and initialize them
    Node* curr = *start, * prev = nullptr;
    while (curr->name != name)
    {
        prev = curr;
        curr = curr->next;
    }

    cout << curr->name << " has drawn " << numDrawn << endl;

    // Iterate through the list to pass the cloak
    for (int i = 0; i < numDrawn; ++i)
    {
        curr = curr->next;
    }

    // Eliminate the current node
    if (prev == nullptr)
    {
        *start = curr->next;
    }

    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;

    cout << curr->name << " was eliminated" << endl << endl;
    delete curr;
}

// Function to display the remaining members of the Night's Watch
void displayMembers(Node* start)
{
    if (start == nullptr)
    {
        cout << "There are no remaining members in the Night's Watch." << endl;
        return;
    }

    Node* current = start;
    cout << "Remaining Members:" << endl << endl;
    do {
        cout << "    " << current->name << endl << endl;
        current = current->next;
    } while (current != start);
}

// Driver program to test the Night's Watch game
int main()
{
    srand(time(0));
    vector<string> members;
    int numMembers;

    cout << "Enter the number of members in the Night's Watch: ";
    cin >> numMembers;

    for (int i = 0; i < numMembers; ++i)
    {
        string name;
        cout << "Enter the name of member " << i + 1 << ": ";
        cin >> name;
        members.push_back(name);
    }

    Node* head = nullptr;

    for (const auto& member : members)
    {
        insert(&head, member);
    }

    cout << "==========================================" << endl;
    cout << "ROUND 1" << endl;
    cout << "==========================================" << endl;

    displayMembers(head);
    cout << endl << endl;

    int round = 1;

    while (head->next != head)
    {
        cout << "Result: " << endl << endl;

        string currentMember = head->name;
        int numDrawn = rand() % members.size() + 1;

        deleteNode(&head, currentMember, numDrawn);
        displayMembers(head);

        cout << endl;

        if (head->next != head) {
            cout << "==========================================" << endl;
            cout << "ROUND " << ++round << endl;
            cout << "==========================================" << endl;
        }
    }

    cout << "==========================================" << endl;
    cout << "FINAL RESULT" << endl;
    cout << "==========================================" << endl;

    cout << "   " << head->name << " will go to seek reinforcements." << endl;

    return 0;
}