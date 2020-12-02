#include <Keyboard.h>

const int bot1 = 8;
const int bot2 = 9;
const int inter = 10;

int curinter_state;
int lastinter_state = LOW;

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
  Keyboard.begin();

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

    // mode 0
  
  if(digitalRead(bot1) ==  HIGH && mode == 0){
      Serial.println("bot1 mode 0");
  } else if (digitalRead(bot2) == HIGH && mode == 0){
      Serial.println("bot2 mode 0");
  }
  
    // mode 1
    if(digitalRead(bot1) ==  HIGH && mode == 1){
      Serial.println("bot1 mode 1");
    } else if (digitalRead(bot2) == HIGH && mode == 1){
      Serial.println("bot2 mode 1");
    }

    // mode 2
    if(digitalRead(bot1) ==  HIGH && mode == 2){
      Serial.println("bot1 mode 2");
     } else if (digitalRead(bot2) == HIGH && mode == 2){
      Serial.println("bot2 mode 2");
    }

    //mode 3
    if(digitalRead(bot1) ==  HIGH && mode == 3){
      Serial.println("bot1 mode 3");
     } else if (digitalRead(bot2) == HIGH && mode == 3){
      Serial.println("bot2 mode 3");
    }
  
}
