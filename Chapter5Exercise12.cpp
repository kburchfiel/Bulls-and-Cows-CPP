//AMDG
//Bulls and Cows game, with non-unique integers permitted. Completed as part of my independent study of Bjarne Stroustrup's Programming: Practices and Principles.
//Special thanks to Benjamin Lindley for suggesting the use of default_random_engine: https://stackoverflow.com/questions/31361968/why-isnt-srand-seed-changing-results
//Kenneth Burchfiel, 4/4/2020 (with help from answers pages on Stack Overflow and other sites)
#include "../std_lib_facilities.h"
#include <iostream>
#include <random>
using namespace std;


int main()

{
int g0;
int g1;
int g2;
int g3;
int bullcount = 0;
int cowcount = 0;
int trycount = 0;
int i = 0;
vector <int> mystnums;
//Using time_0 to seed default_random_engine (instead of asking the user to enter a seed value):
default_random_engine randomizer(time(0));
uniform_int_distribution<int> dist(0, 9);
//int discard is added in because when using default_random_engine and uniform_int_distribution, I always appear to get the same first integer, followed by a range of integers afterwards. So I 'discard' the first integer that is produced by mapping it to "discard" and then keep the other four integers.
int discard = dist(randomizer);
//Now that the first number is discarded, we can use the subsequent numbers. Note that dist(randomizer) will produce different results when it is called multiple times.
//Here is the first number we'll select for our set of four numbers:
mystnums.push_back(dist(randomizer));
//The following three while statements represent a way to make sure that the four numbers are unique (part of the criteria for Bulls and Cows, or at least Bjarne's version of it.)
//The statements make sure that the number found by dist(randomzier) isn't the same as a number that already exists in the vector.
//I believe I would get an out of range error if I asked the while statement to look at four vector entries at once, since the vector starts out with 0 entries . . . 
//And if I launched the vector with 4 entries that were all 0, I don't believe the first number would ever be 0 (since the while statement wouldn't add in a number 0 if the pre-existing number was 0.)
//There's probably a much better way to make sure each number is unique, but since there are only four numbers it's still manageable.
while (i < 1)
//The integer i will always equal 0 within this code. i++ could be used, but then i would have to be reset to 0 each time, so instead a break statement is used to exit the loop.
{int x = dist(randomizer);
if (x != mystnums[0])
{mystnums.push_back(x);
break;}
}
while (i < 1)
{int x = dist(randomizer);
if (x != mystnums[0] && x != mystnums[1])
{mystnums.push_back(x);
break;}
}

while (i < 1)
{int x = dist(randomizer);
if (x != mystnums[0] && x != mystnums[1] && x != mystnums[2])
{mystnums.push_back(x);
break;}
}

cout << "Please enter four integers, separated by a space or enter. Your goal is to guess (in the correct order) four unique numbers stored in the program.\n";
cout << "If you guess a number correctly and it's in the right order, you will get one \"Bull.\" If you guess a number correctly but it's not in the right order, you will get one \"Cow.\"\n"; 
cout << "Note that if you enter the same integer multiple times within the same 4-number set, the \"cow\" count may become artificially inflated. However, keep in mind that a given number will appear only once in the 4-number set.\n";
cout << "You can now enter your four numbers.\n" ;

while (cin)
{
    
    if (cin >> g0 >> g1 >> g2 >> g3)
    {
        if (g0 == mystnums[0])
        {bullcount++;}
        else if (g0 == mystnums[1] || g0 == mystnums[2] || g0 == mystnums[3])
        {cowcount++;}

if (g1 == mystnums[1])
        {bullcount++;}
        else if (g1 == mystnums[0] || g1 == mystnums[2] || g1 == mystnums[3])
        {cowcount++;}

        if (g2 == mystnums[2])
        {bullcount++;}
        else if (g2 == mystnums[0] || g2 == mystnums[1] || g2 == mystnums[3])
        {cowcount++;}

        if (g3 == mystnums[3])
        {bullcount++;}
        else if (g3 == mystnums[0] || g3 == mystnums[1] || g3 == mystnums[2])
        {cowcount++;}

            trycount++;

    if (bullcount == 4)
{

cowcount = 0;
bullcount = 0;

mystnums.clear();

std::default_random_engine randomizer(time(0));
std::uniform_int_distribution<> dist(0, 9);
int discard = dist(randomizer);
mystnums.push_back(dist(randomizer));
while (i < 1)
{int x = dist(randomizer);
if (x != mystnums[0])
{mystnums.push_back(x);
break;}
}
while (i < 1)
{int x = dist(randomizer);
if (x != mystnums[0] && x != mystnums[1])
{mystnums.push_back(x);
break;}
}

while (i < 1)
{int x = dist(randomizer);
if (x != mystnums[0] && x != mystnums[1] && x != mystnums[2])
{mystnums.push_back(x);
break;}
}


cout << "Congrats, you've won! Your number of tries was " << trycount << " tries. You can now play again with a different set of numbers. Try entering your four numbers now:\n";
trycount = 0;
    }


else {
    
    cout << "You have " << bullcount << " bull(s)" << " and " << cowcount << " cow(s). Your number of tries so far is " << trycount << ". Please enter your next set of guesses:\n";
cowcount = 0;
bullcount = 0;
}

    }
//Code that allows users to try again if they did not correctly enter an integer:
else {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Sorry, you did not enter four integers. Please try again.\n";
continue;}

}

}