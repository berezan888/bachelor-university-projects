#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double radius;
    int x;
    int y;
    int z;
} Hole;

int compare(const void *a, const void *b) {
    const Hole *holeA = (const Hole *)a;
    const Hole *holeB = (const Hole *)b;
    return holeA->z - holeB->z;
}

int main() {
    int M;
    int S;
    scanf("%d %d", &M, &S);
    Hole *holes = (Hole *)malloc(M * sizeof(Hole));
    if (holes == NULL) {
        exit(1);
    }
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
    short i = 0;
    for ( ; i < M; ++i) {
        scanf("%lf %d %d %d", &holes[i].radius, &holes[i].x, &holes[i].y, &holes[i].z);
    }
    qsort(holes, M, sizeof(Hole), compare);
    short v = 0;
    for ( ; v < S; ++v) {
        double thickness = 100.0;
        for (int j = 0; j < M; ++j) {
            if (holes[j].z < (i + 1) * 100) {
                double d = sqrt(pow(holes[j].x, 2) + pow(holes[j].y, 2));
                if (d + holes[j].radius >= 100.0 * i) {
                    double x = (100.0 * i - holes[j].radius) / d;
                    double volume = acos(x) - x * sqrt(1.0 - pow(x, 2));
                    thickness -= holes[j].radius * volume;
                }
            } else {
                break;
            }
        }
        printf("%.9lf\n", thickness);
    }
    free(holes);
    return 0;
}
