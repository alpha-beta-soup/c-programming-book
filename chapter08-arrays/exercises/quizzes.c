#include <stdio.h>

#define N_STUDENTS 5
#define N_QUIZZES 5

int main() {
  int quiz_scores[N_QUIZZES][N_STUDENTS] = {};
  int student, quiz, high, low, total;
  float running_average;

  for (quiz = 0; quiz < N_QUIZZES; quiz++) {
    printf("Enter quiz scores for quiz %d (%d students): ", quiz + 1, N_STUDENTS);
    for (student = 0; student < N_STUDENTS; student++) {
      scanf("%d", &quiz_scores[quiz][student]);
    }
  }
  printf("\nQuiz results\n");
  for (quiz = 0; quiz < N_QUIZZES; quiz++) {
    running_average = 0;
    high = quiz_scores[quiz][0]; // Initially
    low = quiz_scores[quiz][0]; // Initially
    for (student = 0; student < N_STUDENTS; student++) {
      running_average = running_average + ((quiz_scores[quiz][student] - running_average) / (student + 1));
      if (quiz_scores[quiz][student] > high) {
        high = quiz_scores[quiz][student];
      }
      if (quiz_scores[quiz][student] < low) {
        low = quiz_scores[quiz][student];
      }
    }
    printf("Average score for quiz %d: %.2f\n", quiz + 1, running_average);
    printf("Highest score for quiz %d: %3d\n", quiz + 1, high);
    printf("Lowest score for quiz %d: %3d\n", quiz + 1, low);
  }
  printf("\nStudent totals\n");
  for (student = 0; student < N_STUDENTS; student++) {
    printf("Student %d: ", student + 1);
    total = 0;
    for (quiz = 0; quiz < N_QUIZZES; quiz++) {
      total += quiz_scores[quiz][student];
    }
    printf("Average %.2f, total %3d\n", (float) total / N_QUIZZES, total);
  }
  printf("\n");
  return 0;
}
