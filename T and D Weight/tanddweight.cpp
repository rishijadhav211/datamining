// 2020BTEIT00206 Rushikesh Jadhav
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

    vector<double> firstrow;
    vector<double> secondrow;
    vector<double> firstcolumn;
    vector<double> secondcolumn;
    for (int i = 0; i < nums.size(); i++)
    {
        double t_wt, d_wt = 0;
        for (int j = 0; j < nums[i].size(); j++)
        {
            if (i == 0)
            {
                t_wt = (nums[i][j] / r1_tot) * 100;
                cout << "T weight for data" << nums[i][j] << "=" << t_wt << endl;
                firstrow.push_back(t_wt);
            }
            if (i == 1)
            {
                t_wt = (nums[i][j] / r2_tot) * 100;
                cout << "T weight for data" << nums[i][j] << "=" << t_wt << endl;
                secondrow.push_back(t_wt);
            }
            if (j == 0)
            {
                d_wt = (nums[i][j] / c1_tot) * 100;
                cout << "D weight for data" << nums[i][j] << "=" << (nums[i][j] / c1_tot) * 100 << endl;
                firstcolumn.push_back(d_wt);
            }
            if (j == 1)
            {
                d_wt = (nums[i][j] / c2_tot) * 100;
                cout << "D weight for data " << nums[i][j] << "=" << d_wt << endl;
                secondcolumn.push_back(d_wt);
            }
            cout << endl;
        }
        cout << "------------------------------\n";
    }
    cout << "T Weight \n";
    double total = 0;
    for (auto i : firstrow)
    {
        cout << i << " ";
        total = i + total;
    }
    cout << total << "\n";

    total = 0;
    for (auto i : secondrow)
    {
        cout << i << " ";
        total = i + total;
    }
    cout << total << "\n";

    cout << "-----------------------\n";

    cout << "D Weight\n";
    double firstcolumntotal;
    double secondcolumntotal;
    bool flag = 1;
    for (int i = 0; i < 2;)
    {
        if (flag == 1)
        {
            cout << firstcolumn[i] << " ";
            firstcolumntotal = firstcolumntotal + firstcolumn[i];
            flag = 0;
        }
        else
        {
            cout << secondcolumn[i] << "\n";
            secondcolumntotal = secondcolumntotal + secondcolumn[i];
            flag = 1;
            i++;
        }
    }
    cout << firstcolumntotal << "       " << secondcolumntotal;

    fin.close();
    return 0;
}