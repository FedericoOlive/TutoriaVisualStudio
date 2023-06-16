#include<iostream>
using namespace std;

void main()
{
    const int maxNums = 10;
    int arr[maxNums];
	
    cout << "Ingrese " << maxNums << " numeros: ";
    for (int i = 0; i < maxNums; i++)
    {
        cin >> arr[i];
    }
    cout << endl << endl;

    cout << "Step 0: ";
    for (int j = 0; j < maxNums; j++)
    {
        cout << arr[j] << " ";	    
    }
    cout << endl;

    for (int i = 0; i < maxNums - 1; i++)
    {
        for (int j = 0; j < (maxNums - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        cout << "Step " << i + 1 << ": ";
        for (int j = 0; j < maxNums; j++)
        {
            cout << arr[j] << " ";	        
        }

        cout << endl;
    }
    cout << endl;
}