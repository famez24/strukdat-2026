#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int nilai) {
    Node* nodeBaru = new Node();
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;

    if (*head == NULL) {
        *head = nodeBaru;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = nodeBaru;
    }
}

int main() {
    Node* head = NULL;
    int n, nilai;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Masukkan angka: ";
        cin >> nilai;
        insertNode(&head, nilai);
    }
    cout << "Hasil: " << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> "; 
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}
