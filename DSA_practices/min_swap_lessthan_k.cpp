#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Complet the function
        int cntswap = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] <= k)
                {
                    swap(arr[i], arr[j]);
                    cntswap++;
                    break;
                }
            }
        }
        return cntswap;
    }
};

int main()
{

    int n, k;
        cout<<"Enter size of array ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout<<"Enter range ";
        cin >> k;
        Solution ob;
        cout <<"Minimum swap needed: "<< ob.minSwap(arr, n, k) << "\n";

        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}
