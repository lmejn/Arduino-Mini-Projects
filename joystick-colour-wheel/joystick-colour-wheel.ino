/* Joystick controlled colour wheel
Uses the joystick to control the colour of an RGB LED

This has been adapted from the Elegoo Arduino Super Starter kit 
RGB LED code and Analog Joystick code (www.elegoo.com 2016.12.09)
*/
const double pi = 2.*acos(0.);

// Arduino pin numbers
/// Joystick pins
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
/// LED pins
const int red_pin = 10; // analog
const int blue_pin = 11; // analog
const int green_pin = 9; // analog

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  digitalWrite(red_pin, HIGH);
  digitalWrite(blue_pin, HIGH);
  digitalWrite(green_pin, HIGH);
}

void color_from_pos(int i, int j, int& R, int& G, int& B) {
  double th, r, x, y;
  
  x = (i-509)/512.;
  y = (j-489)/512.;
  
  th = atan2(y, x);
  r = sqrt(x*x+y*y);

  R = 128*r*max(sin(th), 0.);
  G = 128*r*max(sin(th+2.*pi/3), 0.);
  B = 128*r*max(sin(th+4.*pi/3), 0.);
  
}

void loop() {
  int X_read, Y_read, R, G, B;
  
  X_read = analogRead(X_pin);
  Y_read = analogRead(Y_pin);

  color_from_pos(X_read, Y_read, R, G, B);
  
  analogWrite(red_pin, R);
  analogWrite(green_pin, G);
  analogWrite(blue_pin, B);
  
}
