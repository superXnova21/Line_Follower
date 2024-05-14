void line_follow(){
  int pos = 0;
  while(1){
    reading();

    if(sum == 0){
      if(flag != 's'){
        //etay dhuka mane right or left turn er flag on hoise kuno ek jagay
        if(flag == 'l'){
          motor(-3 * spl, 3 * spr);
          while(!s[3] && !s[4]) reading();
        }
        else if(flag == 'r'){
          motor(3 * spl, -3 * spr);
          while(!s[3] && !s[4]) reading();
        }
        else if(flag == 't'){
          motor(3 * spl, -3 * spr);
          while(!s[3] && !s[4]) reading();
        }
        else if(flag == 'v'){
          motor(3 * spl, -3 * spr);
          while(!s[3] && !s[4]) reading();
        }
        else if(flag == 'w'){
          motor(-3 * spl, 3 * spr);
          while(!s[3] && !s[4]) reading();
        }
        flag = 's';
      }
    }

    //Jodi 2 ta or 1 ta sensor ON thake 
    else if(sum == 1 || sum == 2){
      //straight line e ase
      if(sensor == 0b00011000){
        if(flag == 't') flag = 's';
        if(pos != 0){
          (pos == 1) ? motor(-10 * spl, 10 * spr) : motor(10 * spl, -10 * spr);
          delay(10); pos = 0;
        }
        motor(10 * spl, 10 * spr);
      }

      //right e bari dewa
      else if(sensor == 0b00001000){
        if(flag == 't') flag = 's';
        motor(10 * spl, 9 * spr);
      }
      else if(sensor == 0b00001100){
        pos = 1; motor(10 * spl, 7 * spr);
      }
      else if(sensor == 0b00000100){
        pos = 1; motor(10 * spl, 5 * spr);
      }
      else if(sensor == 0b00000110){
        pos = 1; motor(10 * spl, 3 * spr);
      }
      else if(sensor == 0b00000010){
        pos = 1; motor(10 * spl, 1 * spr);
      }
      else if(sensor == 0b00000011){
        pos = 1; motor(10 * spl, -1 * spr);
      }
      else if(sensor == 0b00000001){
        pos = 1; motor(10 * spl, -3 * spr);
      }

      //left e bari dewa
      else if(sensor == 0b00010000){
        if(flag == 't') flag = 's';
        motor(9 * spl, 10 * spr);
      }
      else if(sensor == 0b00110000){
        pos = -1; motor(7 * spl, 10 * spr);
      }
      else if(sensor == 0b00100000){
        pos = -1; motor(5 * spl, 10 * spr);
      }
      else if(sensor == 0b01100000){
        pos = -1; motor(3 * spl, 10 * spr);
      }
      else if(sensor == 0b01000000){
        pos = -1; motor(1 * spl, 10 * spr);
      }
      else if(sensor == 0b11000000){
        pos = -1; motor(-1 * spl, 10 * spr);
      }
      else if(sensor == 0b10000000){
        pos = -1; motor(-3 * spl, 10 * spr);
      }
    }

    //Jodi 3-5 ta sensor ON thake
    else if((sum == 3 || sum == 4 || sum == 5) && flag != 't'){
      //left e 90 degree turn paise
      if(
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

      else if(
        sensor == 0b00011001 || sensor == 0b00011011 ||
        sensor == 0b00110111 || sensor == 0b00001011 || 
        sensor == 0b00011001 || sensor == 0b00110011
      ) flag = 'v';

      else if(
        sensor == 0b10011000 || sensor == 0b11011000 ||
        sensor == 0b11101100 || sensor == 0b11010000 || 
        sensor == 0b10011000 || sensor == 0b11001100
      ) flag = 'w';
    }
    
    else if(sum == 6 || sum == 7 || sum == 8){
      delay(50);
      reading();
      if(sum == 8){
        motor(0, 0);
        while(sum == 8) reading();
        delay(1000);
      }
      else if(sum == 0) flag = 't';
      else flag = 's';
    }
  }
}