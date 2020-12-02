const int bot1 = 8;
const int bot2 = 9;
const int inter = 10;

int curinter_state, curr_s1, curr_s2;
int lastinter_state = LOW;
int last_s1 = LOW;
int last_s2 = LOW;

int led1 = 12;
int led2 = 13;
int mode = 0;

void setup() {
  Serial.begin(9600);
  pinMode(bot1, INPUT_PULLUP);
  pinMode(bot2, INPUT_PULLUP);
  pinMode(inter, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}


void loop(){
  //check mode
  curinter_state = digitalRead(inter);
  if (lastinter_state == LOW && curinter_state == HIGH){
      mode = mode + 1;
  }
  lastinter_state = curinter_state;

  
  // mode
  if (mode > 3){
    mode = 0;
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
   
  switch (mode){
    case 0:
      mode = 0;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      break;
    case 1:
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
      break;
   case 3:
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     break;

   }


  // check if pressed
  curr_s1 = digitalRead(bot1);
  curr_s2 = digitalRead(bot2);

    // mode 0
  
  if((last_s1 == LOW && curr_s1 == HIGH) && mode == 0){
      Serial.println("10");
  } else if ((last_s2 == LOW && curr_s2 == HIGH) && mode == 0){
      Serial.println("20");
  }
  
    // mode 1
    if((last_s1 == LOW && curr_s1 == HIGH) && mode == 1){
      Serial.println("11");
    } else if ((last_s2 == LOW && curr_s2 == HIGH) && mode == 1){
      Serial.println("21");
    }

    // mode 2
    if((last_s1 == LOW && curr_s1 == HIGH) && mode == 2){
      Serial.println("12");
     } else if ((last_s2 == LOW && curr_s2 == HIGH) && mode == 2){
      Serial.println("22");
    }

    //mode 3
    if((last_s1 == LOW && curr_s1 == HIGH) && mode == 3){
      Serial.println("13");
     } else if ((last_s2 == LOW && curr_s2 == HIGH) && mode == 3){
      Serial.println("23");
    }
    
  last_s1 = curr_s1;
  last_s2 = curr_s2;
}
