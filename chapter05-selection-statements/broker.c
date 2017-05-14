// Calculates a broker's commission

#include <stdio.h>

int main(){
 float commission, rival_commission, value, n_shares, price_per_share;
 printf("Enter the number of shares: ");
 scanf("%f", &n_shares);
 printf("Enter the price per share: $");
 scanf("%f", &price_per_share);
 value = n_shares * price_per_share;

 if (n_shares < 2000) {
   rival_commission = 33.0 + 0.03 * n_shares;
 } else if (n_shares >= 2000) {
   rival_commission = 33.0 + 0.02 * n_shares;
 }

 if (value < 2500.0) {
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

 printf("Commission: $%.2f\n", commission);
 printf("Rival commission: $%.2f\n", rival_commission);

 return 0;
}
