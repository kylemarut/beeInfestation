//Programmer: Kyle Marut
//Date: 11-1-24
//File: hw6.cpp
//Assignment: homework hw6
//Purpose: this file contains the main function of the prgram meant to simulate insect infestation

#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

int main()
{
    //intialization of variables
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int x, y;
    char arr[10][10];
    
    //filling arr with terms from input.txt
    for(int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            fin>>arr[i][k];
        }
    }
    
    //performs the bee drop on coordinates from input.txt
    while(fin>>x)
    {
        fin>>y;
        drop(arr,x,y);
    }
    
    //outputs final arr to output.txt
    for(int i = 0; i < 10; i++)
    {
        for (int k = 0; k < 10; k++)
        {
            fout<<arr[i][k];
        }
        fout<<endl;
    }
    
    return 0;
}