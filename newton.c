#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x)
{
  return x + cos(x);
}

double d_f(double x)
{
  return 1 - sin(x);
}

int main(void){
  double x, del, eps = 0.00001;
  int n = 0, n_max ;

  printf("初期値を入力してください。\nx:");
  scanf("%lf", &x);
  printf("繰り返し回数を入力してください。\nm_max:");
  scanf("%d",&n_max);
  
  do{

    del = -f(x) / d_f(x);
    x = del;
    printf("%d\t:%.10f\n", n+1, x);
    n++;
  }while(fabs(del) > eps && n <= n_max);
  
  if(n = n_max){
   printf("失敗　解が見つかりませんでした。\n");
  }else{
  printf("解は %.10f\n試行回数は%d回です\n", x, n);
  } 

  return 0;
}
