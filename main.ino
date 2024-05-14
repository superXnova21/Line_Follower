//Motor LEFT
#define left_motor_forward 6
#define left_motor_backward 7
#define left_motor_speed 5

//Motor RIGHT
#define right_motor_forward 9
#define right_motor_backward 10
#define right_motor_speed 11

//Motor Speed Coefficient
#define spl 25 
#define spr 22

const int STBY = 8; //Motor stand-by

//Sensor 
const int sen_cnt = 8;
int s[sen_cnt]; //this is for storing analog value of each sensor
int thresould[] = {512, 512, 512, 512, 512, 512, 512, 512}; //this is the mid value for each sensor. use this array if you want to adjust midoint of each sensor individually
int base[] = {128, 64, 32, 16, 8, 4, 2, 1}; //this is for binary to decimal conversion
int sensor; //this is to store final value after binary conversion
int sum = 0; //this is to store the count of detected sensor

//Extra 
char flag = 's';

void setup() {
  Serial.begin(9600);

  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);

  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);

  pinMode(STBY, OUTPUT);
}

void loop() {
  // reading();
  show_the_value();
}


