#include <stdio.h>
#include <math.h>

#define LCOURT 23.78
#define LSERVICE 6.4
#define HNET   .91

double Rad2Deg(double phi_rad);
double Deg2Rad(double phi_deg);
void Service(double h, double delta_L, double phi);

int main(void) {

   // Input variables
   double phi_deg = 0.;
   double h = 0.;
   double delta_L = 0.;

   // Local variables
   double phi_max = 0.;
   double phi_max_deg = 0.;
   double phi_min = 0.;
   double phi_min_deg = 0.;

   printf("\nInsert the height in meters at which the ball is hit:\n");
   scanf("%lf", &h);
   printf("h = %lf\n", h);

   phi_max = atan((delta_L + .5*LCOURT + LSERVICE)/h);
   phi_max_deg = Rad2Deg(phi_max);
   phi_min = .5*M_PI - atan((h - HNET)/(delta_L + .5*LCOURT));
   phi_min_deg = Rad2Deg(phi_min);

   printf("Maximum angle with respect to the vertical in degrees at which the ball can be hit: %lf\n", phi_max_deg);
   printf("Minimum angle with respect to the vertical in degrees at which the ball can be hit: %lf\n", phi_min_deg);

   Service(h, delta_L, phi_max_deg);
   Service(h, delta_L, phi_min_deg);

   printf("\nInsert the angle with respect to the vertical in degrees at which the ball is hit:\n");
   scanf("%lf", &phi_deg);
   printf("phi = %lf\n", phi_deg);

   Service(h, delta_L, phi_deg);

   return 0;
}

double Rad2Deg(double phi_rad) {

   return 180./M_PI*phi_rad;
}

double Deg2Rad(double phi_deg) {

   return M_PI/180.*phi_deg;
}

void Service(double h, double delta_L, double phi_deg) {

   double theta = 0.;
   double delta_court = 0.;
   double delta_net = 0.;

   double phi = 0.;
   double theta_deg = 0.;

   phi = Deg2Rad(phi_deg);

   theta = .5*M_PI - phi;
   delta_court = (delta_L + .5*LCOURT + LSERVICE) - h*tan(phi);
   delta_net = (LSERVICE - delta_court)*tan(theta) - HNET;

   theta_deg = Rad2Deg(theta);

   printf("\nThe ball hit the court with an angle of %lf degrees with respect to the floor.\n", theta_deg);
   printf("The ball hit the court at %lf meters from the service line.\n", delta_court);
   printf("The ball passed %lf meters above the net.\n", delta_net);

   return;
}
