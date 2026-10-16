/////////////////////////////////////////////////////////////////////
// Name: Justin Miller
// Date: 10/15/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Program #2 of 2, takes information from a given text file to classify weight class
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

double getBMI(double gWeight, double gHeight);
double cmConvert(double cm);
string gClassification(double gBMI);

int main()
{
    double pWeight = 0, pHeight = 0, pCount = 0, pBMI;
    string pFName, pLName, pName, pClass;
    ifstream fin;
    fin.open("patients.txt");
    fin >> pCount;
    if (pCount <= 0)
    {
        cout << "The value you've given is too low. Please retry and enter a value of 1 or higher. Don't go too high though, that's a pain.";
    }
    for (int i = 0; i < pCount; i++)
    {
            
        fin >> pFName >> pLName;
        pName = pFName + " " + pLName;
        fin >> pWeight;
        if (pWeight <= 0 || pWeight >= 635)
            {
                cout << "ERROR: The value " << pWeight << " is invalid for weight in kilograms.\nREASON: Too low, or impossibly high."; //I looked it up, and 635 kg is something like the heaviest ever recorded.
                break;
            }
        fin >> pHeight;
        pHeight = cmConvert(pHeight);
        if (pHeight <= 0 || pHeight >= 272)
            {
                cout << "ERROR: The value " << pHeight << " is invalid for height in centimeters.\nREASON: Too low, or impossibly high."; //Same as before, apparently 272 is crazy high.
                break;
            }
        pBMI = getBMI(pWeight, pHeight);
        pClass = gClassification(pBMI);
        cout << pName << " 's BMI is: " << pBMI << endl;
        cout << "The BMI classification is " << pClass << endl << endl;
    }

    cout << "\nThank you for using our system.";
    return 0;
}

double getBMI(double gWeight, double gHeight)
{
    cout << fixed << setprecision(2);
    double squaredHeight = gHeight * gHeight;
    double gBMI = gWeight / squaredHeight;
    return gBMI;
}

double cmConvert(double cm)
{
    double meters = cm / 100.0;
    return meters;
}

string gClassification(double gBMI)
{
    string gClass;
    if (gBMI < 18.5)
    {
        // cout << "Underweight; BMI less than 18.5";
        gClass = "Underweight";
    }
    else if (gBMI < 25)
    {
        // cout << "Normal weight; BMI is in the range between 18.5 and 24.9";
        gClass = "Normal";
        
    }
    else if (gBMI < 30)
    {
        //cout << "Overweight; BMI is in the range between 25 and 29.9";
        gClass = "Overweight";
    }
    else
    {
        //cout << "Obese; BMI is greater than 30";
        gClass = "Obese";
    }
    return gClass;
}