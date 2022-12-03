#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> points;

int main()
{
    fstream fr("data.csv", ios::in);

    if (!fr.is_open())
    {
        perror("Error in opening file : ");
        return -1;
    }

    string line, cord;

    while (getline(fr, line))
    {

        stringstream str(line);

        vector<double> point;

        while (getline(str, cord, ','))
        {
            point.push_back(stod(cord));
        }

        points.push_back(point);
    }

    int n = points.size();
    int no_of_cord = points[0].size();

    vector<double> centre;
    for (int i = 0; i < no_of_cord; i++)
    {
        double sum = 0;

        for (int j = 0; j < n; j++)
        {
            sum += points[j][i];
        }

        centre.push_back(sum / n);
    }

    cout << "center " << centre[0] << " " << centre[1] << endl;
    points.push_back(centre);

    n = points.size();

    vector<vector<double>> distMatrix(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<double> pt1 = points[i];
            vector<double> pt2 = points[j];

            double sq_sum = 0;
            cout << "--------" << endl;
            for (int k = 0; k < no_of_cord; k++)
            {
                cout << "|" << pt1[k] << " - " << pt2[k] << "|"
                     << " ";
                cout << (pt1[k] - pt2[k]) << " ";
                sq_sum += (pt1[k] - pt2[k]) * (pt1[k] - pt2[k]);
            }

            distMatrix[i][j] = sqrt(sq_sum);
            cout << " ans " << sqrt(sq_sum) << endl;
        }
    }

    ofstream fw("dist_cluster_output.csv", ios::out);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << distMatrix[i][j] << " ";
            fw << distMatrix[i][j] << ",";
        }
        cout << "\n";
        fw << endl;
    }

    return 1;
}
