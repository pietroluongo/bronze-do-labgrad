//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=680
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
#define THRESHOLD 0.0001

struct point {
    double x;
    double y;
};

struct film {
    point initial_point;
    point end_point;
    double coefficient;
};

void sortPointsByXAscending(film *f);
void sortFilmsByXAscending(film* films, int filmCount);

bool filmCompare(const film& f1, const film& f2);

int main() {
    int cases;
    scanf("%d\n", &cases);
    for(int i = 0; i < cases; i++) {
        int segment_count;
        scanf("%d", &segment_count);
        vector<film> films;
        vector<double> vals;
        for(int j = 0; j < segment_count; j++) {
            film f;
            film* cur_film = &f;
            scanf("%lf %lf %lf %lf %lf", &cur_film->initial_point.x, &cur_film->initial_point.y, &cur_film->end_point.x,
                  &cur_film->end_point.y, &cur_film->coefficient);
            sortPointsByXAscending(cur_film);
            films.push_back(f);
            vals.push_back(f.initial_point.x);
            vals.push_back(f.end_point.x);
        }
        sort(vals.begin(), vals.end());
        sort(films.begin(), films.end(), filmCompare);
        printf("%lu\n", vals.size() + 1);
        printf("-inf %.3f 1.000\n", vals[0]);
        for(int j = 1; j < vals.size(); j++) {
            double light = 1.0;
            for(int k = 0; k < films.size(); k++) {
                if(films[k].initial_point.x <= vals[j-1] && films[k].end_point.x >= vals[j]) {
                    light *= films[k].coefficient;
                }
            }
            printf("%.3f %.3f %.3f\n", vals[j-1], vals[j], light);
        }
        printf("%.3f +inf 1.000\n", vals[vals.size()-1]);
        if(i != cases - 1)
            printf("\n");
    }
    return 0;
}

void sortPointsByXAscending(film *f) {
    if(f->initial_point.x > f->end_point.x) {
        point p = f->initial_point;
        f->initial_point = f->end_point;
        f->end_point = p;
    }
}

bool filmCompare(const film& f1, const film& f2) {
    return f1.initial_point.x < f2.initial_point.x;
}