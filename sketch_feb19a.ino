const int trig = 8;
const int echo = 7;

const int LED2 = 4;
const int LED1 = 10;

int duration = 0;
int distance = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(LED1 , OUTPUT);
pinMode(LED2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig, HIGH);
delayMicroseconds(1000);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance = (duration/2) / 28.5;

if( distance <= 2){
    digitalWrite(LED1, HIGH);
  }
  else{
    digitalWrite(LED1, LOW);
  }

if( distance >= 3){
    digitalWrite(LED2, HIGH);
  }
  else{
      digitalWrite(LED2, LOW);
    }

Serial.print("Distance: ");
Serial.println(distance);
delay(1000);
}
