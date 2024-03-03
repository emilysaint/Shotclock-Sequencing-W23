// Define pins for segments (A-G) of the 4-digit 7-segment display
const int segmentA = 2;
const int segmentB = 3;
const int segmentC = 4;
const int segmentD = 5;
const int segmentE = 6;
const int segmentF = 7;
const int segmentG = 8;
const int segmentDP = 9;

// Define pins for each digit of the 4-digit 7-segment display
const int digit1 = 10;
const int digit2 = 11;
const int digit3 = 12;
const int digit4 = 13;

const int start = 14; 
const int pause = 15;
const int reset = 16;

// Define the truth table for displaying numbers 0 to 9 on the 7-segment display
const byte numbers[][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set segment pins as outputs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(segmentDP, OUTPUT);
  
  // Set digit pins as outputs
  // pinMode(digit1, OUTPUT);
  // pinMode(digit2, OUTPUT);
  // pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  // Set pin 10 as input for the reset button
  pinMode(start, INPUT);
  pinMode(pause, INPUT);
  pinMode(reset, INPUT);

  // // Display the digit zero only on the fourth digit
  // displayDigitZeroOnFourthDigit();
}

// void displayDigitZeroOnFourthDigit() {
//   // Turn on the required segments to display zero
//   digitalWrite(2, HIGH);
//   digitalWrite(3, HIGH);
//   digitalWrite(4, HIGH);
//   digitalWrite(5, HIGH);
//   digitalWrite(6, HIGH);
//   digitalWrite(7, HIGH);
//   digitalWrite(8, LOW);  // Segment G off
  
//   // // Activate the fourth digit
//   // digitalWrite(DIGIT_1, LOW);
//   // digitalWrite(DIGIT_2, LOW);
//   // digitalWrite(DIGIT_3, LOW);
//   // digitalWrite(DIGIT_4, HIGH);  // Fourth digit activated
// }

void loop() {
  unsigned long previousMillis = 0;
  const unsigned long interval = 1000; // 1 second interval
  int num = 0; // Initialize the number
  bool paused = false;

  while (true) {
    // Check if the reset button is pressed
    if (digitalRead(reset) == HIGH) {
      // Reset the count to zero
      num = 0;
    } else if (digitalRead(pause) == HIGH) {
      paused = true;
      if (digitalRead(reset) == HIGH) {
        num = 0;
        // displayDigitZeroOnFourthDigit(); 
      } 
      while (digitalRead(start) == HIGH){
        delay (1);
      }
    } else if (digitalRead(start) == HIGH) {
      paused = false;
    }

    if (!paused) {
      // Display the number on the 4-digit 7-segment display
      displayNumber(num);

      // Wait for exactly one second
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        num++; // Increment the number
        if (num > 9) {
          num = 0; // Reset the count if it reaches 10
        }
      }
    }
  }
}

void displayNumber(int num) {
  // Display the corresponding segments for the ones digit
  for (int digit = 3; digit <= 4; digit++) {
    // Turn off all digits
    // digitalWrite(digit1, digit != 1 ? HIGH : LOW);
    // digitalWrite(digit2, digit != 2 ? HIGH : LOW);
    // digitalWrite(digit3, digit != 3 ? HIGH : LOW);
    digitalWrite(digit4, digit != 4 ? HIGH : LOW);

    // Display the corresponding segments for the current digit
    for (int segment = 0; segment < 7; segment++) {
      // digitalWrite(segmentA + segment, numbers[num][segment]);
      digitalWrite(segmentA + segment, numbers[num][segment]);
    }

    // Delay for a short duration to allow the digit to be displayed
    delay(5);
  }
}
