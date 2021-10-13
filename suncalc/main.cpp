#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
#include <time.h>
#include "SunCalc.h"

void test1(void);

int main(void)
{
    while (1)
    {
        int num = 0;
        printf("test number? (1-3) > ");
        int ret = scanf("%d", &num);
        if (ret != 1){
            ret = scanf("%*s");
            continue;
        }
        if (num < 1 || num > 3) continue;
        switch (num) {
            case 1: test1(); break;
        }
        printf("\n");
    }
}

// テストプログラム
void test1(void)
{
    SunCalc sun;
    int year, month, day, hour, min, sec;
    double longit, latit;
    
    // UTC日時
    year = 2021; month = 10; day = 4;
    hour = 12; min = 0; sec = 0;
    // 現在位置
    longit = 135; latit = 34;
    
    sun.setDate(year, month, day, hour, min, sec);
    sun.setLocation(latit, longit);
    sun.calc();

    printf("\nTEST 1\n");
    printf("Date = %d/%02d/%02d\n", year, month, day);
    printf("Time = %02d:%02d:%02d \n", hour, min, sec);
    printf("(lt, lg) = (%.1f, %.1f)\n", latit, longit);
    printf("J2000 days = %.2f\n", sun.d);
    
    DegMinSec lambda = RAD2DMS(sun.lambda);
    printf("Lambda = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.lambda), lambda.deg, lambda.min, lambda.sec);
    
    DegMinSec delta = RAD2DMS(sun.delta);
    printf("Delta = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.delta), delta.deg, delta.min, delta.sec);
    
    HourMinSec alpha = RAD2HMS(sun.alpha);
    printf("Alpha = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.alpha), alpha.hour, alpha.min, alpha.sec);
    
    HourMinSec equation = RAD2HMS(sun.equation);
    printf("equation = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.equation), equation.hour, equation.min, equation.sec);

    HourMinSec t_UTC = RAD2HMS(sun.t_UTC);
    printf("UTC  = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.t_UTC), t_UTC.hour, t_UTC.min, t_UTC.sec);

    HourMinSec t_LMT = RAD2HMS(sun.t_LMT);
    printf("LMT  = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.t_LMT), t_LMT.hour, t_LMT.min, t_LMT.sec);

    HourMinSec t_LTST = RAD2HMS(sun.t_LTST);
    printf("LTST = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.t_LTST), t_LTST.hour, t_LTST.min, t_LTST.sec);

    HourMinSec t_LST = RAD2HMS(sun.t_LST);
    printf("LST  = %.3f (%d:%02d:%05.2f)\n",
        RAD2DEG(sun.t_LST), t_LST.hour, t_LST.min, t_LST.sec);
}
