#include <iostream>

using namespace std;

#define MAX 6

struct Queue
{
    int tail = -1, head = -1;
    string data[MAX];
} q;

bool isFull()
{
    return q.tail == MAX - 1;
}

bool isEmpty()
{
    return q.tail == -1;
}

void inQueue(string x)
{
    if(isFull())
    {
        cout << "Maaf, Bookmark sudah penuh!" << endl;
    }
    else
    {
        q.tail++;
        q.data[q.tail] = x;
        cout << q.data[q.tail] << " Berhasil dimasukkan ke bookmark" << endl;
    }
}

void deQueue()
{
    if(isEmpty())
    {
        cout << "Maaf, Bookmark Kosong!" << endl;
    }
    else
    {
        int i = 1; 
        string pop = q.data[0]; 

        cout << pop << " dihapus dari bookmark!" << endl;
        while (i<=q.tail)
        { 
            q.data[i-1]=q.data[i]; 
            i++; 
        } 
        q.tail--; 
    }
}

int main()
{
    int banyak = 0;
    inQueue("UPI");
    banyak++;
    inQueue("Cibiru");
    banyak++;
    inQueue("RPL");
    banyak++;
    cout << endl ;
    cout << "Bookmark Terbaru : " << q.data[q.tail] << endl;
    deQueue();
    banyak--;

    for(int i = 0; i < banyak; i++)
    {
        cout << "Bookmark : "<< q.data[i] << endl;
    }
} 