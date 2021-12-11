#include <stdio.h>
#include <stdlib.h>

int day3A( char* input )
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

int day3B( char* input )
{
  FILE* file;
  char c;
  char temp[15];
  int i, j, k;

  i = 0;
  j = 0;
  k = 0;

  file = fopen(input, "r");

  while ((c = getc(file)) != EOF)
  {
      if (c == '\n')
      {
        j = i;
        i = 0;
        k++;
      } else {
        temp[i] = c;
        i++;
      }
  }
  fclose(file);

  printf("%d\t%d\n",k,j);

  //int arr[k][j];

  /*
  while ((c = getc(file)) != EOF)
  {
      if (c == '\n')
      {

      } else {
        arr[i] = c;
        i++;
      }
  }
  */

  return 0;
}

int main()
{
    int day3AnswerA;
    int day3AnswerB;

    day3AnswerA = day3A("input.txt");
    day3AnswerB = day3B("input.txt");

    printf("%d\t", day3AnswerA);
    printf("%d\n", day3AnswerB);

    return 0;
}
