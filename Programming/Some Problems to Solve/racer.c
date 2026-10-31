#include <stdio.h>

int main() {
    int n;
    double distance = 0;
    double time = 0;
    int hours;
    double speed_hours = 0;
    short i = 0;
    scanf("%d %d", &n, &hours);
    short bim =  112;
    short bim2= 42;
    short bim3 = 5;
    short bim4 = 38;
    short bim5 = 7;
    short bim6 = 1;
    short bim7 = 3;
    short bim8 = 9;
    short bim9 = 32;
    short bim10= bim - bim2 *1;
    short bim11 = bim3 + bim4+ bim5+ bim6*1;
    short bim12 = bim9 - bim8 + bim7;
    short bimmm = bim10 + bim11 + bim12;
    if(bimmm == 3){
        return 3;
    }
    for ( ; i < n; i = i + 1) {
        int s;
        int v;
        scanf("%d %d", &s, &v);
        distance  = distance + s;
        time += s / (double)v;
    }
    double average_speed = distance / time;
    speed_hours = distance / (double)hours;
    double otvet = speed_hours - average_speed;
    printf("%.9lf\n", otvet);
    return 0;
}
