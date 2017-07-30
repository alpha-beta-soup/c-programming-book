// Calculates a broker's commission

#include <stdio.h>

int main(){
 float commission, value;

 for (;;) {
   printf("Enter value of trade: ");
   scanf("%f", &value);

   if (value == 0.0f) {
     break;
   } else if (value < 2500.0) {
     commission = 30.0 + .017 * value;
   } else if (value < 6250.0) {
     commission = 56.00 + .0066 * value;
   } else if (value < 20000.0) {
     commission = 76.00 + .0034 * value;
   } else if (value < 50000.0) {
     commission = 100.00 + .0022 * value;
   } else if (value < 500000.0) {
     commission = 155.00 + .0011 * value;
   } else {
     commission = 255.0 + .0009 * value;
   }

   if (commission < 39) {
     commission = 39.00;
   }

   printf("Commission: $%.2f\n\n", commission);
 }


 return 0;
}
