#include <stdio.h>
#include <stdlib.h>

int day4A( char* input )
{
    FILE* file;
    char c;
    char temp[15];
    int val[15];
    int bin[15];
    int epsilon, gamma, i, j, k, width, ans;

    gamma = 0;
    epsilon = 0;
    i = 0;
    k = 0;
    width = 0;
    ans = 0;

    for (j = 0; j < 15; j++)
    {
      val[j] = 0;
    }

    file = fopen(input, "r");

    while ((c = getc(file)) != EOF)
    {
        if (c == '\n')
        {
          for ( j = 0; j < i; j++)
          {
            val[j] += temp[j]-48;
          }
          width = i;
          i = 0;
          k++;
        } else {
          temp[i] = c;
          i++;
        }
    }

    for (j = 0; j < 15; j++)
    {
      if (val[j] == 0) {
        break;
      } else if (val[j] > k/2) {
        gamma = gamma << 1;
        gamma += 0b1;
      } else {
        gamma = gamma << 1;
      }
    }

    for (j = 0; j < 15; j++)
    {
      //printf("%d\t", val[j]);
      if (val[j] == 0) {
        break;
      } else if (val[j] > k/2 ) {
        epsilon = epsilon << 1;
      } else {
        epsilon = epsilon << 1;
        epsilon += 0b1;
      }
    }

    //printf("Gam:%d\tEpi:%d\n", gamma, epsilon);

    ans = gamma * epsilon;
    fclose(file);

    return ans;
}

int day4B( char* input )
{
  return 0;
}

int main()
{
    int day4AnswerA;
    int day4AnswerB;

    day4AnswerA = day4A("input.txt");
    day4AnswerB = day4B("input.txt");

    printf("%d\t", day4AnswerA);
    printf("%d\n", day4AnswerB);

    return 0;
}
