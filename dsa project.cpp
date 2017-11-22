//gomtesh jain 16csu131 dsa project on kmp 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void computeLPSArray(char *pat, int M, int *l);
 
void kmp(char *pat, char *txt)
{
  int M = strlen(pat);
  int N = strlen(txt);
  int *l = (int *)malloc(sizeof(int) * (M + 1));
  computeLPSArray(pat, M, l);
 
  int i = 0; 
  int j = 0; 

  while (i < N)
  {
    if (pat[j] == txt[i])
    {
      i++;
      j++;
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = l[j];
      }
    }
    else 
    {
    
      j = l[j];
      if (j < 0)
      {
        i++;
        j++;
    
      }
    }
  }
  free(l); 
}
 
void computeLPSArray(char *pat, int M, int *l)
{
  l[0] = -1;
  int i = 1;
  int j = 0; 
  while (i < M)
  {
    if (pat[j] == pat[i])
    {
      l[i] = l[j];
      i++;
      j++;
    }
    else 
    {
      l[i] = j;
      j = l[j];
      while (j >= 0 && pat[j] != pat[i])
      {
        j = l[j];
      }
      i++;
      j++;
    }
  }
  l[i] = j;
}
int main()
{
	char a[50],b[20];
	printf("enter a string ");
	gets(a);
  char *txt = a;
  	printf("enter a string to be searched ");
	gets(b);  
  char *pat = b;
  kmp(pat, txt);
  return 0;
}
/*
reference
https://en.wikibooks.org/wiki/Algorithm_Implementation/String_searching/Knuth-Morris-Pratt_pattern_matcher
licence
Attribution-ShareAlike 3.0 Unported (CC BY-SA 3.0)
*/
