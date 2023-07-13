// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>

int field(int right_rocket, int left_rocket, int score_right, int score_left, int ball_x, int ball_y) {
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 82; j++) {
            if (i == 0 || i == 26 || j == 0 || j == 81)
                printf("#");
            else if (j == 1 && (i == right_rocket || i == right_rocket + 1 || i == right_rocket + 2))
                printf("]");
            else if (j == 80 && (i == left_rocket || i == left_rocket + 1 || i == left_rocket + 2))
                printf("[");
            else if (j == ball_x && i == ball_y)
                printf("*");
            else if (j == 35 && i == 5)
                printf("%d", score_right);
            else if (j == 45 && i == 5)
                printf("%d", score_left);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 1;
}

int main(void) {
    int flag_ball_x = -1, flag_ball_y = 1;
    int right_rocket = 12, left_rocket = 12;
    int ball_x = 41, ball_y = 13;
    char step;
    int score_right = 0, score_left = 0;

    do {
        scanf("%c", &step);
        switch (step) {
            case ' ':

                field(right_rocket, left_rocket, score_right, score_left, ball_x, ball_y);
                if ((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2) &&
                    ball_x == 79)
                    flag_ball_x = -1;
                if (score_right == 21) {
                    printf("RIGHT PLAYER WINS!!!");
                    return 0;
                }
                if (score_left == 21) {
                    printf("LEFT PLAYER WINS!!!");
                    return 0;
                }
                if ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2) &&
                    ball_x == 2)
                    flag_ball_x = 1;
                if (ball_y == 25) flag_ball_y = -1;
                if (ball_y == 1) flag_ball_y = 1;
                if (ball_x == 80) {
                    score_right++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = 1;
                    flag_ball_y = 1;
                }
                if (ball_x == 1) {
                    score_left++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = -1;
                    flag_ball_y = 1;
                }
                ball_x = ball_x + flag_ball_x;
                ball_y = ball_y + flag_ball_y;
                break;

            case 'a':
                if (right_rocket != 1) right_rocket--;

                field(right_rocket, left_rocket, score_right, score_left, ball_x, ball_y);
                if (score_right == 21) {
                    printf("RIGHT PLAYER WINS!!!");
                    return 0;
                }
                if (score_left == 21) {
                    printf("LEFT PLAYER WINS!!!");
                    return 0;
                }
                if ((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2) &&
                    ball_x == 79)
                    flag_ball_x = -1;
                if ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2) &&
                    ball_x == 2)
                    flag_ball_x = 1;
                if (ball_y == 25) flag_ball_y = -1;
                if (ball_y == 1) flag_ball_y = 1;
                if (ball_x == 80) {
                    score_right++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = 1;
                    flag_ball_y = 1;
                }
                if (ball_x == 1) {
                    score_left++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = -1;
                    flag_ball_y = 1;
                }
                ball_x = ball_x + flag_ball_x;
                ball_y = ball_y + flag_ball_y;
                break;

            case 'z':
                if (right_rocket != 23) right_rocket++;

                field(right_rocket, left_rocket, score_right, score_left, ball_x, ball_y);
                if (score_right == 21) {
                    printf("RIGHT PLAYER WINS!!!");
                    return 0;
                }
                if (score_left == 21) {
                    printf("LEFT PLAYER WINS!!!");
                    return 0;
                }
                if ((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2) &&
                    ball_x == 79)
                    flag_ball_x = -1;
                if ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2) &&
                    ball_x == 2)
                    flag_ball_x = 1;
                if (ball_y == 25) flag_ball_y = -1;
                if (ball_y == 1) flag_ball_y = 1;
                if (ball_x == 80) {
                    score_right++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = 1;
                    flag_ball_y = 1;
                }
                if (ball_x == 1) {
                    score_left++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = -1;
                    flag_ball_y = 1;
                }
                ball_x = ball_x + flag_ball_x;
                ball_y = ball_y + flag_ball_y;
                break;

            case 'k':
                if (left_rocket != 1) left_rocket--;

                field(right_rocket, left_rocket, score_right, score_left, ball_x, ball_y);
                if (score_right == 21) {
                    printf("RIGHT PLAYER WINS!!!");
                    return 0;
                }
                if (score_left == 21) {
                    printf("LEFT PLAYER WINS!!!");
                    return 0;
                }
                if ((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2) &&
                    ball_x == 79)
                    flag_ball_x = -1;
                if ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2) &&
                    ball_x == 2)
                    flag_ball_x = 1;
                if (ball_y == 25) flag_ball_y = -1;
                if (ball_y == 1) flag_ball_y = 1;
                if (ball_x == 80) {
                    score_right++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = 1;
                    flag_ball_y = 1;
                }
                if (ball_x == 1) {
                    score_left++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = -1;
                    flag_ball_y = 1;
                }
                ball_x = ball_x + flag_ball_x;
                ball_y = ball_y + flag_ball_y;
                break;

            case 'm':
                if (left_rocket != 23) left_rocket++;

                field(right_rocket, left_rocket, score_right, score_left, ball_x, ball_y);
                if (score_right == 21) {
                    printf("RIGHT PLAYER WINS!!!");
                    return 0;
                }
                if (score_left == 21) {
                    printf("LEFT PLAYER WINS!!!");
                    return 0;
                }
                if ((ball_y == left_rocket || ball_y == left_rocket + 1 || ball_y == left_rocket + 2) &&
                    ball_x == 79)
                    flag_ball_x = -1;
                if ((ball_y == right_rocket || ball_y == right_rocket + 1 || ball_y == right_rocket + 2) &&
                    ball_x == 2)
                    flag_ball_x = 1;
                if (ball_y == 25) flag_ball_y = -1;
                if (ball_y == 1) flag_ball_y = 1;
                if (ball_x == 80) {
                    score_right++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = 1;
                    flag_ball_y = 1;
                }
                if (ball_x == 1) {
                    score_left++;
                    ball_x = 41;
                    ball_y = 13;
                    right_rocket = 12;
                    left_rocket = 12;
                    flag_ball_x = -1;
                    flag_ball_y = 1;
                }
                ball_x = ball_x + flag_ball_x;
                ball_y = ball_y + flag_ball_y;
                break;

            default:
                return 0;
        }
    } while (scanf("%c", &step) == 1);

    return 0;
}