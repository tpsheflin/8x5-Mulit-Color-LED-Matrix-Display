//
//  Title: 8 x 5 Multi-Color LED Matrix Display Code, Arduino, (no other chips required).
//  Author: T. Sheflin
//  Date: 12/22/2021
//  Initial code starting point from https://hackaday.io/project/177165 "LED Chaser Circuits Using IC4017 and Arduino"
//  Heavily modified to drive LED Matrix, used chaser code to pulse display rows high one at a time (like a johnson counter or IC4017)
//  Code displays image bitmaps on LED Matrix Display
//  Code and circuit posted to https://github.com/tpsheflin/8x5-Multi-Color-LED-Matrix-Display
//  LED Matrix: CSM-58261EG-21, (Data Sheet for CSM-58261EG used)
//  HW: Arduino-UNO, 10 390 Ohm resistors and 36 jumper wires
//  

//Define Arduino pins for connection to matrix display
//LED anodes
int ROW_1  = 2; 
int ROW_2  = 3;
int ROW_3  = 4;
int ROW_4  = 5;
int ROW_5  = 6;
int ROW_6  = 7;
int ROW_7  = 8;
int ROW_8  = 9;
//Red LED cathodes
int COL_1_R  = 1; 
int COL_2_R  = 10; 
int COL_3_R  = 11; 
int COL_4_R  = 12; 
int COL_5_R  = 13; 
//Green LED cathodes
int COL_1_G  = 14; 
int COL_2_G  = 15; 
int COL_3_G  = 16; 
int COL_4_G  = 17; 
int COL_5_G  = 18; 

//counters for rows and columns of matrix display
int CTR_R  = 1;
int CTR_C  = 1;
int CTR_D  = 1;

void setup() {
   // initialize pins as output
   pinMode(ROW_1,  OUTPUT);
   pinMode(ROW_2,  OUTPUT);
   pinMode(ROW_3,  OUTPUT);
   pinMode(ROW_4,  OUTPUT);
   pinMode(ROW_5,  OUTPUT);
   pinMode(ROW_6,  OUTPUT);
   pinMode(ROW_7,  OUTPUT);
   pinMode(ROW_8,  OUTPUT);

   pinMode(COL_1_R,  OUTPUT);
   pinMode(COL_2_R,  OUTPUT);
   pinMode(COL_3_R,  OUTPUT);
   pinMode(COL_4_R,  OUTPUT);
   pinMode(COL_5_R,  OUTPUT);

   pinMode(COL_1_G,  OUTPUT);
   pinMode(COL_2_G,  OUTPUT);
   pinMode(COL_3_G,  OUTPUT);
   pinMode(COL_4_G,  OUTPUT);
   pinMode(COL_5_G,  OUTPUT);
}

void loop() {
  if (CTR_D < 504){
    Turn_them_all_off();
    COL_LOAD_1();           //load led display column data
    ROW_Forward_Pulse();    //pulse led display row 
    delay(2);               //stay lit for 2 ms, total time to update whole display must be less than 20ms to get no flicker, 8x2ms=16ms, so ok!
  }
  else if (CTR_D >= 504 && CTR_D < 1008){
    Turn_them_all_off();
    COL_LOAD_2();
    ROW_Forward_Pulse();
    delay(2);
  }
  else if (CTR_D >= 1008 && CTR_D < 1512){
    Turn_them_all_off();
    COL_LOAD_3();
    ROW_Forward_Pulse();
    delay(2);
  }
  else{
    Turn_them_all_off();
    COL_LOAD_4();
    ROW_Forward_Pulse();
    delay(2);
  }
  CTR_D++;      //counter to loop and change images
  if (CTR_D > 2016) CTR_D=0;    //values multiple of 8 so display doesn't stop updating in the middle
}

void ROW_Forward_Pulse(){
   switch (CTR_R) {
    case 1 : digitalWrite(ROW_1,  HIGH); CTR_R++; break; //set row pin high and increment counter
    case 2 : digitalWrite(ROW_2,  HIGH); CTR_R++; break;
    case 3 : digitalWrite(ROW_3,  HIGH); CTR_R++; break;
    case 4 : digitalWrite(ROW_4,  HIGH); CTR_R++; break;
    case 5 : digitalWrite(ROW_5,  HIGH); CTR_R++; break;
    case 6 : digitalWrite(ROW_6,  HIGH); CTR_R++; break;
    case 7 : digitalWrite(ROW_7,  HIGH); CTR_R++; break;
    case 8 : digitalWrite(ROW_8,  HIGH); CTR_R=1; break; //Reset the counter to start from the begining
   };
}
                    //column bit map to image, LOW here turns led on, enabling both leds in a column makes amber
