const int pF=5;
const int pL=4;
const int pR=2;
const int pB=3;
//int inputVal0 = 0;
//int inputVal1 = 0;
//int inputVal2 = 0;ikiuuj
//int inputVal3 = 0;
int processIn = 0;

void setup() 
{                
  pinMode(12, OUTPUT);          // Pin 12 has an LED connected on most Arduino boards:  
  pinMode(pF,INPUT);  //Pin 2 is connected to the output of proximity sensor
  pinMode(pL,INPUT);
  pinMode(pR,INPUT);
  pinMode(pB,INPUT);
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(pF)==LOW)      //Check the sensor output
  {
    digitalWrite(12, HIGH);// set the LED on
    processIn = 1;
    delay(500);
  }
  else if(digitalRead(pL)==LOW)
  { digitalWrite(12,HIGH);
    processIn = 2;
    delay(500);
  }
  else if(digitalRead(pR)==LOW)
  { digitalWrite(12,HIGH);
    processIn = 3;
    delay(500);
  }
  else if(digitalRead(pB)==LOW)
  { digitalWrite(12,HIGH);
    processIn = 4;
    delay(500);
  }
  
  else
  {
    digitalWrite(12, LOW); // set the LED off
    processIn = 0;
  }
//inputVal0 = digitalRead(pF);
//inputVal1 = digitalRead(pL);
//inputVal2 = digitalRead(pR);
//inputVal3 = digitalRead(pB);

Serial.println(processIn);
//Serial.println(inputVal0);
//Serial.println(inputVal1);
//Serial.println(inputVal2);
//Serial.println(inputVal3);
delay(50);              // wait for a second
}
