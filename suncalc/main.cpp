#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
// テストプログラム
#include <stdlib.h> 
#include <time.h>
#include "SunCalc.h"

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

int main(void)
{
    while (1)
    {
        int num = 0;
        printf("test number? (1-5) > ");
        int ret = scanf("%d", &num);
        if (ret != 1){
            char buff[2];
            ret = scanf("%1s", buff);
            if (buff[0] == 'q') return 0;
            continue;
        }
        if (num < 1 || num > 5) continue;
        switch (num) {
            case 1: test1(); break;
            case 2: test2(); break;
            case 3: test3(); break;
            case 4: test4(); break;
            case 5: test5(); break;
        }
        printf("\n");
    }
}


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
    
    DegMinSec L = RAD2DMS(sun.L);
    printf("Mean L = %7.3f (%s)\n",
        RAD2DEG(sun.L), DMS2STR(L));
    DegMinSec lambda = RAD2DMS(sun.lambda);
    printf("Lambda = %7.3f (%s)\n",
        RAD2DEG(sun.lambda), DMS2STR(lambda));
    DegMinSec delta = RAD2DMS(sun.delta);
    printf("Delta  = %7.3f (%s)\n",
        RAD2DEG(sun.delta), DMS2STR(delta));
    HourMinSec alpha = RAD2HMS(sun.alpha);
    printf("Alpha  = %7.3f (%s)\n",
        RAD2DEG(sun.alpha), HMS2STR(alpha));
    HourMinSec equation = RAD2HMS(sun.equation);
    printf("EoT    = %7.3f (%s)\n",
        RAD2DEG(sun.equation), HMS2STR(equation));
    HourMinSec t_UTC = RAD2HMS(sun.t_UTC);
    printf("UTC    = %7.3f (%s)\n",
        RAD2DEG(sun.t_UTC), HMS2STR(t_UTC));
    HourMinSec t_LMT = RAD2HMS(sun.t_LMT);
    printf("LMT    = %7.3f (%s)\n",
        RAD2DEG(sun.t_LMT), HMS2STR(t_LMT));
    HourMinSec t_LTST = RAD2HMS(sun.t_LTST);
    printf("LTST   = %7.3f (%s)\n",
        RAD2DEG(sun.t_LTST), HMS2STR(t_LTST));
    HourMinSec t_LST = RAD2HMS(sun.t_LST);
    printf("LST    = %7.3f (%s)\n",
        RAD2DEG(sun.t_LST), HMS2STR(t_LST));
}

