

//STRING TO NUM

int main ()
{
  char sentence []="Rudolph is 12 years old";
  char str [20];
  int i;

  sscanf (sentence,"%s %*s %d",str,&i);
  printf ("%s -> %d\n",str,i);
  
  return 0;
}



//NUM TO STRING

#include <stdio.h>
#include <stdbool.h>



int main()
{

char word[30];
int n;
scanf("%d", &n);
sprintf(word,"%d", n);
printf(word);



   
return 0;
}