#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream ifile("cc.csv", ios::in);

    vector<vector<int>> nums;
    string line;
    ifile >> line;

    while (ifile >> line)
    {
        stringstream ss(line);
        string number;
        vector<int> temp;
        while (getline(ss, number, ','))
        {
            temp.push_back(stoi(number));
        }
        nums.push_back(temp);
    }

    for (int i = 0; i < nums.size() - 1; i++)
    {
        cout << "for i= " << i << " and i= " << i + 1;
        int related = 0;
        int a_count = 0;
        int b_count = 0;
        for (int j = 0; j < 7; j++)
        {
            if (nums[i][j] && nums[i + 1][j])
            {
                related++;
            }
            if (nums[i][j])
            {
                a_count++;
            }
            if (nums[i][j])
            {
                b_count++;
            }
        }

        float coefficient = (related * 1.0f) / (a_count * b_count);

        cout << " coefficient is = " << coefficient;
        if (coefficient == 1)
        {
            cout << " and are 'independently' correlated " << endl;
        }
        else if (coefficient < 1.0)
        {
            cout << " and are 'negatively' correlated" << endl;
        }
        else if (coefficient > 1.0)
        {
            cout << " and are 'positively' correlated" << endl;
        }
    }
    return 0;
}