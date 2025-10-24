// EECS 348 Lab 8
// Boolean Properties and Truth Tables
// Input: User inputed NFL Score
// Output: All of the possible combinations of scoring plays for a score
// Austin Lin
// Creation date: 10/23/2025


int main(void) {
    int score;

    //Gets the input from the user and makes sure its a integer
    printf("Enter the NFL score: ");
    if (scanf("%d", &score) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    // Checks if the num is less than or equal to 1
    if (score <= 1) {
        printf("Invalid score. Score must be greater than 1.\n");
        return 1;
    }

    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    // Nested loops to check all combinations
    for (int td2 = 0; td2 * 8 <= score; td2++) {
        for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) {
            for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) {
                for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) {
                    for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) {
                        if (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }

    return 0;
}