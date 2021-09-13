#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "analitica.h"

point *create_pairs(int number_of_pairs) {
    point *ordered_pair;
    ordered_pair = (point *)malloc(sizeof(point) * number_of_pairs);

    if (ordered_pair == NULL) 
        exit(EXIT_FAILURE);

    return ordered_pair;
}

void read_pairs(point *point) {
    scanf("%f %f", &point->x, &point->y);
}

unity_type distance_between_points(point initial_point, point final_point) {
    unity_type delta_x = (final_point.x - initial_point.x);
    unity_type delta_y = (final_point.y - initial_point.y);

    unity_type distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));

    return distance;
}

unity_type total_distance(const point *pairs, int number_of_pairs) {
    unity_type sum_of_distance = 0;

    for (int i = 1; i < number_of_pairs; i++) {
        sum_of_distance += distance_between_points(pairs[i - 1], pairs[i]);
    }

    return sum_of_distance;
}
