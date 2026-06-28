#Sasidu Wishshanka(*Sasidu-Tech)

#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(A0, A1); // RX, TX


AF_DCMotor r1 (1);
AF_DCMotor r2 (2);
AF_DCMotor r3 (3);
AF_DCMotor r4 (4);


void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600);
  BT.begin(9600);

  r1.setSpeed(200);
  r2.setSpeed(200);
  r3.setSpeed(200);
  r4.setSpeed(200);

}

void loop() {
  // put your main code here, to run repeatedly:

if (BT.available()) {
    char command = BT.read();
    Serial.print(command);

  if(command == 'f') forward();
  else if(command == 'b') backward();
  else if(command == 'l') left();
  else if(command == 'r') right();
  else if(command == 's') stop();

  }
}



  void forward() {

    r1.run(FORWARD);
    r2.run(FORWARD);
    r3.run(FORWARD);
    r4.run(FORWARD);
  }

  void backward() {

    r1.run(BACKWARD);
    r2.run(BACKWARD);
    r3.run(BACKWARD);
    r4.run(BACKWARD);
  }

  void left() {
  r1.run(BACKWARD);
  r2.run(FORWARD);

  r3.run(BACKWARD);
  r4.run(FORWARD);
}

 void right() {
  r1.run(FORWARD);
  r2.run(BACKWARD);

  r3.run(FORWARD);
  r4.run(BACKWARD);
}
 
 void stop() {
  r1.run(RELEASE);
  r2.run(RELEASE);
  r3.run(RELEASE);
  r4.run(RELEASE);
}
```

  




