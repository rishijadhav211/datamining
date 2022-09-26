// 2020BTEIT00206 Rushikesh Jadhav
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low);
    int val;
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {

            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]);
    return (i);
}

void quicksort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {

        int pi = partition(nums, low, high);
        quicksort(nums, low, pi - 1);
        quicksort(nums, pi + 1, high);
    }
}

int main()
{
    ifstream fin;
    fin.open("data.csv", ios::in);
    ofstream fout;
    fout.open("data.csv", ios::out | ios::app);

    vector<int> nums;
    string word;
    while (getline(fin, word, ','))
    {
        nums.push_back(stoi(word));
    }

    quicksort(nums, 0, nums.size() - 1);

    cout << "Min----------------> " << nums[0] << endl;
    fout << endl;
    fout << "MIN," << nums[0] << endl;
    cout << "max----------------> " << nums[nums.size() - 1] << endl;
    fout << "MAX," << nums[nums.size() - 1] << endl;
    float median;
    int n = nums.size();

    if (n % 2 != 0)
        median = nums[n / 2];
    else
        median = (nums[(n - 1) / 2] + nums[n / 2]) / 2.0;

    cout << "median-------------> " << median << endl;
    fout << "Median," << median << endl;
    float Q1;
    // n = n / 2;
    if (n % 2 != 0)
    {
        Q1 = nums[n / 4];
    }
    else
    {
        Q1 = (nums[(n - 1) / 4] + nums[n / 4]) / 2.0;
    }
    cout << "Q1-----------------> " << Q1 << endl;
    fout << "Q1," << Q1 << endl;
    float Q3;
    n = nums.size();
    if (n % 2 != 0)
    {
        Q3 = nums[(3 * n) / 4];
    }
    else
    {
        Q3 = (nums[((3 * (n - 1))) / 4] + nums[(3 * n) / 4]) / 2.0;
    }
    cout << "Q3-----------------> " << Q3 << endl;
    fout << "Q3," << Q3 << endl;
    cout << "2020BTEIT00206 Rushikesh Jadhav" << endl;
}
