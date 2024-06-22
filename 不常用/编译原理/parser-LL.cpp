#include <stdio.h>
#include <string.h>

char stack[20];                          // 定义堆栈，用于存储非终结符和终结符
char input[20];                          // 输入字符串
char VT[20] = {'a', 'd', 'b', 'e', '#'}; // 终结符集合
char VN[20] = {'S', 'H', 'M', 'A'};      // 非终结符集合

int ip = 0, top = 0, len; // 输入指针，堆栈顶指针，输入字符串长度

// 定义产生式结构体
typedef struct type
{
    char origin;   // 产生式左部
    char array[5]; // 产生式右部
    int length;    // 产生式右部长度
} type;

type s, h, h1, m, m1, a, a1; // 定义文法中的产生式

type C[10][10]; // 解析表

// 打印当前堆栈内容
void print_stack()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%c", stack[i]);
    printf("\t\t");
}

// 打印当前输入内容
void print_input()
{
    int i;
    for (i = 0; i < ip; i++)
        printf(" ");
    for (i = ip; i < len; i++)
        printf("%c", input[i]);
    printf("\t\t\t");
}

// LL(1)解析函数
void LL()
{
    int i;
    int row, col, step, flag;
    char sym, x;
    type production;

    flag = 0;
    ip = 0;
    step = 0;
    top = 0;
    sym = input[ip]; // 读入第一个输入符号
    stack[top] = '#';
    stack[++top] = 'S'; // 将起始符号推入堆栈

    printf("step\t\tstack \t\tinput \t\tproduction \n");
    while (1)
    {
        printf("%d", step++);
        printf("\t\t");
        print_stack();
        print_input();

        x = stack[top--]; // 弹出堆栈顶部符号

        for (i = 0; i <= 4; i++)
            if (x == VT[i])
            {
                flag = 1;
                break;
            }

        if (flag == 1)
        {
            if (x == sym)
            {
                if (x == '#')
                {
                    printf("acc!\n"); // 输入符号匹配完成，接受
                    return;
                }
                printf("%c match\n", sym);
                sym = input[++ip]; // 移动到下一个输入符号
                flag = 0;
            }
            else
            {
                printf("%c error!\n", sym); // 匹配错误，打印错误信息
                return;
            }
        }
        else
        {
            for (i = 0; i <= 3; i++)
                if (x == VN[i])
                {
                    row = i; // 在非终结符集合中找到对应的行
                    break;
                }
            for (i = 0; i <= 4; i++)
                if (sym == VT[i])
                {
                    col = i; // 在终结符集合中找到对应的列
                    break;
                }
            if (i == 5)
            {
                printf("error...illegal input!!\n"); // 非法输入
                return;
            }

            production = C[row][col]; // 根据解析表找到对应的产生式
            if (production.origin != 'N')
            { // 如果产生式不是空
                printf("%c->", production.origin);
                for (i = 0; i < production.length; i++)
                    printf("%c", production.array[i]);
                printf("\n");

                for (i = (production.length - 1); i >= 0; i--)
                    stack[++top] = production.array[i]; // 将产生式右部推入堆栈
            }
            else
            {
                printf("%c error!\n", x); // 产生式为空，打印错误信息
                return;
            }
        }
    }
}

int main()
{
    int i, j;
    char c;

    s.origin = 'S';
    strcpy(s.array, "aH");
    s.length = 2;
    h.origin = 'H';
    strcpy(h.array, "aMd");
    h.length = 3;
    h1.origin = 'H';
    strcpy(h1.array, "d");
    h1.length = 1;
    m.origin = 'M';
    strcpy(m.array, "Ab");
    m.length = 2;
    m1.origin = 'M';
    m1.length = 0;
    a.origin = 'A';
    strcpy(a.array, "aM");
    a.length = 2;
    a1.origin = 'A';
    strcpy(a1.array, "e");
    a1.length = 1;

    /*initialize parsing table*/
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5; j++)
            C[i][j].origin = 'N';

    C[0][0] = s;
    C[1][0] = h;
    C[1][1] = h1;
    C[2][0] = m;
    C[2][1] = m1;
    C[2][2] = m1;
    C[2][3] = m;
    C[3][0] = a;
    C[3][3] = a1;
    while (1)
    {
        printf("\ninput length<50,ending with'#'; '^#' to return!\n");
        len = 0;
        do
        {
            scanf("%c", &c);
            input[len++] = c;
        } while (c != '#');
        getchar();

        if (input[0] == '^' && input[1] == '#')
            return 0;

        LL();
    }
}