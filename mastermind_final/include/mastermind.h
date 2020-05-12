#ifndef MASTERMIND_H
#define MASTERMIND_H


class mastermind
{
    public:
        int hints[4] = {0, 0, 0, 0};
        int final_hints[4] = {0, 0, 0, 0};
        int solution[4] = {4, 3, 2, 1};
        int temp_solution[4] =  {4, 3, 2, 1};
        int list[1296][4];
        int temp_list[1296][4];

        mastermind();
        void give_hints(int* guess);
        int menu();
        void codebreaker();
        void codemaker();
        void generate();

    private:
};

#endif // MASTERMIND_H

