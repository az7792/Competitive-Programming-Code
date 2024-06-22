/*
S::=bA
A::=BaA
A::=     empty production
B::=ab

input:baba#
*/

#include <stdio.h>

#define ERROR -1
char sym, a[50];
int ip = 0;

int S();
int M();
int B();

void getNextSym()
{
    sym = a[++ip];
    printf("  sym=%c\n", sym);
}

//================================================
int main()
{
    int ret;
    while (1)
    {
        printf("\ninput length < 50,ending with'#'; '^#' to return!\n");
        ip = 0;
        do
        {
            scanf("%c", &sym);
            a[ip++] = sym;
        } while (sym != '#');

        if (a[0] == '^' && a[1] == '#')
            return 0;

        printf("......begin......\n");
        ip = -1;
        getNextSym();
        ret = S();
        if (ret != ERROR && sym == '#')
            printf("......accept!\n");
        else
            printf("......error!\n");
        getchar();
    }
}

//================================================
int S()
{
    if (sym == 'd' || sym == 'b' || sym == 'e')
    {
        printf("S->MBf\n");
        if (M() == ERROR)
            return ERROR;

        if (B() == ERROR)
            return ERROR;

        if (sym != 'f')
            return ERROR;

        getNextSym();
    }
    else
        return ERROR;

    return 0;
}

//================================================
int M()
{
    if (sym == 'd' || sym == 'b')
    {
        printf("M->BbS\n");
        if (B() == ERROR)
            return ERROR;

        if (sym != 'b')
            return ERROR;
        getNextSym();

        if (S() == ERROR)
            return ERROR;
    }
    else if (sym == 'e')
    {
        printf("M->e\n");
        getNextSym();
    }
    else
        return ERROR;

    return 0;
}

//================================================
int B()
{
    if (sym == 'd')
    {
        printf("B->dMg\n");
        getNextSym();
        if (M() == ERROR)
            return ERROR;
        if (sym != 'g')
            return ERROR;
        getNextSym();
    }
    else if (sym == 'f' || sym == 'b')
    {
        printf("B-> \n");
    }
    else
        return ERROR;

    return 0;
}
