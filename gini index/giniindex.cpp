
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
    ifstream file("gini_index_cpp.csv");
    string outlook, temp, humidity, windy, six;
    map<string, int> parent;
    map<string, map<string, int>> childoutlook, childTemp, childHumidity, childWindy;
    int count = 0;
    file >> line;
    if (file.is_open())
    {

        while (file >> line)
        {
            stringstream str(line);
            getline(str, outlook, ',');
            getline(str, temp, ',');
            getline(str, humidity, ',');
            getline(str, windy, ',');
            getline(str, six, ',');

            parent[six]++;
            childoutlook[outlook][six]++;
            childTemp[temp][six]++;
            childHumidity[humidity][six]++;
            childWindy[windy][six]++;
            count++;
        }

        double minimum = 0;
        double gini = 0;
        for (auto p : childoutlook)
        {
            string val = p.first;
            double pR = childoutlook[val]["Play"], nR = childoutlook[val]["NoPlay"];
            double tR = pR + nR;
            gini += (tR / count) * (1 - ((pR / tR) * (pR / tR)) - ((nR / tR) * (nR / tR)));
        }
        cout << "gini index of outlook :" << gini << "\n";

        minimum = gini;
        gini = 0;
        for (auto p : childTemp)
        {
            string val = p.first;
            double pR = childTemp[val]["Play"], nR = childTemp[val]["NoPlay"];
            double tR = pR + nR;
            gini += (tR / count) * (1 - ((pR / tR) * (pR / tR)) - ((nR / tR) * (nR / tR)));
        }
        cout << "gini index of Temp :" << gini << "\n";

        minimum = min(gini, minimum);
        gini = 0;
        for (auto p : childHumidity)
        {
            string val = p.first;
            double pR = childHumidity[val]["Play"], nR = childHumidity[val]["NoPlay"];
            double tR = pR + nR;
            gini += (tR / count) * (1 - ((pR / tR) * (pR / tR)) - ((nR / tR) * (nR / tR)));
        }
        cout << "gini index of Humidiy :" << gini << "\n";
        minimum = min(gini, minimum);
        gini = 0;
        for (auto p : childWindy)
        {
            string val = p.first;
            double pR = childWindy[val]["Play"], nR = childWindy[val]["NoPlay"];
            double tR = pR + nR;
            gini += (tR / count) * (1 - ((pR / tR) * (pR / tR)) - ((nR / tR) * (nR / tR)));
        }
        cout << "gini index of Windy:" << gini << "\n";
        minimum = min(gini, minimum);

        cout << "Best Split is = " << minimum;
    }
    else
    {
        cout << "Could not open the file\n";
    }

    return 0;
}
