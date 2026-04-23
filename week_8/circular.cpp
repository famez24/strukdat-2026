#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertNode(Node** head, int nilai) {
    Node* nodeBaru = new Node();
    nodeBaru->data = nilai;

    if (*head == NULL) {
        *head = nodeBaru;
        nodeBaru->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) temp = temp->next;
        temp->next = nodeBaru;
        nodeBaru->next = *head;
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
    if (head != NULL) {
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); 
        cout << "(kembali ke " << head->data << ")" << endl;
    }

    return 0;
}