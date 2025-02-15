//Programmer: Kyle Marut
//Date: 11-4-24
//File: functions.cpp
//Assignment: homework 6
//Purpose: the file contains all of the function definitions

#include "functions.h"

//Description: "upgrades" insect type when mutations occur
//Pre: c will only ever be 'B', 'W', 'T', or '_' for the different types of insects
//Post: values in arr will be changed
void upgrade(char arr [][10],int a, int b, char c = '_')
{
    if (a>=0 && b>=0 && a<10 && b < 10)
    {
        if (c == 'T')
        {
            arr[a][b] = 'T';
        }
        else if (c == 'W' && arr[a][b] != 'T')
        {
            if (arr[a][b] == 'W')
            {
                arr[a][b] = 'T';
            }
            else
            {
                arr[a][b] = 'W';
            }
        }
        else if (arr[a][b] != 'W' && arr[a][b] != 'T')
        {
            if (arr[a][b] == 'B')
            {
                arr[a][b] = 'W';
            }
            else
            {
                arr[a][b] = 'B';
            }
        }
    }
}

//Description: used when outbreaks occur
//Pre: none
//Post: upgrade funciton is called to all values surrounding arr[a][b]
void explode(char arr [][10],int a, int b)
{
    for(int i = a-1; i <= a+1; i++)
    {
        for(int k = b-1; k <= b+1; k++)
        {
            if(a!=i || b!=k)
            {
                upgrade(arr, i,k, arr[a][b]);
            }
        }
    }
}

//Description: used to drop insects into a given country
//Pre: none
//Post: If the country at arr[a][b] does not have any insects, it will become infested with bees, otherwise the explode function will be called.
void drop(char arr [][10],int a, int b)
{
    if (a>=0 && b>=0 && a<10 && b < 10)
    {
        if (arr[a][b] == '_')
        {
            arr[a][b] = 'B';
        }
        else
        {
            explode(arr,a,b);
        }
    }
}

