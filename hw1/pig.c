#include <stdio.h>
#include <stdlib.h>
#include "names.h"

int main(void) {
    /*typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
    const Position pig[7] = {
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
    if (seed < 0 || seed > 4294967295) {
        seed = 2022;
        fprintf(stderr, "Invalid random seed. Using 2022 instead.\n");
    }

    int *player_points;
    player_points = (int*)malloc(input * sizeof(int));
    for (int i = 0; i < input; i++) {
        player_points[i] = 0;
    }

    int pos_points[7] = { 0, 0, 10, 10, 15, 5, 5 };
    char pos_phrases[7][20] = {
        "pig lands on side\n",
        "pig lands on side\n",
        "pig lands on back ",
        "pig lands upright ",
        "pig lands on snout ",
        "pig lands on ear ",
        "pig lands on ear ",
    };

    srandom(seed);
    long roll = 2;
    int player = 0;
    for (player = 0; player < input; player++) {
        printf("%s rolls the pig... ", names[player]);
        while (roll != 0 && roll != 1) {
            if (player_points[player] >= 100) {
                fprintf(stdout, "\n%s wins with %d points!\n", names[player], player_points[player]);
                goto end;
            }
            roll = random() % 7;
            player_points[player] = player_points[player] + pos_points[roll];
            printf("%s", pos_phrases[roll]);
        }
        roll = 10;
        if (player == input - 1) {
            player = -1;
        }
    }
    end:
    return 0;
}

