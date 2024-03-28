// https://www.tinkercad.com/things/fW3sE9LRNoG-2-digit-7-segment-display
// https://www.electronics-tutorials.ws/counter/7-segment-display.html
// https://learn.adafruit.com/ninja-timer-giant-7-segment-display?view=all


//a,b,c,d,e,f,g 
byte segValue[10][7] = {
   {0,0,0,0,0,0,1}, //0
   {1,0,0,1,1,1,1}, //1
   {0,0,1,0,0,1,0}, //2
   {0,0,0,0,1,1,0}, //3
   {1,0,0,1,1,0,0}, //4
   {0,1,0,0,1,0,0}, //5
   {0,1,0,0,0,0,0}, //6
   {0,0,0,1,1,1,1}, //7
   {0,0,0,0,0,0,0}, //8
   {0,0,0,0,1,0,0}  //9  
};

byte segPin[8]={2,3,4,5,6,7,8,9}; //{a,b,c,d,e,f,g,dp} 
byte digitPin[2] = {A0,A1}; //segment 

void setup() {
  for(int i=0;i<10;i++){
    pinMode(segPin[i], OUTPUT);
  }
  pinMode(digitPin[0], OUTPUT);
  pinMode(digitPin[1], OUTPUT); 
  digitalWrite(digitPin[0], LOW); 
  digitalWrite(digitPin[1], LOW); 
}

void loop()
{
  for (int i = 0; i<100; i++)
  {
    display_N(i);
    delay(1);
  }
}

void display_N(int num)
{
  // Convierte unidades y decenas
  int und = num % 10;
  int dec = (num % 100) / 10;
  // Refresco dinamico
  for(int i=0; i<100; i++)
  {
    segOutput(1, und, 1);
    segOutput(0, dec, 1);
    delay(2); 
  }
  
  Serial.print(dec);
  Serial.println(und);
}
 
//LED 
void segClear(){ 
  for(int i=0;i<8;i++){
    digitalWrite(segPin[i], HIGH);        
  }
}
//LED 
void segOutput(int d, int Number, int dp){ 
  segClear();
  digitalWrite(digitPin[d], HIGH); 
  for(int i=0;i<7;i++){
     digitalWrite(segPin[i], segValue[Number][i]);        
  }
  digitalWrite(segPin[7], dp);
  delayMicroseconds(1000);
  digitalWrite(digitPin[d], LOW); 
}
