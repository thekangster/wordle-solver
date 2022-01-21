#include <stdio.h>
#include "names.h"
#include <limits.h>

int main(void) {
    //typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
    /*const Position pig[7] = {
        SIDE,
        SIDE,
        RAZORBACK,
        TROTTER,
        SNOUTER,
        JOWLER,
        JOWLER
    };*/
    
    int input = 0;
    printf("How many players? ");
    scanf("%d", &input);
    if (input < 2 || input > 10) {
        input = 2;
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
    }

    unsigned int seed = 0;
    printf("Random seed: ");
    scanf("%d", &seed);
    if (seed < 0 || seed > UINT_MAX) {
        seed = 2022;
        fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
    }

    /*int min = 0;
    int max = 6;
    
    int roll;
    int size = input;
    int player_points[size];
    int pos_points[7] = { 0, 0, 10, 10, 15, 5, 5 };
    char pos_phrases[7][20] = {
        "pig rolled on side",
        "pig rolled on side",
        "pig lands on back",
        "pig lands upright",
        "pig lands on snout",
        "pig lands on ear",
        "pig lands on ear",
    };
    */
    return 0;
}