void COL_LOAD_1(){  //Image 1, Christmas Tree Red Star
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 2 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 3 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 5 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 7 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 8 : digitalWrite(COL_1_R,  LOW); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  LOW);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH);  CTR_C=1; break;
  };
}

void COL_LOAD_2(){    //Image 2, Christmas Tree Amber Star
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH);  digitalWrite(COL_2_G,  HIGH); digitalWrite(COL_3_G,  LOW);  digitalWrite(COL_4_G,  HIGH); digitalWrite(COL_5_G,  HIGH);  CTR_C++; break;
            
   case 2 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH);  digitalWrite(COL_2_G,  HIGH); digitalWrite(COL_3_G,  LOW);  digitalWrite(COL_4_G,  HIGH); digitalWrite(COL_5_G,  HIGH);  CTR_C++; break;
            
   case 3 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 5 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 7 : digitalWrite(COL_1_R,  HIGH);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 8 : digitalWrite(COL_1_R,  LOW); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  LOW);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH);  CTR_C=1; break;  
    
  };
}


void COL_LOAD_3(){    //Image 3, Present with ribbon and bow
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 2 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 3 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 5 : digitalWrite(COL_1_R,  LOW); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  LOW); digitalWrite(COL_5_R,  LOW);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 7 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 8 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH);  CTR_C=1; break;
  };
}

void COL_LOAD_4(){    //Image 4, Present with ribbon and bow
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 2 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 3 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 5 : digitalWrite(COL_1_R,  LOW); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  LOW); digitalWrite(COL_5_R,  LOW);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 7 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 8 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH);  CTR_C=1; break;
  };
}


void Turn_them_all_off(){
   digitalWrite(ROW_1,  LOW);         //Anode side
   digitalWrite(ROW_2,  LOW);
   digitalWrite(ROW_3,  LOW);
   digitalWrite(ROW_4,  LOW);
   digitalWrite(ROW_5,  LOW);
   digitalWrite(ROW_6,  LOW);
   digitalWrite(ROW_7,  LOW);
   digitalWrite(ROW_8,  LOW);
   
   digitalWrite(COL_1_R,  HIGH);      //Cathode side
   digitalWrite(COL_2_R,  HIGH);
   digitalWrite(COL_3_R,  HIGH);
   digitalWrite(COL_4_R,  HIGH);
   digitalWrite(COL_5_R,  HIGH);
   
   digitalWrite(COL_1_G,  HIGH);      //Cathode side
   digitalWrite(COL_2_G,  HIGH);
   digitalWrite(COL_3_G,  HIGH);
   digitalWrite(COL_4_G,  HIGH);
   digitalWrite(COL_5_G,  HIGH);
   
   //delayMicroseconds(500);
}


/*
void COL_LOAD_1(){    //First time writing to display, checker board pattern, red
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   case 2 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 3 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 5 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 7 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 8 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C=1; break;
  };
}

void COL_LOAD_2(){    //First attempt at multi color
  switch (CTR_C){
   case 1 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW);  digitalWrite(COL_2_G,  HIGH); digitalWrite(COL_3_G,  LOW);  digitalWrite(COL_4_G,  HIGH); digitalWrite(COL_5_G,  LOW);  CTR_C++; break;
   case 2 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 3 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 4 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 5 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 6 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C++; break;
   case 7 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  LOW);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  LOW);  digitalWrite(COL_5_R,  HIGH); CTR_C++; break;
   case 8 : digitalWrite(COL_1_R,  LOW);  digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  LOW);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  LOW);  CTR_C=1; break;   
  };
}
   //Christmas tree bulb decoration 
   case 1 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH);  digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 2 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  LOW); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
            
   case 3 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH); digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW);  digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 4 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 5 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW);  digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
            
   case 6 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  LOW); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  LOW); CTR_C++; break;
   
   case 7 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH);  digitalWrite(COL_4_R,  HIGH); digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  LOW);  digitalWrite(COL_3_G,  LOW); digitalWrite(COL_4_G,  LOW);  digitalWrite(COL_5_G,  HIGH); CTR_C++; break;
   
   case 8 : digitalWrite(COL_1_R,  HIGH); digitalWrite(COL_2_R,  HIGH);  digitalWrite(COL_3_R,  HIGH); digitalWrite(COL_4_R,  HIGH);  digitalWrite(COL_5_R,  HIGH);
            digitalWrite(COL_1_G,  HIGH); digitalWrite(COL_2_G,  HIGH);  digitalWrite(COL_3_G,  HIGH); digitalWrite(COL_4_G,  HIGH);  digitalWrite(COL_5_G,  HIGH);  CTR_C=1; break;

*/
