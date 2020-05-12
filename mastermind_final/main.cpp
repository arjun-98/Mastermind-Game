#include <iostream>
#include <stdio.h>
#include "mastermind.h"

using namespace std;

/* Documentation

    General Algorithm: 1) Code breaker option
                            Generate a list of every possible 'code', randomly select one as solution.
                            Ask user for their guess. Give hints based on guess, display hints. repeat till user finds solution
                            or the number of guess exceeds a certain value.
                       2) Code maker option
                            Generate a list of every possible code. Randomly select one as the guess. Ask user to give hints.
                            Scan through the list, and check every possible code that yields the same hints that the user gave when compared
                            to our guess. These are all the potential solutions. Transfer all such codes to a new list.
                            Repeat the above process with the new shortened list until the solution is found.



*/

int main()
{
    mastermind m;

    int choice = m.menu();

    while(1) {
        switch(choice) {
            case 1  : m.codebreaker(); break;
            case 2  : m.codemaker(); break;
            case 3:   break;
            default:  printf("invalid choice\n");  break;

        }
         return 0;
    }

}
