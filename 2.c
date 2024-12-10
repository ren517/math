// 2024年11月1日17:22:10
#include <stdio.h>
#include <math.h>

double f(double x1)
{
    double y1;
    y1 = x1 * x1 * x1 * x1 * x1 + 5 * x1 - 1;
    return y1;
}

double f_derivative(double x1)
{
    // 求函数f的导数
    return 5 * x1 * x1 * x1 * x1 + 5;
}

double f_twoderivative(double x1)
{
    return 20 * x1 * x1 * x1;
}

int main(void)
{
    double x1, x0, x3;
    printf("请输入(x1,x2)\n");
    scanf("%lf,%lf", &x0, &x3);
    printf("x1的二阶导是%lf,x2的二阶导是%lf", f_twoderivative(x0), f_twoderivative(x3));
    printf("请根据二阶导数判断输入x0\n");
    scanf("%lf", &x0);
    int i = 1;
    double temp;
    do
    {
        x1 = x0 - (f(x0) / f_derivative(x0));
        temp = x0;
        x0 = x1;
        i = i + 1;
        printf("第%次", i);
        printf("x%d = %lf\n", i, x1);
    } while (fabs(x1 - temp) >= 1e-6);
    printf("f(x)的解为%.2lf", x1);
    return 0;
}
