// correlation of items
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
    ifstream file("transactions.csv");

    ofstream fout;
    fout.open("outputcorrelation.csv", ios::out | ios::app);

    string item;
    int count = 0;
    vector<unordered_set<string>> transactions;
    unordered_map<string, double> supportcount;
    if (file.is_open())
    {

        while (file >> line)
        {
            stringstream str(line);

            unordered_set<string> temp;
            while (getline(str, item, ','))
            {
                temp.insert(item);
                supportcount[item]++;
            }
            transactions.push_back(temp);
            count++;
        }

        string A, B;
    input:
        cout << "enter Two Items to get correlation : \n";
        cin >> A >> B;

        if (supportcount.find(A) == supportcount.end() || supportcount.find(B) == supportcount.end())
        {
            cout << "no match\n";
            goto input;
        }

        double AUB = 0;

        for (auto it : transactions)
        {
            if (it.find(A) != it.end() && it.find(B) != it.end())
                AUB++;
        }

        double pAUB = AUB / count;

        double nA = supportcount[A] / count;
        double nB = supportcount[B] / count;

        cout << "Probablities : " << endl;
        cout << "A " << nA << " , B " << nB << " , AUB " << pAUB << endl;
        double ans = pAUB / (nA * nB);

        cout << "\ncorrelation : "
             << ans << endl;

        if (ans > 1)
        {
            cout << A << " and " << B << " are positively correlated" << endl;
            fout << A << " and " << B << " are positively correlated" << endl;
        }
        else if (ans < 1)
        {
            cout << A << " and " << B << " are negatively correlated" << endl;
            fout << A << " and " << B << " are negatively correlated" << endl;
        }
        else
        {
            cout << A << " and " << B << " are independent" << endl;
            fout << A << " and " << B << " are independent" << endl;
        }
    }
    return 0;
}