void test2(void)
{
    SunCalc sun;
    int year, month, day, hour, min, sec;
    double longit, latit;

    // UTC日時
    year = 2020; month = 12; day = 23;
    hour = 12; min = 0; sec = 0;
    // 現在位置
    longit = 135; latit = 34;

    printf("\nTEST 2\n");
    printf("yyyy/mm/dd,  L,       Lambda,  Delta,   Alpha, ,                  EoT\n");
    for (int i = 0; i < 24; i++)
    {
        sun.setDate(year, month, day, hour, min, sec);
        sun.setLocation(latit, longit);
        sun.calc();

        printf("%d/%02d/%02d,  ", year, month, day);
        printf("%7.3f, ", RAD2DEG(sun.L));
        printf("%7.3f, ", RAD2DEG(sun.lambda));
        printf("%7.3f, ", RAD2DEG(sun.delta));
        HourMinSec alpha = RAD2HMS(sun.alpha);
        printf("%7.3f, (%s), ", RAD2DEG(sun.alpha), HMS2STR(alpha));
        HourMinSec equation = RAD2HMS(sun.equation);
        printf("%7.3f, (%s)\n", RAD2DEG(sun.equation), HMS2STR(equation));

        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void test3(void)
{
    SunCalc sun;
    int year, month, day, hour, min, sec;
    double longit, latit;

    // UTC日時
    year = 2021; month = 10; day = 4;
    hour = 0; min = 0; sec = 0;
    // 現在位置
    longit = 135; latit = 34;

    printf("\nTEST 3\n");
    printf("yyyy/mm/dd,  L,       Lambda,  Delta,   Alpha, ,                  EoT\n");
    for (int i = 0; i < 25; i++)
    {
        sun.setDate(year, month, day, hour, min, sec);
        sun.setLocation(latit, longit);
        sun.calc();

        printf("%d/%02d/%02d,  ", year, month, day);
        printf("%7.3f, ", RAD2DEG(sun.L));
        printf("%7.3f, ", RAD2DEG(sun.lambda));
        printf("%7.3f, ", RAD2DEG(sun.delta));
        HourMinSec alpha = RAD2HMS(sun.alpha);
        printf("%7.3f, (%s), ", RAD2DEG(sun.alpha), HMS2STR(alpha));
        HourMinSec equation = RAD2HMS(sun.equation);
        printf("%7.3f, (%s)\n", RAD2DEG(sun.equation), HMS2STR(equation));

        hour += 2;
        if (hour >= 24) {
            hour = 0;
            day++;
        }
    }
}

void test4(void)
{
    SunCalc sun;
    int year, month, day, hour, min, sec;
    double longit, latit;

    // UTC日時
    year = 2020; month = 12; day = 23;
    hour = 12; min = 0; sec = 0;
    // 現在位置
    longit = 135; latit = 34;

    printf("\nTEST 4\n");
    printf("yyyy/mm/dd,   t_UTC,         t_LMT,        t_LTST,      t_LST,        Alpha,       EoT\n");
    for (int i = 0; i < 24; i++)
    {
        sun.setDate(year, month, day, hour, min, sec);
        sun.setLocation(latit, longit);
        sun.calc();

        HourMinSec t_UTC  = RAD2HMS(sun.t_UTC);
        HourMinSec t_LMT  = RAD2HMS(sun.t_LMT);
        HourMinSec t_LTST = RAD2HMS(sun.t_LTST);
        HourMinSec t_LST  = RAD2HMS(sun.t_LST);
        HourMinSec alpha  = RAD2HMS(sun.alpha);
        HourMinSec equation = RAD2HMS(sun.equation);
        printf("%d/%02d/%02d,  ", year, month, day);
        printf("%s, ", HMS2STR(t_UTC));
        printf("%s, ", HMS2STR(t_LMT));
        printf("%s, ", HMS2STR(t_LTST));
        printf("%s, ", HMS2STR(t_LST));
        printf("%s, ", HMS2STR(alpha));
        printf("%s\n", HMS2STR(equation));

        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void test5(void)
{
    SunCalc sun;
    int year, month, day, hour, min, sec;
    double longit, latit;

    // UTC日時
    year = 2020; month = 12; day = 23;
    hour = 12; min = 0; sec = 0;
    // 現在位置
    longit = 135; latit = 34;

    printf("\nTEST 5\n");
    printf("yyyy/mm/dd,   t_UTC,         t_LMT,        t_LTST,      t_LST,        Alpha,       EoT\n");
    for (int i = 0; i < 25; i++)
    {
        sun.setDate(year, month, day, hour, min, sec);
        sun.setLocation(latit, longit);
        sun.calc();

        HourMinSec t_UTC = RAD2HMS(sun.t_UTC);
        HourMinSec t_LMT = RAD2HMS(sun.t_LMT);
        HourMinSec t_LTST = RAD2HMS(sun.t_LTST);
        HourMinSec t_LST = RAD2HMS(sun.t_LST);
        HourMinSec alpha = RAD2HMS(sun.alpha);
        HourMinSec equation = RAD2HMS(sun.equation);
        printf("%d/%02d/%02d,  ", year, month, day);
        printf("%s, ", HMS2STR(t_UTC));
        printf("%s, ", HMS2STR(t_LMT));
        printf("%s, ", HMS2STR(t_LTST));
        printf("%s, ", HMS2STR(t_LST));
        printf("%s, ", HMS2STR(alpha));
        printf("%s\n", HMS2STR(equation));

        hour += 2;
        if (hour >= 24) {
            hour = 0;
            day++;
        }
    }
}
