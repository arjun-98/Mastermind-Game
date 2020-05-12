#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

using namespace std;

mastermind::mastermind()
{

}

void mastermind::give_hints(int* guess) {
    for(int i = 0; i < 4; i++) {
         hints[i] = 0;
    }
    for(int i = 0; i < 4; i++) {
        if(temp_solution[i] == guess[i]) hints[i] = 2;
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(temp_solution[i] == guess[j]) {
                if(hints[j] == 0 && hints[i] != 2) {
                    hints[j] = 1;
                    break;
                }
            }
        }
    }

    int temp_hints[4] = {0, 0, 0, 0};
    int n = 0;
    for(int i = 0; i < 4; i++) {
        if(hints[i] == 2) {
            temp_hints[n] = 2;
            n++;
        }
    }
    for(int i = 0; i < 4; i++) {
        if(hints[i] == 1) {
            temp_hints[n] = 1;
            n++;
        }
    }
    for(int i = 0; i < 4; i++) {
        hints[i] = temp_hints[i];
    }
}

void mastermind::generate() {

    int counter = 0;

    for(int i = 1; i<=6; i++){
             for(int j = 1; j<=6; j++){
                 for(int k = 1; k<=6; k++){
                     for(int l = 1; l<=6; l++){
                            list[counter][0] = i;
                            list[counter][1] = j;
                            list[counter][2] = k;
                            list[counter][3] = l;

                            temp_list[counter][0] = 0;
                            temp_list[counter][1] = 0;
                            temp_list[counter][2] = 0;
                            temp_list[counter][3] = 0;

                            counter +=1;
                     }
                 }
             }

    }

}

int mastermind::menu() {
    int choice;

      while(1) {
        printf("\n        MAIN MENU") ;
        printf("\n     1. Code Breaker ");
        printf("\n     2. Code Maker");
        printf("\n     3. Quit");
        printf("\n\n      Enter your choice (1-3): ");
        cin >> choice;

        if ( (choice  >= 1) && ( choice <= 3) )
            break;

      }

    return choice;
}

void mastermind::codebreaker() {
    generate();
    int guess[4];
    int counter = 1;

    srand(time(NULL));
    int n = rand()%1296 ;

    for (int i = 0; i < 4; i++) {
        temp_solution[i] = list[n][i];
        //cout << temp_solution[i];
    }
    cout<<endl;

    cout << "Enter guess: " << endl;

    while(1) {
            cout<<endl;
        cout<<counter<<") ";
        int result = scanf("%d%d%d%d", &guess[0], &guess[1], &guess[2], &guess[3]);
        int check = 0;

        for(int i = 0; i < 4; i++) {
            if(guess[i] < 1 || guess[i] > 6) {
                cout << "invalid input" << endl;
                check = 1;
            }
        }
        if (check == 1) {
            continue;
        }

        give_hints(guess);
        cout<<"hint: ";
        int wcount = 0;
        for(int i = 0; i < 4; i++) {

            cout << hints[i];
            if(hints[i] == 2 ) wcount++;
            if (wcount == 4){
                cout<<" You Win";
                return 0;
            }

        }

        counter++;
        if(counter == 11) {
            cout<<" You lose";
            break;
        }

    }
}

void mastermind::codemaker() {
    int counter = 0;
    generate();
    int guess[4] = {1, 2, 3, 4};



     for(int i = 0; i < 4; i++) {
        cout << guess[i];
        }


    while(1){

        cout<<" ";
        cout << "Enter hint: ";
        int result = scanf("%d%d%d%d", &hints[0], &hints[1], &hints[2], &hints[3]);

        int wcount = 0;
        for(int i = 0; i < 4; i++) {
            final_hints[i] = hints[i];
            if(hints[i] == 2 ) wcount++;
            if (wcount == 4){
                cout<<" Code broken";
                return;
            }
        }

        cout<<endl;

        for(int i = 0; i < 1296; i++) {
            if(list[i][0] == 0) break;
            for(int j = 0; j < 4; j++) {
                temp_solution[j] = list[i][j];
            }
            give_hints(guess);
            for(int k = 0; k < 4; k++) {
                if (final_hints[k] != hints[k]) break;

                if (k == 3) {
                    for(int l = 0; l < 4; l++) {
                        temp_list[counter][l] = list[i][l];


                    }
                    counter++;
                }
            }
        }
        for(int i = 0; i < 1296; i++) {
            for(int j = 0; j < 4; j++) {
                list[i][j] = temp_list[i][j];
                temp_list[i][j] = 0;

            }
        }
        for(int i = 0; i < 4; i++) {
            guess[i] = list[0][i];
            cout<<guess[i];

        }
        counter = 0;

        for(int i = 0; i < 4; i++) {
            temp_solution[i] = solution[i];
        }
    }


}





