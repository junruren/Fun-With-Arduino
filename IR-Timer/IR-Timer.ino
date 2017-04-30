/*
 * Filename: IR-Timer.ino
 * Author: Junru Ren
 * Description: Read digital signals from two IR Sensors and use the time 
 *              difference between two signals to calculate the speed of
 *              a moving object.
 * More information: http://tinyurl.com/IR-Timer-Slides
 * Date: Apr 30 2017
 * Credit: www.instructables.com/id/Arduino-IR-Sensor-Timer/
 */
#define PIN_SENSOR_2 3
#define PIN_REFERENCE 13
#define DISTANCE 10
#define SERIAL_PORT_BPS 115200

// reads two IR proximity/line-detectors.  reports time between triggers.
// uses interrupts.  First one should go high for detect on 2
// second detector should go high on detect on pin 3

unsigned long t1=0;
unsigned long t2=0;

void sens1() { 
  if ((t1==0) && (t2==0))
    t1=myMicros();
}

void sens2() {
  if ((t2==0) && (t1!=0))
    t2=myMicros();
}

void setup() {
  pinMode(PIN_SENSOR_1,INPUT);
  pinMode(PIN_SENSOR_2,INPUT);
  pinMode(PIN_REFERENCE,OUTPUT);
  attachInterrupt(0,sens1,RISING);
  attachInterrupt(1,sens2,RISING);
  Serial.begin(SERIAL_PORT_BPS);
  //Serial.begin(57600);
}

void loop() {
  digitalWrite(13,t1?HIGH:LOW);
  if (t2>0)
    {
      double duration_sec = (t2 - t1) / 1000000.0;
      double measuredSpeed = DISTANCE / duration_sec;
      Serial.print("\nSpeed: ");
      printDouble (measuredSpeed, 3);
      Serial.print(" cm/s\n");
      t1=t2=0;
    }
}


//This version may be safer inside an interrupt:
static unsigned long myMicros() {
   extern volatile unsigned long timer0_overflow_count;
   uint8_t oldSREG = SREG;      
   cli();      
   uint32_t t = TCNT0;
   if ((TIFR0 & _BV(TOV0)) && (t == 0))
       t = 256;
   uint32_t m = timer0_overflow_count;
   SREG = oldSREG;
   return ((m << 8) + t) * (64 / clockCyclesPerMicrosecond());
}

/*
 * Credit: http://forum.arduino.cc/index.php?topic=44216.0
 */
void printDouble( double val, byte precision){
 // prints val with number of decimal places determine by precision
 // precision is a number from 0 to 6 indicating the desired decimial places
 // example: printDouble( 3.1415, 2); // prints 3.14 (two decimal places)

 Serial.print (int(val));  //prints the int part
 if( precision > 0) {
   Serial.print("."); // print the decimal point
   unsigned long frac;
   unsigned long mult = 1;
   byte padding = precision -1;
   while(precision--)
      mult *=10;
      
   if(val >= 0)
     frac = (val - int(val)) * mult;
   else
     frac = (int(val)- val ) * mult;
   unsigned long frac1 = frac;
   while( frac1 /= 10 )
     padding--;
   while(  padding--)
     Serial.print("0");
   Serial.print(frac,DEC) ;
 }
}
