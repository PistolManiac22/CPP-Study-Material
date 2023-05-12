#include <iostream>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
};

tree *pohon, *root;

void deklarasi()
{
    pohon = NULL;
}

void masuktree(tree **root, int nilai)
{
    tree *newNode;
    if ((*root) == NULL)
    {
        newNode = new tree;
        newNode->data = nilai;
        newNode->left = NULL;
        newNode->right = NULL;

        (*root) = newNode;

        cout << "Nilai " << newNode->data << " masuk sebagai root" << endl;
    }
    else if (nilai < (*root)->data)
    {
        masuktree(&((*root)->left), nilai);
        cout << "Data " << nilai << " sudah masuk sebelah kiri" << endl;
    }
    else
    {
        masuktree(&((*root)->right), nilai);
        cout << "Data " << nilai << " sudah masuk sebelah kanan" << endl;
    }
}

// preOrder: Root-Left-Right
void preOrder(tree *root)
{
    if (root != NULL)
    {
        // Print Data Node
        cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }
}

// inOrder: Left-Root-Right
void inOrder(tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);

        // Print Data Node
        cout << root->data << " ";

        inOrder(root->right);
    }
}

// postOrder:Left-Right-Root
void postOrder(tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    int input, data, opsi;
    deklarasi();
    cout << "Anda ingin memasukkan berapa data : ";
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        cout << "Masukkan Data " << i + 1 << " : ";
        cin >> data;
        masuktree(&pohon, data);
    }
    cout << "Opsi :" << endl;
    cout << "1. preOrder" << endl;
    cout << "2. inOrder" << endl;
    cout << "3. postOrder" << endl;
    cout << "Pilih : ";
    cin >> opsi;

    switch (opsi)
    {
    case 1:
        cout << "\nOUTPUT PRE ORDER : ";
        cout << "\n------------------\n";
        if (pohon != NULL)
        {
            preOrder(pohon);
        }
        else
        {
            cout << "Masih kosong!";
        }
        break;
    case 2:
        cout << "\nOUTPUT IN ORDER : ";
        cout << "\n------------------\n";
        if (pohon != NULL)
        {
            inOrder(pohon);
        }
        else
        {
            cout << "Masih kosong!";
        }
        break;
    case 3:
        cout << "\nOUTPUT POST ORDER : ";
        cout << "\n------------------\n";
        if (pohon != NULL)
        {
            postOrder(pohon);
        }
        else
        {
            cout << "Masih kosong!";
        }
        break;
    }
}