#include <bits/stdc++.h>

using namespace std;

string qiu[100];
int front = -1, rear = -1;

void enqueue(string nama) {
    if (rear == 100 - 1) {
        cout << "Antrian Penuh!" << endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        qiu[rear] = nama;
        cout << nama << " masuk antrian." << endl;
    }
}

void dequeue() {
    if (front == -1) {
        cout << "Antrian Kosong!" << endl;
    } else {
        cout << "Melayani mahasiswa: " << qiu[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

int main() {
    enqueue("A");
    enqueue("B");
    enqueue("C");

    dequeue();

    enqueue("D");

    if (front == -1) {
        cout << "Antrian Kosong." << endl;
    } else {
        cout << "Antrian Saat Ini: ";
        for (int i = front; i <= rear; i++) {
            cout << qiu[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
