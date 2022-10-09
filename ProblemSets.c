#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

// Problem set 3: Q1
#define MAX 9

typedef struct {
    char* name;
    int votes;
}
candidate;

candidate candidates[MAX];

int candidate_count;

// Function prototypes
bool vote(char* name);
void print_winner(void);

char *inputString(FILE* fp, size_t size);
double countCharacters(char* str);

char* cipherText(char* str, char* key);

void Mario(int height) {
    while (height < 1 || height >8 ) {
        printf("Height: ");
        scanf("%i", &height);
    }
    char c = '#';
    char space = ' ';
    for (int i=0; i<height; i++) {
        for (int k=height-1; k>i; k--) {
            printf("%c",space);
        }
        for (int j=0; j<=i; j++) {
            printf("%c",c);
        }
        printf("%c",space);
        for (int j=0; j<=i; j++) {
            printf("%c",c);
        }
        printf("\n");
    } 
}


int main(int argc,char* argv[]) {
    /** Problem Set 1 **/
    //MARIO
//    int height;
//    printf("Height: ");
//    scanf("%i", &height);
//    Mario(height);
    
    //CREDIT
//    4003600000000014
//    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2 = 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8 =  2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
//    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
    char* input;
    printf("Number: ");
    scanf("%s", input);
    int len = strlen(input);
    int *arr=(int*)malloc(len*sizeof(int));
    for (int i=0; i<len; i++) 
        arr[i]=input[i]-48;  
    int sum;
    for (int i=len-1; i>=0; i--) {
        if (i>0) {
            if (arr[i-1] * 2 > 9) 
                sum += arr[i-1]*2-9;
            else {
                sum += arr[i-1]*2;
            }
        }
        sum += arr[i];
        i--;
    }
    printf("%i\n", sum);
    if (sum % 10 == 0) {
        if (arr[0] == 4 && len >=13 && len <=16) {
            printf("%s\n", "VISA");
        } else if (arr[0] == 5 && (
                arr[1] == 1 || arr[1] == 2 || arr[1] == 3 || arr[1] == 4 || arr[1] == 5
                ) && len == 16) {
            printf("%s\n", "MasterCard");
        } else if (arr[0] == 3 && (
                arr[1] == 4 || arr[1] == 7
                ) && len == 15) {
            printf("%s\n", "American Express");
        } 
    } else {
        printf("%s\n", "INVALID");
    }
    free(arr);
    
    
    /** Problem Set 2 **/
    /*//Question 1: Readability test
    char *text;
    printf("Text : ");
    text = inputString(stdin, 1000);
    double grade = countCharacters(text);
    if (grade<1) {
        printf("Before Grade 1"); 
    } else if (grade>= 16) {
        printf("Grade 16+");
    } else 
        printf("Grade %i\n", (int)round(countCharacters(text)));
    
    free(text);
    return 0;
    */
    
    /*//Question 2: Substitution
    char* key = argv[1];
    if (strlen(key) != 26 && argc != 2) {
        printf("ERROR: Key must contain 26 characters.\n");
        return 1;
    }
    bool error = false;
    for (int i=0; i<26; i++) {
        for (int j=0; j<i; j++) {
            if (key[i] == key[j]) {
                error = true; //duplicate keys
            }
        }
        if (key[i]<65 || (key[i]>90 && key[i]<97) || key[i]>122) {
            error = true;  //not an alphabet letter
        }
    }
    if (error) printf("ERROR: Invalid Key!");
    printf("Key: %s\n",key);
    printf("plaintext: ");
    char* plaintext = inputString(stdin, 100);
    char* ciphertext = cipherText(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
    return 0; */
    
    /**Problem Set 3*/
    /*//Question 1: Plurality
    // Check for invalid usage
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count;
    printf("Number of voters: ");
    scanf("%i", &voter_count);
    for (int i = 0; i < voter_count; i++) {
        char name[20];
        printf("Vote: ");
        scanf("%s",&name);
        // Check for invalid vote
        if (!vote(name)) {
            printf("Invalid vote.\n");
        }
    }
    print_winner();
    return 0;*/
}

char *inputString(FILE* fp, size_t size){
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    return realloc(str, sizeof(*str)*len);
}

double countCharacters(char* str) {
    int countChars = 0, countWords = 1, countSentences=0;
    for (int i=0; i<strlen(str); i++) {
        if ((str[i] >= 65 && str[i] <= 90) ||  (str[i] >= 97 && str[i] <= 122)) {
            countChars++;
        } else if (str[i] == ' ') {
            countWords++;
        } else if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
            countSentences++;
        }
    }
    //L--average number of letters per 100 words in the text
    //S--average number of sentences per 100 words
    double L, S;
    L = (countChars * 100) / countWords;
    S = (countSentences * 100) / countWords;
    return 0.0588 * L - 0.296 * S - 15.8;
}

char* cipherText(char* str, char* key) {
    for (int i=0; i<strlen(str); i++) {
        if (str[i]>=65 && str[i] <=95) { //if uppercase
            str[i] = key[str[i]-65];
        } else if (str[i]>=97 && str[i] <=122) { //if lowercase
            str[i] = tolower(key[str[i]-97]);
        }
    }
    return str;
}

// Update vote totals given a new vote
bool vote(char* name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {
    int highestScore = candidates[0].votes, temp=0;
    printf("\nWinner(s)\n");
    printf("--------\n");
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes >= highestScore) {
            highestScore = candidates[i].votes;
            printf("%s, %i\n", candidates[i].name, candidates[i].votes);
        } 
    }
    return;
}
