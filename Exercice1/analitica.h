#ifndef ANALITICA_H
#define ANALITICA_H

typedef float unity_type;

typedef struct ORDERED_PAIR {
    unity_type x, y;
} point;

point *create_pairs(int number_of_pairs);

void read_pairs(point *point);

unity_type distance_between_points(point initial_point, point final_point);

unity_type total_distance(const point *pairs, int number_of_pairs);

#endif
