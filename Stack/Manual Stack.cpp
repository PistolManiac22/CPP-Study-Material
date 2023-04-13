#include <iostream>
using namespace std;

#define MAX 6

struct Stack
{
    int top, data[MAX];
    Stack() : top(-1), data{} {}
};

Stack stack;

bool isFull()
{
    return stack.top == MAX - 1;
}

bool isEmpty()
{
    return stack.top == -1;
}

void push(int x)
{
    if (isFull())
    {
        cout << "stack penuh" << endl;
    }
    else
    {
        stack.top++;
        stack.data[stack.top] = x;
    }
}

void pop(int input)
{
    if (isEmpty())
    {
        cout << "Tidak ada penghapusan data" << endl;
    }
    else
    {
        for (int i = 1; i <= input; i++)
        {
            int popped = stack.data[stack.top];
            cout << popped << " Telah Dihapus" << endl;
            stack.top--;
        }
    }
}

int main()
{
    int input, input2, size, opsi;
    do {
        cout << "Opsi : " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan Angka" << endl;
        cout << "Pilih : ";
        cin >> opsi;
        switch (opsi){
        case 1:
            cout << "Anda Ingin Memasukkan Berapa Angka? (MAX = 6) : ";
            cin >> size;
            for (int a = 0; a < size; a++)
            {
                cout << "Masukkan Angka : ";
                cin >> input;
                push(input);
            }
            cout << "\n";
            cout << "Angka yang dimasukkan" << endl;
            for (int i = 0; i <= stack.top; i++)
            {
                cout << stack.data[i] << endl;
            }
            break;

        case 2:
            cout << "Anda ingin menghapus berapa angka? (MAX = 6) : ";
            cin >> input2;
            pop(input2);
            cout << "\n";
            cout << "Angka setelah di hapus" << endl;
            for (int d = 0; d <= stack.top; d++)
            {
                cout << stack.data[d] << endl;
            }
            break;
        case 3:
            for (int c = 0; c <= stack.top; c++)
            {
                cout << stack.data[c] << endl;
            }
        }
    } while (true);
    return 0;
}
