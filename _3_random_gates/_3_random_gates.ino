//3 random gates
//
//3 random channel.
int random1;
int random1out = 4;
int random2;
int random2out = 5;
int random3;
int random3out = 6;
//
//random level cv control pins.
int pot1pin = A1;
int pot2pin = A2;
int pot3pin = A3;
//
//output pins.
int outfor2pin = 11;
int outfor3pin = 12;
int logicgate = 1;
//
//input pins.
int clockpin = 3;


void setup() {
  pinMode(random1out , OUTPUT);
  pinMode(random2out , OUTPUT);
  pinMode(random3out , OUTPUT);
  pinMode(outfor2pin, OUTPUT);
  pinMode(outfor3pin, OUTPUT);
  pinMode(clockpin, INPUT);
  pinMode(logicgate, INPUT);
  pinMode(gate_or_trigger, INPUT);
  attachInterrupt(digitalPinToInterrupt(clockpin), logicout , RISING);
}

void loop() {
  //random level setting.
  //use a potentiometer to control the gate-out possibility on every random channel.
  if (map(random(analogRead(pot1pin)), 0, 1024, 1, 32) == 1) {
    random1 == 1;
  } else {
    random1 == 0;
  };
  if (map(random(analogRead(pot2pin)), 0, 1024, 1, 32) == 1) {
    random2 == 1;
  } else {
    random2 == 0;
  };
  if (map(random(analogRead(pot3pin)), 0, 1024, 1, 32) == 1) {
    random3 == 1;
  } else {
    random3 == 0;
  };
}

void logicout() {
  digitalWrite(random1out, random1);
  digitalWrite(random2out, random2);
  digitalWrite(random3out, random3);
  //AND gate.
  if (logicgate = LOW) {
    if (random1 == random2 || random1 == random3 || random2 == random3) {
      digitalWrite(outfor2pin, HIGH);
    }
    if (random1 == random2 == random3) {
      digitalWrite(outfor3pin, HIGH);
    }
    //XAND gate.
  } else {
    if (random1 != random2 || random1 != random3 || random2 != random3) {
      digitalWrite(outfor2pin, HIGH);
    }
    if (random1 != random2 != random3) {
      digitalWrite(outfor3pin, HIGH);
    }
  }
}

