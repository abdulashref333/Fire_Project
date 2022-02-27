char serial;
const int r1=8,r2=9,l1=10,l2=11,e1=5,e2=6;
 
void setup() {
  Serial.begin(9600);
  pinMode(e1,OUTPUT);
  pinMode(e2,OUTPUT);
  pinMode(r1,OUTPUT);   //right motors forward
  pinMode(r2,OUTPUT);   //right motors reverse
  pinMode(l1,OUTPUT);   //left motors forward
  pinMode(l2,OUTPUT);   //left motors reverse
}
 
void loop() {
  if(Serial.available()){
    serial = Serial.read();
  }
  
  if(serial == 1){            //move forward

    digitalWrite(e1,HIGH);
    digitalWrite(e2,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);
  }
  
  else if(serial == 3){      //move reverse 
    digitalWrite(e1,HIGH);
    digitalWrite(r2,HIGH);
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
  }
  
  else if(serial == 2){      //turn right 
    digitalWrite(e1,HIGH);
    digitalWrite(r1,HIGH);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,HIGH);

  }
  
  else if(serial == 4){      //turn left 
    digitalWrite(e2,HIGH);
    digitalWrite(r1,LOW);
    digitalWrite(r2,HIGH);
    digitalWrite(l1,HIGH);
    digitalWrite(l2,LOW);
  }
  
  else if(serial== 0){      //STOP (all motors stop)
    digitalWrite(r1,LOW);
    digitalWrite(r2,LOW);
    digitalWrite(l1,LOW);
    digitalWrite(l2,LOW);
  }
}