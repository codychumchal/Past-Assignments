/******************************************************
File Name: prog02_A04293582.cpp

Author: Cody Chumchal
Date: 2/6/15
Problem Number: 2
CS 2308 Spring 2015
Instructor: Priebe

This program grades tests by comparing student's
answers to a test key. Each students score will be
written to an output file. A final report will
 be created showing the number of each grade earned
 along with the high, low, and mean score.

*******************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUM_QUESTIONS = 10;

//Function Prototypes
int gradeTest(string key, string test);
void printReport(int scores[], ofstream & fout);
int getHighGrade(int scores[], int SIZE);
int getLowGrade(int scores[], int SIZE);
double getMeanGrade(int scores[], int SIZE);

int main()
{
    //Open input file
    ifstream fin;
    fin.open("grade_data.txt");

    //Create and open output file
    ofstream fout;
    fout.open("grade_report.txt");

    //Variables
    string key;
    string test;
    const int SIZE = NUM_QUESTIONS + 1;
    int scores[SIZE] = {0};
    int studentNum = 0;
    int highGrade;
    int lowGrade;
    double meanGrade;

    //Read the test key
    getline(fin, key);

    //Grade tests, update scores array, write grade to file
    while(getline(fin, test))
    {
        int grade;

        if(test != "")
        {
            //Grade test
            grade = gradeTest(key, test);

            //Update scores array
            scores[grade] = scores[grade] + 1;

            //Write student's grade to ofile
            fout << "Student " << (studentNum + 1) << ": " << grade << endl;
        }
        studentNum++;
    }

    fout << endl;
    fout << "Final Report" << endl;
    fout << "------------" << endl;

    printReport(scores, fout);

    //Get the high, low, and mean grade
    highGrade = getHighGrade(scores, SIZE);
    lowGrade = getLowGrade(scores, SIZE);
    meanGrade = getMeanGrade(scores, SIZE);

    //Write high, low, and mean scores to file
    fout << setprecision(2) << fixed << showpoint;
    fout << endl;
    fout << "High Score: " << highGrade << endl;
    fout << "Low Score: " << lowGrade << endl;
    fout << "Mean Score: " << meanGrade << endl;

    //Close files
    fin.close();
    fout.close();

    return 0;
}

/******************************************************
Function name: gradeTest
Parameters: string key, string test
Return value: int
*******************************************************/
int gradeTest(string key, string test)
{
    int grade = 0;

    for(int i=0; i < NUM_QUESTIONS; i++)
    {
        if(key[i] == test[i])
        {
            grade++;
        }
    }

    return grade;
}

/******************************************************
Function name: printReport
Parameters: int scores[], ofstream & fout
Return value: void
*******************************************************/
void printReport(int scores[], ofstream & fout)
{
    for(int i = NUM_QUESTIONS; i >= 0; i--)
    {
        fout << i << " - " << scores[i] << endl;
    }
}

/******************************************************
Function name: getHighGrade
Parameters: int scores[], int SIZE
Return value: int
*******************************************************/
int getHighGrade(int scores[], int SIZE)
{
    int highest = 0;

    for(int i=0; i < SIZE; i++)
    {
        if(scores[i] > 0)
        {
            if(i > highest)
                highest = i;
        }
    }
    return highest;
}

/******************************************************
Function name: getLowGrade
Parameters: int scores[], int SIZE
Return value: int
*******************************************************/
int getLowGrade(int scores[], int SIZE)
{
    int lowest = NUM_QUESTIONS;

    for(int i=0; i < SIZE; i++)
    {
        if(scores[i] > 0)
        {
           if(i < lowest)
                lowest = i;
        }
    }
    return lowest;
}
/******************************************************
Function name: getMeanGrade
Parameters: int scores[], int SIZE
Return value: double
*******************************************************/
double getMeanGrade(int scores[], int SIZE)
{
    int sumScores = 0;
    int numScores = 0;
    double mean;

    for(int i=0; i < SIZE; i++)
    {
        if(scores[i] > 0)
        {
            sumScores = sumScores + (i * scores[i]);
            numScores = numScores + (1 * scores[i]);
        }
    }

    mean = sumScores / static_cast<double>(numScores);

    return mean;
}
