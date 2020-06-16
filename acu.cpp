#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include"matplotlibcpp.h"

namespace plt = matplotlibcpp;

int main(){
  FILE *f;
  FILE *w;
  char year[20];
  char month[20];
  char day[20];
  char weekday[20];
  char time[20];
  char coun[20];
  char word[20];
  double set_day[1000] = {};
  double set_num[1000] = {};

  int at = 0;
  //for judge
  int num = 0;
  int count = 0;
  char ten[20] = "before";

  f = fopen("/home/kengo/dict/accumulate.csv", "r");
  w = fopen("/home/kengo/dict/hist.csv", "w");

  while(1){
    at = fgetc(f);
    if (at == EOF) break;
    fscanf(f, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", year, month, day, weekday, time, coun, word);
    //printf("%s\n", day);
    
    //judge and accumulate
    if(strcmp(ten, "before") == 0){
      num++;
      strcpy(ten, day);
    }else if(strcmp(ten, day) == 0){
      num++;
    }else{
      fprintf(w, "%s %d\n", ten, num);
      //strcmp(set_day[count],ten);
      set_num[count] = num +1 ;
      set_day[count] = count;
      //printf("%f %f %d\n", set_day[count], set_num[count], num);
      num = 0;
      strcpy(ten, day);
      count++;
    }

  }

  
  fclose(f);
  fclose(w);

  //make graph
  plt::plot(set_day, set_num, "r--");
  plt::xlabel("day");
  plt::ylabel("word num");
  plt::show();

  return 0;
}

