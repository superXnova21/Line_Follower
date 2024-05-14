void line_follow(){
  while(1){
    reading();

    if(sensor == 0b00000000){
      if(flag != 's'){
        //etay dhuka mane right or left turn er flag on hoise kuno ek jagay
        motor(10 * spl, 10 * spr);
        delay(20);
        if(flag == 'l') motor(-6 * spl, 6 * spr);
        else if(flag == 'r') motor(6 * spl, -6 * spr);
      }
      flag = 's';
    }

    //straight line e ase
    if(sensor == 0b00011000) motor(10 * spl, 10 * spr);

    //right e bari dewa
    else if(sensor == 0b00001000) motor(10 * spl, 9 * spr);
    else if(sensor == 0b00001100) motor(10 * spl, 7 * spr);
    else if(sensor == 0b00000100) motor(10 * spl, 5 * spr);
    else if(sensor == 0b00000110) motor(10 * spl, 3 * spr);
    else if(sensor == 0b00000010) motor(10 * spl, 1 * spr);
    else if(sensor == 0b00000011) motor(10 * spl, -1 * spr);
    else if(sensor == 0b00000001) motor(10 * spl, -3 * spr);

    //left e bari dewa
    else if(sensor == 0b00010000) motor(9 * spl, 10 * spr);
    else if(sensor == 0b00110000) motor(7 * spl, 10 * spr);
    else if(sensor == 0b00100000) motor(5 * spl, 10 * spr);
    else if(sensor == 0b01100000) motor(3 * spl, 10 * spr);
    else if(sensor == 0b01000000) motor(1 * spl, 10 * spr);
    else if(sensor == 0b11000000) motor(-1 * spl, 10 * spr);
    else if(sensor == 0b10000000) motor(-3 * spl, 10 * spr);

    //left e 90 degree turn paise
    else if(
      sensor == 0b01111000 || sensor == 0b01111100 ||
      sensor == 0b01110000 || sensor == 0b11110000 ||
      sensor == 0b11111000
    ) flag = 'l';

    //right e 90 degree turn paise
    else if(
      sensor == 0b00011110 || sensor == 0b00111110 ||
      sensor == 0b00001110 || sensor == 0b00001111 || 
      sensor == 0b00011111
    ) flag = 'r';


  }
}