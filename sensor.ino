void reading() {
  sensor = 0; //this is to refresh initial value
  sum = 0;
  for(int i = 0; i < sen_cnt; i++){
    s[i] = analogRead(sen_cnt-i-1);
    (s[i] > thresould[i]) ? s[i] = 1 : s[i] = 0;
    sensor += s[i]*base[i];
    sum += s[i];
  }
}

void show_the_value() {
  reading();
  for (int i = 0 ; i < sen_cnt ; i++){
    Serial.print(String(s[i], 10) + " ");
  }
  Serial.println(sensor);
}
