#include <stdio.h>
#include <stdlib.h>

int day2A( char* input )
{
    FILE* file;
    char c;
    char temp[10];
    char dir[6];
    int ans, depth, horiz, i;

    ans = 0;
    depth = 0;
    horiz = 0;
    i = 0;

    file = fopen(input, "r");

    while ((c = getc(file)) != EOF)
    {
        if (c == '\n')
        {
          //printf("%s\n", temp);
          if (temp[0] == 'u')
          {
            depth -= temp[i-1]-48;
          } else if (temp[0] == 'd') {
            depth += temp[i-1]-48;
          } else if (temp[0] == 'f') {
            horiz += temp[i-1]-48;
          }
          i = 0;
        } else {
          temp[i] = c;
          i++;
        }
    }

    fclose(file);

    //printf("%d\t%d\n", horiz, depth);

    ans = depth * horiz;

    return ans;
}

int day2B( char* input )
{
  FILE* file;
  char c;
  char temp[10];
  char dir[6];
  int ans, depth, horiz, aim, i;

  ans = 0;
  depth = 0;
  horiz = 0;
  i = 0;
  aim = 0;

  file = fopen(input, "r");

  while ((c = getc(file)) != EOF)
  {
      if (c == '\n')
      {
        printf("%s\n", temp);
        if (temp[0] == 'u')
        {
          aim -= temp[i-1]-48;
        } else if (temp[0] == 'd') {
          aim += temp[i-1]-48;
        } else if (temp[0] == 'f') {
          horiz += temp[i-1]-48;
          depth += (temp[i-1]-48) * aim;
        }
        i = 0;
      } else {
        temp[i] = c;
        i++;
      }
  }

  fclose(file);

  printf("%d\t%d\n", horiz, depth);

  ans = depth * horiz;

  return ans;
}

int main()
{
    int day2AnswerA;
    int day2AnswerB;

    day2AnswerA = day2A("input.txt");
    day2AnswerB = day2B("input.txt");

    printf("%d\t", day2AnswerA);
    printf("%d\n", day2AnswerB);

    return 0;
}
