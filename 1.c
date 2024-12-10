// 2024年11月1日17:22:54
#include <stdio.h>
#include <math.h>

double f(double x1)
{
    double y1;
    y1 = x1 * x1 * x1 - 3 * x1 + 6 * x1 - 1;
    return y1;
}

int main(void)
{
    double x1, x2, x0, f1, f2;
    printf("请输入x1,x2,使在(x1,x2)区间上\n");
    scanf("%lf,%lf", &x1, &x2);
    f1 = f(x1);
    f2 = f(x2);
    x0 = (x1 + x2) / 2;
    if (f(x1) * f(x2) > 0)
    {
        printf("不在此区间内\n");
    }
    else
    {
        int i = 1;
        do
        {
            if (f(x0) * f1 < 0)
            {
                x2 = x0;
                f2 = f(x0);
            }
            if (f(x0) * f2 < 0)
            {
                x1 = x0;
                f1 = f(x0);
            }
            x0 = (x1 + x2) / 2;
            i = i + 1;
            printf("第%次", i);
            printf("x1 = %lf x2 = %lf 中点x0 = %lf f(x1) = %lf f(x2) = %lf f(x0) = %lf\n", x1, x2, x0, f(x1), f(x2), f(x0));
        } while (fabs(f(x0)) >= 1e-3);
        printf("f(x)的解为%.3lf", x0);
    }
    return 0;
}