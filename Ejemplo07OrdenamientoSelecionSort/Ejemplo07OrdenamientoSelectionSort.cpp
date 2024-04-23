#include<iostream>
using namespace std;

void main()
{
    const int maxNums = 5;
    int arr[maxNums] = { 5, 1, 4, 3, 2 };

    //cout << "Ingrese " << maxNums << " numeros: ";
    //for (int i = 0; i < maxNums; i++)
    //{
    //    cin >> arr[i];
    //}
    //cout << endl << endl;

    cout << "Step 0: ";
    for (int j = 0; j < maxNums; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;


    for (int i = 0; i < maxNums - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < maxNums; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

        cout << "Step " << i + 1 << ": ";
        for (int j = 0; j < maxNums; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
}