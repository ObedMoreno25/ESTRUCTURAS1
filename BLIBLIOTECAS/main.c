/* isdigit example
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main ()
{
  char str[]="1776ad";
  int year;
  if (isdigit(str[0]))
  {
    year = atoi (str);
    printf ("The year that followed %d was %d.\n",year,year+1);
  }
  return 0;
}
 isprint example
#include <stdio.h>
#include <ctype.h>
int main ()
{
  int i=0;
  char str[]="first line \n second line \n";
  while (isprint(str[i]))
  {
    putchar (str[i]);
    i++;
  }
  return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
    int i = 8, j = 5, k;
    float x = 2.5, y = -0.3, z;
    char a, b, c = 'c', d = 'd';
    int r;
    float f;
    char e;

    r = abs(i -2 *j);
    printf("1-. %d\n", r );
    f = fabs(x + y);
   printf("2.-%f\n", f);
    e = isprint(c);
    printf("3.-%c\n", e);
    e = isdigit(c);
    printf("4.-%c\n", e);
    e = toupper(d);
    printf("5.-%c\n", e);
    f =floor(x + y);
    printf("6.-%f\n", f);
    e =islower(c);
    printf("7.-%c\n", e);
    e =isupper(d);
    printf("8.-%c\n", e);
    r =exp (i);
   printf("9.-%d\n", r);
    r =log (j);
    printf("10.-%d\n", r);
    f =sqrt (x * x + y * y);
    printf("11.-%d\n", f);
    f =fmod(x , y);
    printf("12.-%d", f);
    f =pow(x - y, 3.0);
    printf("13.-%f\n", f);
    f = sin(x - y);
    printf("14.-%f\n", f);
    e =strlen("Hola\0");
    printf("15.-%c\n", e);
    return 0;
}
