#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>& nums, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = nums[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        nums[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        nums[k] = R[j];
        j++;
        k++;
    }
}

// merge sort
void merge_sort(vector<int>& nums, int left, int right)
{
    if(left >= right) return;

    int mid = (left + right) / 2;

    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);

    merge(nums, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    merge_sort(nums, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout << nums[i] << " ";

    return 0;
}
