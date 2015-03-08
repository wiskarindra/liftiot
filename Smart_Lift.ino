// Konfigurasi Dual 7-Segment
int A = 4;
int B = 5;
int C = 10;
int D = 9;
int E = 8;
int F = 2;
int G = 3;
int C1 = 6;
int C2 = 7;
static int segs[7] = {A, B, C, D, E, F, G};
static byte numbers[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010, 0b1111000, 0b0000000, 0b0010000};

// Konfigurasi Button
int Button1 = 11;
int target = 1;
int digit1 = 0;
int flagButton1 = 0;

Lift lift = Lift();

void setup() {
  // Konfigurasi Dual 7-Segment
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(Button1, INPUT);
  pinMode(12, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {  
//======kodingan farhan=====//
  
//======kodingan farhan=====//
//  for(int digit2=1; digit2<5; digit2++) {
//    unsigned long startTime = millis();
//    for(unsigned long elapsed=0; elapsed < 1000; elapsed = millis() - startTime) {
//      int buttonState = digitalRead(Button1);
//      lightDigit1(numbers[digit1]);
//      delay(5);
//      lightDigit2(numbers[digit2]);
//      delay(5);
//    }
//  }
//  for(int digit2=5; digit2>0; digit2--) {
//    unsigned long startTime = millis();
//    for(unsigned long elapsed=0; elapsed < 1000; elapsed = millis() - startTime) {
//      lightDigit1(numbers[digit1]);
//      delay(5);
//      lightDigit2(numbers[digit2]);
//      delay(5);
//    }
//  }
  int buttonState = digitalRead(Button1);
  if(buttonState == HIGH && flagButton1 == 0) {
    if(target == 1) {
      target = 5;
    }
    else {
      target = 1; 
    }
  }
  else if(buttonState == LOW && flagButton1 == 1) {
    flagButton1 = 0;
  }
  lift.update(); 
}

void lightDigit1(byte number) {
  digitalWrite(C1, HIGH);
  digitalWrite(C2, LOW);
  lightSegments(number);
}

void lightDigit2(byte number) {
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  lightSegments(number);
}

void lightSegments(byte number) {
  for (int i = 0; i < 7; i++) {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
  }
}
