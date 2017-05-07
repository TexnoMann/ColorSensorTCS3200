/*     Arduino Color Sensing Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
 
#define S0 3
#define S1 2
#define S2 15
#define S3 18
#define sensorOut 14
int green=0;
int blue=0;
int red= 0;
int col[3]={0};
int clears=0;
int colinstall[6][3]={{1,3,2},
                      {1,2,2},
                      {2,1,2},
                      {2,2,1},
                      {2,3,2},
                      {1,2,3}};
int colorsum[6]={0};



void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,HIGH);
  
  Serial.begin(9600);
}
void loop() {
colorread();
switch(coldetect()){
  case 0: Serial.println("red"); break;
  case 1: Serial.println("white"); break;
  case 2: Serial.println("green"); break;
  case 3: Serial.println("blue"); break;
  case 4: Serial.println("black"); break;
  case 5: Serial.println("yellow"); break;
}
delay(1000);
}

void colorread(){
// Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  red = pulseIn(sensorOut, LOW);

  delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  green = pulseIn(sensorOut, LOW);

  delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  blue = pulseIn(sensorOut, LOW);
  
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  clears = pulseIn(sensorOut, LOW);



  delay(100);
  col[0]=red/clears;
  col[1]=green/clears;
  col[2]=blue/clears;
  for(int i=0;i<3;i++) {
    Serial.print(col[i]);
    Serial.print(" ");
  }
  Serial.println();
}

int coldetect(){
  int currentcolor=-1;
  for(int b=0;b<6;b++){
    if(col[0]==colinstall[b][0]&&col[1]==colinstall[b][1]&&col[2]==colinstall[b][2]){
      currentcolor= b;
      break;
    }
  }
return currentcolor;
}

  
