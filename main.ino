//Motor LEFT
#define left_motor_forward 6
#define left_motor_backward 7
#define left_motor_speed 5

//Motor RIGHT
#define right_motor_forward 9
#define right_motor_backward 10
#define right_motor_speed 11

//Motor Speed Coefficient
#define spl 20 
#define spr 17  

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
  // show_the_value();
  line_follow();
  // reading();
  // if(
  //     sensor == 0b00011110 || sensor == 0b00111110 ||
  //     sensor == 0b00001110 || sensor == 0b00001111 || 
  //     sensor == 0b00011111
  //   ){
  //     motor(10 * spl, 10 * spr);
  //     delay(15);
  //     motor(0, 0);
  //   }
  //   else if(sensor == 0b00011000) motor(10 * spl, 10 * spr);
  // else motor(0, 0);
}


