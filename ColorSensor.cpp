#include "Arduino.h"
#include "ColorSensor.h"

ColorSensor::ColorSensor(int s0, int s1, int s2, int s3, int out, int led){
	int colinstall[6][3]={{0,0,0},
                      {0,0,0},
                      {0,0,0},
                      {0,0,0},
                      {0,0,0},
                      {0,0,0}};
    int col[3]={0};
	_s0=s0;
	_s1=s1;
	_s2=s2;
	_s3=s3;
	_out=out;
	_led=led;
	pinMode(_s0, OUTPUT);
  	pinMode(_s1, OUTPUT);
  	pinMode(_s2, OUTPUT);
 	pinMode(_s3, OUTPUT);
 	pinMode(_out, INPUT);
 	pinMode(_led, OUTPUT);
	digitalWrite(_led, HIGH);
	digitalWrite(_s0,HIGH);
  	digitalWrite(_s1,HIGH);
}

void ColorSensor::setUnits(int arr[6][3]){
	for(i=0;i<6;i++){
		for(j=0;j<3;j++){
			colinstall[i][j]=arr[i][j];
		}
	}
}

int ColorSensor::colorread(){
	digitalWrite(_s2,LOW);
	digitalWrite(_s3,LOW);
  	col[0] = pulseIn(_out, LOW);
  delay(100);
  
  digitalWrite(_s2,HIGH);
  digitalWrite(_s3,HIGH);
  col[1] = pulseIn(_out, LOW);
  delay(100);
  
  digitalWrite(_s2,LOW);
  digitalWrite(_s3,HIGH);
  col[2] = pulseIn(_out, LOW);
  delay(100);
 
  digitalWrite(_s2,HIGH);
  digitalWrite(_s3,LOW);
  clears = pulseIn(_out, LOW);
  
  col[0]/=clears;
  col[1]/=clears;
  col[2]/=clears;
  
  currentcolor=-1;
  for(b=0;b<6;b++){
    if(	((col[0]==(colinstall[b][0]%10))||(col[0]==(colinstall[b][0]/10)))	&&	((col[1]==(colinstall[b][1]%10))||(col[1]==(colinstall[b][0]/10)))	&& ((col[2]==(colinstall[b][2]%10))||(col[2]==(colinstall[b][2]/10)))){
      currentcolor= b;
      break;
    }
  }
return currentcolor;
}
