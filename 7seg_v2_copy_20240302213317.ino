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

const int reset = 14; 

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
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(digit4, OUTPUT);

  // Set pin as input for the reset button
  pinMode(reset, INPUT);
}

void loop() {
  unsigned long previousMillis = 0;
  const unsigned long interval = 1000; // 1 second interval
  int num = 0; // Initialize the number
  
  while (true) {
    // Check if the reset button is pressed
    if (int(digitalRead(reset)) == HIGH) {
      // Reset the count to zero
      num = 0;
      // // Wait for the button to be released
      // while (int(digitalRead(reset)) == LOW);
    }
    
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

void displayNumber(int num) {
  // Turn off all digits except the first one
  digitalWrite(digit1, HIGH);
  digitalWrite(digit2, HIGH);
  digitalWrite(digit3, HIGH);
  digitalWrite(digit4, LOW);
  
  // Display the corresponding segments for the ones digit
  for (int segment = 0; segment < 7; segment++) {
    digitalWrite(segmentA + segment, numbers[num][segment]);
  }
  
  // Delay for a short duration to allow the digit to be displayed
  delay(100);
  
  // Turn off the digit
  //digitalWrite(digit1, HIGH);
}
