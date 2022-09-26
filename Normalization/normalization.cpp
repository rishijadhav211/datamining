#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;
float Maximum_Value(vector<float> MinMaxArray, int num_elements)
{
    int i, max = -32000;
    for (i = 0; i < num_elements; i++)
    {
        if (MinMaxArray[i] > max)
        {
            max = MinMaxArray[i];
        }
    }
    return (max);
}
float MinValue(vector<float> MinMaxArray, int num_elements)
{
    int i, min = 0;
    for (i = 0; i < num_elements; i++)
    {
        if (i == 0)
            min = MinMaxArray[i];
        else if (MinMaxArray[i] < min)
            min = MinMaxArray[i];
    }
    return (min);
}
float averageX(vector<float> MinMaxArray, int num_elements)
{
    float average;
    int i;
    float sum = 0;
    int valuesAboveAverage = 0;
    for (i = 0; i < num_elements; i++)
    {
        sum += MinMaxArray[i];
        average = sum / num_elements;
        if (MinMaxArray[i] > average)
            valuesAboveAverage++;
    }
    printf(" Values above the average are: %d\n", valuesAboveAverage);
    printf("Average: %f\n", average);
    return (average);
}
void norm_1D(float min, float max, float new_min, float new_max, vector<float> MinMaxArray, float num_elements)
{
    int i;
    vector<float> normalizedVal(MinMaxArray.size());
    for (i = 0; i < num_elements; i++)
    {
        normalizedVal[i] = (((MinMaxArray[i] -
                              min) /
                             (max - min)) *
                            (new_max - new_min)) +
                           new_min;
    }
    for (i = 0; i < num_elements; i++)
        printf("Normalized Values are  :%5.2f\n", normalizedVal[i]);
}
int main(void)
{
    ifstream ifile("lab1.csv", ios::in);
    vector<float> MinMaxArray;
    if (!ifile.is_open())
    {
        cerr << "There was a problem opening the input file!\n";
        exit(1); // exit or do additional error checking
    }
    float num = 0.0;
    while (ifile >> num)
    {
        MinMaxArray.push_back(num);
    }
    vector<float> dummy = MinMaxArray;
    float new_max, new_min, old_min, old_max;
    cout << "Enter New Min: ";
    cin >> new_min;
    cout << "Enter New Max: ";
    cin >> new_max;
    float average;
    old_max = Maximum_Value(MinMaxArray, MinMaxArray.size());
    old_min = MinValue(MinMaxArray, MinMaxArray.size());

    average = averageX(MinMaxArray, MinMaxArray.size());
    norm_1D(old_min, old_max, new_min, new_max, MinMaxArray, MinMaxArray.size());
    cout << "The min value is :"
         << old_min << endl;
    cout << "The max value is :"
         << old_max << endl;
    printf("\n");
    cout << "z-score Normalisation\n";
    int i;
    int n = MinMaxArray.size();
    float sd = 0.0;
    for (i = 0; i < dummy.size(); i++)
    {
        sd += pow(dummy[i] - average, 2);
    }
    float std_dev = sqrt(sd / MinMaxArray.size());
    vector<float> newArr = dummy;
    for (i = 0; i < newArr.size(); i++)
    {
        newArr[i] = (newArr[i] - average) / std_dev;
    }
    for (i = 0; i < newArr.size(); i++)
    {
        printf("z-score Values are :  %5.2f\n", newArr[i]);
    }
    return (0);
}
