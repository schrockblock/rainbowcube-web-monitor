/*
 Rainbowduino v3.0 Library examples:

 Sets pixels on 2D plane (8x8 matrix)

*/

#include <Rainbowduino.h>

void setup()
{
  Rb.init();
  Serial.begin(9600);
}

unsigned char x,y,z;
char led = '1';
char value = 0;
boolean shouldUpdate = false;
int location = -1;

char statuses[4][4];

void loop()
{
    while (Serial.available() > 0) {
      parseLocation(Serial.read());
      while (Serial.available() == 0){
        delay(1);
      }
      statuses[x][y] = Serial.read();
    }
    
    if (statuses[2][1] != 0){
      setStatuses();
      
      resetStatuses();
    }
}

void setStatuses(){
  for (int j = 0; j<4; j++){
    for (int i = 0; i<4; i++){
      Rb.setPixelZXY(j,i,3,0);
      Rb.setPixelZXY(j,i,2,0);
      Rb.setPixelZXY(j,i,1,0);
      Rb.setPixelZXY(j,i,0,0);
      switch (statuses[i][j]){
        case 'a':
          Rb.setPixelZXY(j,i,3,0x00FF00);
          break;
        case 'b':
          Rb.setPixelZXY(j,i,3,0x00FF00);
          Rb.setPixelZXY(j,i,2,0x00FF00);
          break;
        case 'c':
          Rb.setPixelZXY(j,i,3,0xFFFF00);
          Rb.setPixelZXY(j,i,2,0xFFFF00);
          Rb.setPixelZXY(j,i,1,0xFFFF00);
          break;
        case 'd':
          Rb.setPixelZXY(j,i,3,0xFF0000);
          Rb.setPixelZXY(j,i,2,0xFF0000);
          Rb.setPixelZXY(j,i,1,0xFF0000);
          Rb.setPixelZXY(j,i,0,0xFF0000);
          break;
      }
    }
  }
}

void resetStatuses(){
  for (int i = 0; i<4; i++){
    for (int j = 0; j<4; j++){
      statuses[i][j] = 0;
    }
  }
}

void parseLocation(int led){
  switch (led){
    case 'a':
      x = 0;
      y = 0;
      break;
    case 'b':
      x = 1;
      y = 0;
      break;
    case 'c':
      x = 2;
      y = 0;
      break;
    case 'd':
      x = 3;
      y = 0;
      break;
    case 'e':
      x = 0;
      y = 1;
      break;
    case 'f':
      x = 1;
      y = 1;
      break;
    case 'g':
      x = 2;
      y = 1;
      break;
    case 'h':
      x = 3;
      y = 1;
      break;
    case 'i':
      x = 0;
      y = 2;
      break;
    case 'j':
      x = 1;
      y = 2;
      break;
    case 'k':
      x = 2;
      y = 2;
      break;
    case 'l':
      x = 3;
      y = 2;
      break;
    case 'm':
      x = 0;
      y = 3;
      break;
    case 'n':
      x = 1;
      y = 3;
      break;
    case 'o':
      x = 2;
      y = 3;
      break;
    case 'p':
      x = 3;
      y = 3;
      break;
  }
}




