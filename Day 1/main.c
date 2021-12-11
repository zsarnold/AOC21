#include <stdio.h>
#include <stdlib.h>

int day1A( char* input )
{
    FILE* file;
    char c;
    char temp[5];
    int ans, prev, cur, i;

    ans = 0;
    i = 0;

    file = fopen(input, "r");

    while ((c = getc(file)) != EOF)
    {
        if (c == '\n')
        {
          cur = atoi(temp);
          i = 0;
        } else {
          temp[i] = c;
          i++;
        }

        if (prev < cur)
        {
            ans++;
        }

        prev = cur;
    }

    fclose(file);

    return ans-1;
}

int day1B( char* input )
{
    FILE* file;
    char c;
    char temp[5];
    int ans, prev, cur, i, j, k;
    int num[3];

    ans = 0;
    cur = 0;
    i = 0;
    j = 3;
    k = 0;
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;

    file = fopen(input, "r");

    while ((c = getc(file)) != EOF)
    {
      if (c == '\n')
      {
        if (k == 0)
        {
          num[2] = 0;
          num[1] = 0;
          num[0] = atoi(temp);
        } else if ( k == 1 ) {
          num[2] = num[1];
          num[1] = num[0];
          num[0] = atoi(temp);
        } else {
          num[2] = num[1];
          num[1] = num[0];
          num[0] = atoi(temp);
          cur = num[0] + num[1] + num[2];
        }
        i = 0;
        k++;
      } else {
        temp[i] = c;
        i++;
      }
      if (cur > prev)
      {
        ans++;
      }
      prev = cur;
    }

    fclose(file);

    return ans-1;
}




int main()
{
    int day1AnswerA;
    int day1AnswerB;

    day1AnswerA = day1A("input.txt");
    day1AnswerB = day1B("input.txt");

    printf("%d\t", day1AnswerA);
    printf("%d\n", day1AnswerB);

    return 0;
}
