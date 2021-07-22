#include <Servo.h>

#include <IRremote.h>

int ir_pin = 0;
int led1 = 8; 
int led2 = 7;
int motor_pin = 9;
long power_button = 16580863L;
IRrecv recv(ir_pin);

void setup () {
  recv.enableIRIn();
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
}

void loop() {
  decode_results results;
  if (recv.decode(&results)) {
    long value = results.value;
    Serial.println(value);
    recv.resume();
    if (value == power_button){
      digitalWrite(motor_pin, HIGH);
      
      for (int i =0; i <5; i++) {
        digitalWrite(led1, HIGH);
        delay(500);
        digitalWrite(led2, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
      } 
    }
  }
  delay (100);
}
