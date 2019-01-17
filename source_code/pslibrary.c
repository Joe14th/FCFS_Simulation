#include <string.h>
#include <stdio.h>
#include "pslibrary.h"

void part0(char *s1, char *s2){
   strcpy(s1,"RRwwwwwRRRRRRRRR");
   strcpy(s2,"rrRRRRwwwwwwwwrrRRRRRRR");
}

void display(char *heading, char *s1, char *s2){
   fprintf(stdout, "\n");
   fprintf(stdout, "%s" , heading);
   fprintf(stdout, "%s\n", s1);
   fprintf(stdout, "%s\n", s2);
   int i;
   int r1=0;
   int r2=0;
   int R1=0;
   int R2=0;
   int str1 = strlen(s1);
   int str2 = strlen(s2);
   float size = 0;
   for(i=0; i < str1; i++){
      if(s1[i] == 'r')
         r1++;
      else if(s1[i] == 'R')
         R1++;
   }
   for(i=0; i < str2; i++){
      if(s2[i] == 'r')
         r2++;
      else if(s2[i] == 'R')
         R2++;
   }
   size = (str1>str2) ? (float)(R1+R2)/str1 : (float)(R1+R2)/str2;
   fprintf(stdout, "%d %d %.1f %.5f\n", r1, r2, (float)(r1+r2)/2, size);
}

void fcfsa(char *s1, char *s2, int x1, int y1, int z1, int  x2, int y2, int z2){
   int sum = 0;
   memset(s1, 'R', x1);
   memset(s1+x1, 'w', y1);

   memset(s2, 'r', x1);
   memset(s2+x1, 'R', x2);

   sum = ((x1+x2)-(x1+y1)<0)? 0 : (x1+x2)-(x1+y1);
   memset(s1+x1+y1, 'r', sum);
   memset(s1+x1+y1+sum, 'R', z1);

   memset(s2+x1+x2, 'w', y2);

   sum = (x1+y1+sum+z1-(x1+x2+y2)<0)? 0 : x1+y1+sum+z1-(x1+x2+y2);
   memset(s2+x1+x2+y2, 'r', sum);
   memset(s2+x1+x2+y2+sum, 'R', z2);
}
