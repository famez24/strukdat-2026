#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;

// CLASS NODE — Representasi satu folder
class Node {
public:
    string name;
    Node* parent;
    vector<Node*> children;

    Node(string folderName, Node* p = nullptr)
        : name(folderName), parent(p) {}
};

// CLASS FOLDER TREE — General Tree
class FolderTree {
private:
    Node* root;

    void deleteSubtree(Node* node) {
        if (node == nullptr) return;
        for (Node* child : node->children)
            deleteSubtree(child);
        delete node;
    }

    void printTree(Node* node, string prefix, bool isLast) {
        if (node == nullptr) return;

        cout << prefix;
        if (node != root) {
            cout << (isLast ? "└── " : "├── ");
        }
        cout << node->name << "\n";

        string childPrefix = prefix + (node != root ? (isLast ? "    " : "│   ") : "");
        for (int i = 0; i < (int)node->children.size(); i++) {
            bool last = (i == (int)node->children.size() - 1);
            printTree(node->children[i], childPrefix, last);
        }
    }

public:
    FolderTree() {
        root = new Node("Root");
    }
    ~FolderTree() {
        deleteSubtree(root);
    }

    // GET ROOT
    Node* getRoot() {
        return root;
    }
    // MAKE NEW FOLDER
    bool addFolder(const string& parentName, const string& folderName) {
        Node* parent = search(root, parentName);
        if (parent == nullptr) {
            cout << "[ERROR] Folder parent '" << parentName << "' tidak ditemukan!\n";
            return false;
        }
        for (Node* child : parent->children) {
            if (child->name == folderName) {
                cout << "[ERROR] Folder '" << folderName
                     << "' sudah ada di dalam '" << parentName << "'!\n";
                return false;
            }
        }

        Node* newFolder = new Node(folderName, parent);
        parent->children.push_back(newFolder);
        cout << "[OK] Folder '" << folderName
             << "' berhasil ditambahkan ke '" << parentName << "'\n";
        return true;
    }

    // DELETE FOLDER
    bool deleteFolder(const string& folderName) {
        Node* target = search(root, folderName);
        if (target == nullptr) {
            cout << "[ERROR] Folder '" << folderName << "' tidak ditemukan!\n";
            return false;
        }
        if (target == root) {
            cout << "[ERROR] Root tidak dapat dihapus!\n";
            return false;
        }
        Node* parent = target->parent;

        auto it = find(parent->children.begin(), parent->children.end(), target);
        if (it != parent->children.end())
            parent->children.erase(it);

        int jumlah = countFolder(target);
        deleteSubtree(target);

        cout << "[OK] Folder '" << folderName
             << "' beserta " << jumlah - 1 << " subfolder berhasil dihapus!\n";
        return true;
    }
    // MENAMPILKAN STRUKTUR DIREKTORI
    void tampilkanStruktur() {
        cout << "\n";
        printTree(root, "", true);
    }
    // MENCARI FOLDER 
    Node* search(Node* node, const string& target) {
        if (node == nullptr) return nullptr;
        if (node->name == target) return node;

        for (Node* child : node->children) {
            Node* result = search(child, target);
            if (result != nullptr) return result;
        }
        return nullptr;
    }
    bool cariFolder(const string& folderName) {
        Node* result = search(root, folderName);
        if (result != nullptr) {
            cout << "[DITEMUKAN] Folder '" << folderName << "' ada dalam sistem.\n";
            cout << "            ";
            tampilkanPath(folderName);
            return true;
        } else {
            cout << "[TIDAK DITEMUKAN] Folder '" << folderName << "' tidak ada.\n";
            return false;
        }
    }
    // MENGHITUNG JUMLAH FOLDER
    int countFolder(Node* node) {
        if (node == nullptr) return 0;
        int total = 1;
        for (Node* child : node->children)
            total += countFolder(child);
        return total;
    }
    int hitungFolder() {
        return countFolder(root);
    }
    // MENAMPILKAN PATH LENGKAP
    void tampilkanPath(const string& folderName) {
        Node* target = search(root, folderName);
        if (target == nullptr) {
            cout << "[ERROR] Folder '" << folderName << "' tidak ditemukan!\n";
            return;
        }
        vector<string> path;
        Node* current = target;
        while (current != nullptr) {
            path.push_back(current->name);
            current = current->parent;
        }
        cout << "Path: ";
        for (int i = (int)path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << "/";
        }
        cout << "\n";
    }
    // PREORDER TRAVERSAL (Root → Child)
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << "  " << node->name << "\n";
        for (Node* child : node->children)
            preorder(child);
    }
    void traversalPreorder() {
        cout << "Urutan: Root → Child\n";
        preorder(root);
    }
    // POSTORDER TRAVERSAL (Child → Root)
    void postorder(Node* node) {
        if (node == nullptr) return;
        for (Node* child : node->children)
            postorder(child);
        cout << "  " << node->name << "\n";
    }
    void traversalPostorder() {
        cout << "Urutan: Child → Root\n";
        postorder(root);
    }
};

// Cetak header section
void printHeader(const string& judul) {
    cout << "\n";
    cout << "======================================\n";
    cout << "  " << judul << "\n";
    cout << "======================================\n";
}

int main() {
   SetConsoleOutputCP(CP_UTF8);
    cout << "======SIMULASI SISTEM FOLDER KOMPUTER======\n";

    FolderTree tree;
    Node* root = tree.getRoot();

    printHeader("MEMBUAT STRUKTUR FOLDER");

    tree.addFolder("Root", "Documents");
    tree.addFolder("Root", "Pictures");
    tree.addFolder("Root", "Music");
    tree.addFolder("Root", "Downloads");

    tree.addFolder("Documents", "Kuliah");
    
    // Tampilkan Struktur Direktori
    printHeader("STRUKTUR DIREKTORI");
    tree.tampilkanStruktur();

    // Preorder Traversal
    printHeader("PREORDER TRAVERSAL");
    tree.traversalPreorder();

    // Postorder Traversal
    printHeader("POSTORDER TRAVERSAL");
    tree.traversalPostorder();

    // Pencarian Folder
    printHeader("PENCARIAN FOLDER");
    tree.cariFolder("Semester2");
    tree.cariFolder("Music");
    tree.cariFolder("VideoGame"); 

    // Menampilkan Path
    printHeader("PATH LENGKAP FOLDER");
    tree.tampilkanPath("Semester1");
    tree.tampilkanPath("Kuliah");
    tree.tampilkanPath("Dokumen");

    // Menghitung Jumlah Folder
    printHeader("MENGHITUNG JUMLAH FOLDER");
    cout << "Total folder dalam sistem : " << tree.hitungFolder() << "\n";

    // Menghapus Folder
    printHeader("MENGHAPUS FOLDER");
    tree.deleteFolder("Pictures");    
    tree.deleteFolder("Semester1");  
    tree.deleteFolder("Root");        
    tree.deleteFolder("XYZFolder");   

    // Struktur Setelah Delete
    printHeader("STRUKTUR SETELAH PENGHAPUSAN");
    tree.tampilkanStruktur();

    // Jumlah Folder Setelah Delete
    printHeader("JUMLAH FOLDER SETELAH PENGHAPUSAN");
    cout << "Total folder dalam sistem : " << tree.hitungFolder() << "\n";

    return 0;
}
