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
    string day, outlook, three, four, five, six;
    map<string, int> parent;
    map<string, map<string, int>> child;

    file >> line;
    if (file.is_open())
    {
        int i = 0;

        while (file >> line)
        {
            stringstream str(line);
            if (i == 0)
            {
                i++;
                continue;
            }
            getline(str, day, ',');
            getline(str, outlook, ',');
            getline(str, three, ',');
            getline(str, four, ',');
            getline(str, five, ',');
            getline(str, six, ',');

            parent[six]++;
            child[five][six]++;
        }
        double posR = parent["Yes"], negR = parent["No"];
        double totR = posR + negR;
        double parent_entropy = -((posR / totR) * log2(posR / totR) + (negR / totR) * log2(negR / totR));
        double child_entropy_pro = 0;
        for (auto p : child)
        {
            string val = p.first;
            double pR = child[val]["Yes"], nR = child[val]["No"];
            double tR = pR + nR;

            child_entropy_pro += -((pR + nR) / totR) * ((pR / tR) * log2(pR / tR) + (nR / tR) * log2(nR / tR));
        }
        cout << "Info gain : " << parent_entropy - child_entropy_pro << "\n";
    }
    else
    {
        cout << "Could not open the file\n";
    }

    return 0;
}