#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        int size = 0;
    }

    void insert(int val)
    {
        size++;
        arr[size] = val;
        int index = size;

        while (index > 1)
        {
            int parentindex = index / 2;
            if (arr[parentindex] < arr[index])
            {
                swap(arr[parentindex], arr[index]);
                index = parentindex;
            }
            else
            {
                return;
            }
        }
    }

    void deleteroot()
    {
        if (size == 0)
            return;
        arr[1] = arr[size];
        size--;

        int i = 1;

        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;
            if (leftindex < size && arr[i] < arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // n/2 +1  --> n ma leaf node hota ha
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
} // o(n);

// HEAP SORT ;
void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1)
    }
}

// priorty_queue

int main()
{
    heap h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.print();
    h.deleteroot();
    h.print();
    int arr[] = {-1, 1, 2 3, 4, 5};
    n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i)
    }
    return 0;
}