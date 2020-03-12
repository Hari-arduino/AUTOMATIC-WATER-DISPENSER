#define trigger 9
#define echo 8
#define LED 13
#define MOSFET 12
 

 
float time=0,distance=0;
 
void setup()
{
Serial.begin(9600);

 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(MOSFET,OUTPUT);

 delay(2000);
}
 
void loop()
{
 measure_distance();

 if(distance<10)
 {
   digitalWrite(LED,HIGH);digitalWrite(MOSFET,HIGH);
 }
 else
 {
   digitalWrite(LED,LOW);digitalWrite(MOSFET,LOW);
 }

 delay(500);
}

void measure_distance()
{
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 
 distance=time*340/20000;
}
