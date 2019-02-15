//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=680
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define THRESHOLD 0.0001

struct point {
    float x;
    float y;
};

struct film {
    point initial_point;
    point end_point;
    float coefficient;
};

void sortPointsByXAscending(film *f);
void sortFilmsByXAscending(film* films, int filmCount);

int main() {
    int cases;
    scanf("%d\n", &cases);
    for(int i = 0; i < cases; i++) {
        int segment_count;
        scanf("%d", &segment_count);
        film films[segment_count];
        for(int j = 0; j < segment_count; j++) {
            film* cur_film = &films[j];
            scanf("%f %f %f %f %f", &cur_film->initial_point.x, &cur_film->initial_point.y, &cur_film->end_point.x,
                                    &cur_film->end_point.y, &cur_film->coefficient);
            sortPointsByXAscending(cur_film);
        }
        sortFilmsByXAscending(films, segment_count);
        
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

// Lazy bubble sort
void sortFilmsByXAscending(film* films, int filmCount) {
    for(int i = 0; i < filmCount; i++) {
        for(int j = i; j < filmCount; j++) {
            if(films[i].initial_point.x > films[j].initial_point.x) {
                film f = films[i];
                films[i] = films[j];
                films[j] = f;
            }
        }
    }
}