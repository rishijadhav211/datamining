//2020BTEIT00206 Rushikesh Jadhav
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream fin;
    fin.open("data.csv", ios::in);

    vector<vector<int>> nums;
    string word;
    fin >> word;
    int count = 0;
    while (fin >> word)
    {
        stringstream ss(word);
        string values;
        vector<int> temp;
        getline(ss, values, ',');
        while (getline(ss, values, ','))
        {
            temp.push_back(stoi(values));
        }
        nums.push_back(temp);
    }

    float c1_tot = 0;
    float c2_tot = 0;
    float r1_tot = 0;
    float r2_tot = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (i == 0)
            {
                r1_tot = r1_tot + nums[i][j];
            }
            if (i == 1)
            {
                r2_tot = r2_tot + nums[i][j];
            }
            if (j == 0)
            {
                c1_tot = c1_tot + nums[i][j];
            }
            if (j == 1)
            {
                c2_tot = c2_tot + nums[i][j];
            }
        }
    }

    cout << "row 1 " << r1_tot << endl;
    cout << "row 2 " << r2_tot << endl;
    cout << "colum 1 " << c1_tot << endl;
    cout << "colum 2 " << c2_tot << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (i == 0)
            {
                cout << "T weight for data" << nums[i][j] << "=" << (nums[i][j] / r1_tot) * 100 << endl;
            }
            if (i == 1)
            {
                cout << "T weight for data" << nums[i][j] << "=" << (nums[i][j] / r2_tot) * 100 << endl;
            }
            if (j == 0)
            {
                cout << "D weight for data" << nums[i][j] << "=" << (nums[i][j] / c1_tot) * 100 << endl;
            }
            if (j == 1)
            {
                cout << "D weight for data " << nums[i][j] << "=" << (nums[i][j] / c2_tot) * 100 << endl;
            }
            cout << endl;
        }
    }
    cout << "2020BTEIT00206 Rushikesh Jadhav" << endl;

    fin.close();
    return 0;
}