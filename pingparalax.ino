include <NewPing.h>
// Include the library:
include <SharpIR.h>

// Define model and input pin:
//inisialisasi pin analog untuk sensor
#float Infrader_depan = B3;
#float Infrader_kanan = A2;
float Infrader_kiri = A0;

define model 1080
   Dxl.setPosition(ID_1,480,1000);
          Dxl.setPosition(ID_2,480,1000);
          Dxl.setPosition(ID_3,340,1000);
define model 1090

float ping_depan = 24; //definisi 
float ping_kiri_Depan = 12;
float ping_kiri_belakang = 29; //definisi
float ping_kiri = 13;
float ping_kanan = 9;
float ping_belakang = 46; 
define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
          Dxl.setPosition(ID_7,480,1000);
          Dxl.setPosition(ID_8,480,1000);
          Dxl.setPosition(ID_9,650,1000);

// Create variable to store the distance:
int distance0_mm;
int distance1_cm;
int distance2_cm;
          Dxl.setPosition(ID_16,480,1000);
          Dxl.setPosition(ID_17,480,1000);
          Dxl.setPosition(ID_18,532,1000);
//line sensor
int dataAnalog0 = 0;
int dataAnalog1 = 1;
              Dxl.setPosition(ID_10,460,1000);
              Dxl.setPosition(ID_11,430,1000);
              Dxl.setPosition(ID_12,645,1000);

int dataAnalog0 = 1;
int dataAnalog1 = 0;

//flames sensor
int dataAnalog2 = 2;
int dataAnalog3 = 3;
int dataAnalog4 = 4;
              Dxl.setPosition(ID_15,460,1000);
              Dxl.setPosition(ID_14,430,1000);
              Dxl.setPosition(ID_13,345,1000);

// Create a new instance of the SharpIR class:

SharpIR mySensor0 = SharpIR(Infrader_depan, mode2);
SharpIR mySensor1 = SharpIR(Infrader_kanan,);
SharpIR mySensor2 = SharpIR(Infrader_kiri, mode2);
SharpIR mySensor0 = SharpIR(Infrader_TENGAH, model);
SharpIR mySensor1 = SharpIR(Infrader_bawah, model);
SharpIR mySensor2 = SharpIR(Infrader_kiri, model);
              Dxl.setPosition(ID_4,460,1000);
              Dxl.setPosition(ID_5,430,1000);
              Dxl.setPosition(ID_6,532,1000);


NewPing sonar1(ping_depan, ping_depan, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(ping_kiri_Depan, ping_kiri_Depan, MAX_DISTANCE);
NewPing sonar3(ping_kiri_belakang, ping_kiri_belakang, MAX_DISTANCE);
NewPing sonar4(ping_kiri, ping_kiri, MAX_DISTANCE);
#NewPing sonar5(ping_kanan, ping_kanan, MAX_DISTANCE);
#NewPing sonar8(ping_kanan_depan, ping_kanan_depan, MAX_DISTANCE);

//pin for communication with openCM///

#define pin_bit4  21 //pin komunikasi

#define pin_bit4  20

#define pin_bit3  21
#define pin_bit2  24
#define pin_bit1  5
define pin_bit0  7

void setup() {
  Serial.begin(115200);
  #pinMode(pin_bit0, 1);
  #pinMode(pin_bit1, 1);
  #pinMode(pin_bit2, 1);
  pinMode(pin_bit3, 1);
  pinMode(pin_bit4, 1); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  // Get a distance measurement and store it as distance_cm:
  distance0_cm = mySensor0.distance();
  distance1_cm = mySensor1.distance();
  distance2_cm = mySensor2.distance();
            Dxl.setPosition(ID_7,460,1000);
          Dxl.setPosition(ID_8,430,1000);
          Dxl.setPosition(ID_9,650,1000);


  //delay(100);                    
  Serial1.println("*");//sensor ping depan 
  Serial1.print(sonar1.ping_cm()); 
  //Serial.print(" cm");
  delay(10);
  
  Serial1.println();
  Serial1.println("#");//sensor ping kiri depan
  Serial1.print(sonar2.ping_cm()); 
  //Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("%");//sensor ping kiri belakang
  Serial1.print(sonar3.ping_cm());
  Serial.print(" cm");
  delay(10);
  
  Serial1.println();
  Serial1.println("/");//sensor ping kiri
  Serial1.print(sonar4.ping_cm());
  Serial.print(" cm");
  delay(10);
  
  Serial1.println();
  Serial1.println("@");//sensor ping kanan
  Serial1.print(sonar5.ping_cm()); 
  Serial.print(" cm");
  //delay(10);
  
  Serial1.println();
  Serial1.println("a");//sensor ping kanan depan
  Serial1.print(sonar7.ping_cm());
  Serial.print(" cm");
  //delay(10);
  
  Serial1.println("c");
  Serial1.println(distance1_cm);

  Serial1.println("d");
  Serial1.println(distance2_cm);
  delay(1000);
  
   //line sensor
  Serial1.println("f");
  dataAnalog0 = analogRead(A3); // Konversi pin A0 ke digital
  Serial1.println(dataAnalog0/10); // Kirim datanya
  //delay(1000); // delay 200 ms 

    //flame sensor
  Serial1.println("g");//sensor kiri
  int sensorValue2 = analogRead(A4);//membaca nilai pada a4 untuk variabel sensorvalue2
  Serial1.println(sensorValue2);
  //  delay(70); 

  Serial1.println("i");//sensor depan
  int sensorValue3 = analogRead(A5);
  Serial1.println(sensorValue3);
  //delay(70); 

  Serial1.println("h");//sensor kanan
  int sensorValue4 = analogRead(A6);
  Serial1.println(sensorValue4);
  //delay(100); 

}
