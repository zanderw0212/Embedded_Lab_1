#define a 400           //4*100us 

#define b 500           //5*100us 

#define d 3500          //7*500us 

#define inc 50          //50us 

int c = 12;             //8+4 

int NOP = 0;            //used for manipulating the c variable   

const int switch1 = 4;    //switch 1 on pin 4 

const int switch2 = 2;    //switch 2 on pin 5 

const int sigA = 13;       // LED pin on 1 

const int sigB = 12;     // LED pin on 2 

  

//setting up the switches as inputs and LEDs as outputs 

void setup(){ 

  

pinMode(switch1, INPUT); 

pinMode(switch2, INPUT); 

pinMode(sigA, OUTPUT); 

pinMode(sigB, OUTPUT); 

} 

//reading the inputs from the switches 

void loop(){ 

  

  int switch1State = digitalRead(switch1); 

  int switch2State = digitalRead(switch2); 

   

// Condition for mode 1 

if (switch2State == HIGH) { 

  

NOP = c - 3; 

  sigAsigB(); 

} 

//for a normal pulse 

else if (switch1State == LOW){ 

  

  NOP = c; 

  sigAsigB(); 

} 

} 

//begining the LED sequence  

void sigAsigB(){ 

digitalWrite (sigB, HIGH);          //setting the Signal B LED to high 

delay (inc); 

digitalWrite (sigB, LOW);          //Turning off the signal B LED 

for (int i = 0; i<NOP; i++){      //incrementing the pulse by 12 each itteration 

  digitalWrite(sigA, HIGH); 

  delay (a+inc*i);                  //setting the delay to the correct time 

  digitalWrite(sigA, LOW); 

}  

} 

 
