#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void lab1() {
    int start;
    printf("Start size: ");
    scanf("%i", &start);
    while (start < 9) {
        printf("Start size: ");
        scanf("%i", &start);
    }
    int end;
    printf("End size: ");
    scanf("%i", &end);
    while (end < start) {
        printf("End size: ");
        scanf("%i", &end);
    }
    int count = 0;
    int current = start;
    while (current < end) {
        int new = current / 3;
        int old = current / 4;
        current = current + new - old;
        count++;
    }
    printf("Years: %i\n", count);
}

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(char* word);

int main(void) {
    /**LAB 1 **/
    //lab1();

    /**LAB 2**/
    char word1[20];
    char word2[20];
    printf("Player 1: ");
    fgets(word1,20,stdin);
    printf("Player 2: ");
    fgets(word2,20,stdin);
    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    printf("%i\n", score1);
    printf("%i\n", score2);
    // TODO: Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score1 < score2) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }
    return 0;
}

int compute_score(char* word){
    int sum=0;
    for (int i=0; i<strlen(word); i++) {
        char current = tolower(word[i]);
        sum += POINTS[current - 97];
    }
    return sum;
}



