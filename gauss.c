#include <stdio.h>
#include <math.h>

double get_x1(double x2, double x3)
{
       return((10.0 - x2 - x3) / 5.0) ;
}

double get_x2(double x1, double x3)
{
       return((12.0 - x1 - x3) / 4.0) ;
}

double get_x3(double x1, double x2)
{
       return((13.0 - 2.0 * x1 - x2) / 3.0) ;
}


int main(void)
{
    double x1, x2, x3;
    double b_x1, b_x2, b_x3;
    int i;
    int count = 0;

    x1 = x2 = x3 = 1.0;   //初期値

    for(i=0; i<20; i++)
    {
       
       b_x1 = x1;
       b_x2 = x2;
       b_x3 = x3;
       x1 =get_x1(x2, x3);
       x2 =get_x2(x1, x3);
       x3 =get_x3(x1, x2);

       printf("[i=%02d], x1 = %.10f, x2 = %.10f, x3 = %.10f\n", i+1, x1, x2, x3);

       if(fabs(x1-b_x1)<0.0000000001 && fabs(x2-b_x2)<0.0000000001 && fabs(x3-b_x3)<0.0000000001){   //前の値と比較 収束条件
          printf("収束しました。\n");
            count++;
            if(count == 3){   //3回収束したら出力されないようにする。
              break;
            }   
       }
    }
return 0;
}
