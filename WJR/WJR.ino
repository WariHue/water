#include <Arduino.h>  //아두이노의 기본적인 라이브러리 포함하기
#include <TM1637Display.h>
#include <Keypad.h>
#define CLK 12
#define DIO 13
#define DELAY 1000  //딜레이 설정값입니다.
TM1637Display display(CLK, DIO);
int a = a;
int b = 9;
int c = 9;
int d = 9;

int cnt = 0;
char h = '0';

const byte rows = 4; //four rows
const byte cols = 4;
byte rowPins[rows] = {9,8,7,6};
byte colPins[cols] = {5,4,3,2};

char f = '0';
char g = '0';
char y = '0';
char j = '0';

String as = "0";
String bs = "0";
String cs = "0";
String ds = "0";

char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

const uint8_t SEG_NONO[]={
  
SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_E | SEG_F,
SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,
};

const uint8_t SEG_YES[]={
  
SEG_B | SEG_C | SEG_F | SEG_G,
SEG_A | SEG_D | SEG_E | SEG_F | SEG_G,
SEG_A | SEG_C | SEG_D | SEG_F | SEG_G,
SEG_C | SEG_D | SEG_E,
};
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup()
{
  uint8_t data[] = {0x0, 0x0, 0x0, 0x0}; 
  display.setSegments(data);  
  display.setBrightness(7); //밝기는 가장 강하게
}

void loop()
{
as=f;
bs=g;
cs=y;
ds=j;

String all = as+bs+cs+ds;
char key = keypad.getKey();
if(isDigit(key)){
  if (key != NO_KEY){
  switch (cnt){
    case 0:
      f = key;
      as=f;
      bs=g;
      cs=y;
      ds=j;
      cnt++;
      break;
   case 1:
      g = key;
      as=f;
      bs=g;
      cs=y;
      ds=j;
      cnt++;
      break;
   case 2:
      y = key;
      as=f;
      bs=g;
      cs=y;
      ds=j;
      cnt++;
      break;
   case 3:
      j = key;
      as=f;
      bs=g;
      cs=y;
      ds=j;
      cnt = 0;
      all = as+bs+cs+ds;
      int data = all.toInt();
      display.showNumberDec(data,true);
      delay(1000);
      if(data == 2428)
        display.setSegments(SEG_YES);
      else
        display.setSegments(SEG_NONO);
      delay(1000);
      f = '0';
      g = '0';
      y = '0';
      j = '0';
      as=f;
      bs=g;
      cs=y;
      ds=j;
      
      break;
  }
}
}
 


all = as+bs+cs+ds;
int data = all.toInt();
display.showNumberDec(data,true);
delay(100);
}
