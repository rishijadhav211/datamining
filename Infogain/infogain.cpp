// info gain , Entropy
// 2020BTEIT00206 Rushikesh Jadhav

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string line, word;
    ifstream file("infogain_cpp.csv");
    ofstream fout;
    fout.open("outputinfogain.csv", ios::out | ios::app);
    string day, outlook, three, four, five, six;
    map<string, int> parent;
    map<string, map<string, int>> child;
    vector<string> attribute;
    int clmnum = 1;
    cout << "Enter column number to check entropy " << endl;
    cin >> clmnum;
    // file >> line;
    if (file.is_open())
    {
        int i = 0;

        while (file >> line)
        {
            stringstream str(line);
            if (i == 0)
            {
                while (getline(str, day, ','))
                {
                    attribute.push_back(day);
                }

                i++;
                continue;
            }
            vector<string> columns;
            while (getline(str, day, ','))
            {
                columns.push_back(day);
            }

            int n = columns.size();

            parent[columns[n - 1]]++;
            child[columns[clmnum - 1]][columns[n - 1]]++;
        }

        vector<int> ParentResult;
        for (auto it : parent)
        {
            ParentResult.push_back(it.second);
        }

        // double posR = parent["Yes"], negR = parent["No"];
        double totR = accumulate(ParentResult.begin(), ParentResult.end(), 0);

        double parent_entropy;
        for (int i = 0; i < ParentResult.size(); i++)
        {
            parent_entropy += -(ParentResult[i] / totR * log2(ParentResult[i] / totR));
        }

        // double parent_entropy = -((posR / totR) * log2(posR / totR) + (negR / totR) * log2(negR / totR));
        double child_entropy_pro = 0;
        cout << "----" << endl;

        for (auto p : child)
        {
            bool broke = false;
            string val = p.first;

            double addition = 0;
            for (auto it : parent)
            {
                if (child[val][it.first] == 0)
                {
                    broke = true;
                    break;
                }
                addition += child[val][it.first];
            }
            if (broke == true)
                continue;

            double childentro = 0;
            for (auto it : parent)
            {

                cout << (child[val][it.first] / addition) * log2(child[val][it.first] / addition) << " + ";
                childentro += -1 * ((child[val][it.first] / addition) * log2(child[val][it.first] / addition));
            }
            cout << endl;

            child_entropy_pro += (addition / totR) * (childentro);
        }
        cout << "parent_entropy : " << parent_entropy << "  child_entropy_pro : " << child_entropy_pro << endl;
        cout << "Info gain : " << attribute[clmnum] << " " << parent_entropy - child_entropy_pro << "\n";

        fout << "\n infogain of " << attribute[clmnum] << parent_entropy - child_entropy_pro << endl;
    }
    else
    {
        cout << "Could not open the file\n";
    }

    return 0;
}