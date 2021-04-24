#include <stdio.h>
#include <math.h>

#define LCOURT 23.78
#define LSERVICE 6.4
#define HNET   .91

double Rad2Deg(double phi_rad);
double Deg2Rad(double phi_deg);

int main(void) {

   // Input variables
   double phi_deg = 0.;
   double h = 0.;
   double delta_L = 0.;

   // output variables
   double theta = 0.;
   double delta_court = 0.;
   double delta_net = 0.;

   // Local variables
   double phi = 0.;
   double phi_max = 0.;
   double phi_max_deg = 0.;
   double theta_deg = 0.;

   printf("Insert the height in meters at which the ball is hit:\n");
   scanf("%lf", &h);
   printf("h = %lf\n", h);

   phi_max = atan((delta_L + .5*LCOURT + LSERVICE)/h);
   phi_max_deg = Rad2Deg(phi_max);
   // printf("Maximum angle with respect to the vertical in degrees at which the ball can be hit is: %lf\n", phi_max_deg);

   printf("Insert the angle with respect to the vertical in degrees at which the ball is hit:\n");
   scanf("%lf", &phi_deg);
   printf("phi = %lf\n", phi_deg);

   phi = Deg2Rad(phi_deg);

   theta = M_PI/2. - phi;
   delta_court = (delta_L + .5*LCOURT + LSERVICE) - h*tan(phi);
   delta_net = (LSERVICE - delta_court)*tan(theta) - HNET;

   theta_deg = Rad2Deg(theta);

   printf("\nThe ball hit the court with an angle of %lf degrees with respect to the floor.\n", theta_deg);
   printf("The ball hit the court at %lf meters from the service line.\n", delta_court);
   printf("The ball passed %lf meters above the net.\n", delta_net);

   return 0;
}

double Rad2Deg(double phi_rad) {

   return 180./M_PI*phi_rad;
}

double Deg2Rad(double phi_deg) {

   return M_PI/180.*phi_deg;
}
