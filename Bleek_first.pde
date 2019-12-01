import processing.serial.*;

Serial mySerial;

String myString = null; //a variable to collect serial data
int nl = 10; //ASCII code for carage return in serial
float myVal; //float for storing converted ascii serial data

String[] imageNames = { "Car_top_Back.png" , "Car_top_front.png" , "Car_top_Left.png" , "Car_top_Right.png"};
PImage[] images = new PImage[imageNames.length];
PImage background;

void setup() {
  size(755,619);
  
  background = loadImage("C:\\Users\\Admin\\Desktop\\Car_top.png");
  
  //link processsing to serial port
  String myPort = Serial.list() [0]; //find correct serial port
  mySerial = new Serial(this,myPort, 9600);
  
    //images[0] = loadImage("Car_top.png"); 
    images[0] = loadImage("Car_top_front.png");
    images[1] = loadImage("Car_top_Left.png");
    images[2] = loadImage("Car_top_Right.png");
    images[3] = loadImage("Car_top_Back.png");
    fill(0);
}

void draw() {
  
  background(background);
  frameRate(5);
  
  while (mySerial.available() > 0) {
    myString = mySerial.readStringUntil(nl); //Strips data of serial port
    
    if (myString != null) {
      myVal = float(myString); //takes data from serial and turns it into number
      println(myVal);
      if (int(myVal)==0){
        myVal=0;
      }
      else{
      PImage img = images[int(myVal)-1];
      image(img,15,15);
      //delay(10);
      }
    }
  }
  
  
  
}
  
     
    
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
