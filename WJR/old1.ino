#include <Keypad.h>
#include <TM1637Display.h>
#define CLK 12
#define DIO 13

const byte rows = 4; //four rows
const byte cols = 4; //four columns
int aa = 0;
int bb = 0;
 
byte rowPins[rows] = {9,8,7,6};
byte colPins[cols] = {5,4,3,2};

const uint8_t SEG_nal[]={

SEG_G,
SEG_G,
SEG_G,
SEG_G,
};


const uint8_t SEG_2[]={

SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_G,
SEG_G,
SEG_G,
};


const uint8_t SEG_24[]={

SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_B | SEG_C | SEG_F | SEG_G,
SEG_G,
SEG_G,
};


const uint8_t SEG_242[]={

SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_B | SEG_C | SEG_F | SEG_G,
SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_G,
};


const uint8_t SEG_2428[]={
  
SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_B | SEG_C | SEG_F | SEG_G,
SEG_A | SEG_B | SEG_D | SEG_E | SEG_G,
SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G,
};

const uint8_t SEG_YES[]={
  
SEG_B | SEG_C | SEG_F | SEG_G,
SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
SEG_A | SEG_C | SEG_D | SEG_F | SEG_G,
SEG_C | SEG_D | SEG_E,
};

const uint8_t SEG_NONO[]={
  
SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
};

 
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
TM1637Display dsp(CLK, DIO);
 
void setup(){
  Serial.begin(9600);  
  pinMode(13, OUTPUT);
  dsp.setBrightness(7);
}
 
void loop(){
   
   char key = keypad.getKey();
   char a = '2';
   char b = '4';
   char c = '2';
   char d = '8';
 
   if (key != NO_KEY){      //키값이 눌렀는지 확인문
      switch (aa){
        case 0:
          if(key == a){
            aa++;
            dsp.setSegments(SEG_2);
            break; 
          }else{
            aa = 0;
            dsp.setSegments(SEG_NONO);
            delay(2000);
            dsp.setSegments(SEG_nal);
            break;
          }
       case 1:
          if(key == b){
            aa++;
            dsp.setSegments(SEG_24);
            break; 
          }else{
            aa = 0;
            dsp.setSegments(SEG_NONO);
            delay(2000);
            dsp.setSegments(SEG_nal);
            break;
          }
       case 2:
          if(key == c){
            aa++;
            dsp.setSegments(SEG_242);
            break; 
          }else{
            aa = 0;
            dsp.setSegments(SEG_NONO);
            delay(2000);
            dsp.setSegments(SEG_nal);
            break;
          }
       case 3:
          if(key == d){
            dsp.setSegments(SEG_YES);
            delay(2000);
            dsp.setSegments(SEG_nal);
            aa = 0;
          }else{
            aa = 0;
            dsp.setSegments(SEG_NONO);
            delay(2000);
            dsp.setSegments(SEG_nal);
            break;
          }
       default:
         
          break;
          }
      }
}
