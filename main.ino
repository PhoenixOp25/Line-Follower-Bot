//IR Sensors
int IR1 = 2, IR2 = 4, IR3 = 8, IR4 = 12, IR5 = 13;
//Motors
int Motor1Pin1 = 10, Motor1Pin2 = 11;
int Motor2Pin1 = 5, Motor2Pin2 = 6;
unsigned long mytime,mytime2;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
}

void Left() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 100);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 0);
}

void Straight() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 100);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 115);
}

void Right() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 0);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 115);
}

void Back() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 100);
  analogWrite(Motor2Pin1, 115);
  analogWrite(Motor2Pin2, 0);
}

void SlightLeft() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 100);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 85);
}

void SlightRight() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 70);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 110);
}

void SlightMoreRight() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 60);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 130);
}

void SlightMoreLeft() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 130);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 60);
}

void Stop() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 0);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 0);
}
 void reverse() {
  analogWrite(Motor1Pin1, 100 );
  analogWrite(Motor1Pin2, 0);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 115);
 }

 void ExtremeRight() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 60);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 140);
}

void ExtremeLeft() {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, 130);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, 60);
}
 
void LSRB() {
  int IR1_ = !digitalRead(IR1);
  int IR2_ = !digitalRead(IR2);
  int IR3_ = !digitalRead(IR3);
  int IR4_ = !digitalRead(IR4);
  int IR5_ = !digitalRead(IR5);
  
  if((IR1_ || IR2_ || IR3_ || IR4_ || IR5_)==0) {
    Stop();
    delay(100);
    Left();
  }
  
  else if((IR1_ || IR2_ || IR3_) == 0 && (IR4_ && IR5_) == 1) {
    Serial.print("LEFT\n");
      Left();
  }
  
  else if(IR3_ == 0 && (IR1_ && IR2_ && IR4_ && IR5_) == 1) {
    Serial.print("STRAIGHT\n");
    Straight();
  }
  
  else if((IR1_ && IR2_) == 1 && (IR3_ ||IR4_ || IR5_) == 0) {
    delay(500);
    IR1_ = !digitalRead(IR1);
    IR2_ = !digitalRead(IR2);
    IR3_ = !digitalRead(IR3);
    IR4_ = !digitalRead(IR4);
    IR5_ = !digitalRead(IR5);
    
    if((IR3_ || IR2_|| IR4_) == 0 && (IR1_  && IR5_) == 1) {
      Serial.print("STRAIGHT\n");
      Straight();
    }
    else {
      Serial.print("RIGHT\n");
      while((IR3_  && IR4_ && IR2_)!= 0) {
         reverse();
         IR1_ = !digitalRead(IR1);
         IR2_ = !digitalRead(IR2);
         IR3_ = !digitalRead(IR3);
         IR4_ = !digitalRead(IR4);
         IR5_ = !digitalRead(IR5);
      }
    }
  }
  
  else if((IR1_ && IR2_ && IR3_ && IR4_ && IR5_) == 1) {
    Serial.print("BACK\n");
    delay(500);
    Back();
  }
  
  else if(((IR2_ || IR3_) == 0) && (IR1_ && IR4_ && IR5_) == 1) {
    Serial.print("SLIGHT LEFT\n");
    SlightLeft();
  }
  else if(((IR4_ || IR3_) == 0) && (IR1_ && IR2_ && IR5_) == 1) {
    Serial.print("SLIGHT RIGHT\n");
    SlightRight();
  }
  else if((IR2_) == 0 && (IR1_ && IR3_&& IR4_ && IR5_) == 1) {
    Serial.print("SLIGHT MORE LEFT\n");
    SlightMoreLeft();
  }
  else if((IR4_) == 0 && (IR1_ && IR3_ && IR2_ && IR5_) == 1) {
    Serial.print("SLIGHT MORE RIGHT\n");
    SlightMoreRight();
  }
  
  else if((IR5_) == 0 && (IR1_ && IR3_ && IR2_ && IR4_) == 1) {
    Serial.print("SLIGHT MORE RIGHT\n");
    ExtremeRight();
  }

  else if((IR1_) == 0 && (IR4_ && IR3_ && IR2_ && IR5_) == 1) {
    Serial.print("SLIGHT MORE LEFT\n");
    ExtremeLeft();
  }

  else {
    LSRB();
  }
}

void loop() {
  LSRB();
}
