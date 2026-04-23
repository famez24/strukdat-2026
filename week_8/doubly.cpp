#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertNode(Node** head, int nilai) {
    Node* nodeBaru = new Node();
    nodeBaru->data = nilai;
    nodeBaru->next = NULL;
    nodeBaru->prev = NULL;

    if (*head == NULL) {
        *head = nodeBaru;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = nodeBaru;
        nodeBaru->prev = temp;
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
    cout << "Hasil (depan ke belakang): " << endl;
    Node* temp = head;
    Node* last = NULL;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        last = temp; 
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "Hasil (belakang ke depan): " << endl;
    while (last != NULL) {
        cout << last->data << " <-> ";
        last = last->prev;
    }
    cout << "NULL" << endl;
    return 0;
}