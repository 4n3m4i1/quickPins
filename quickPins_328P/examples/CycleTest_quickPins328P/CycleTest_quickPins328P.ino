/*  Test for quickPins speed vs. standard library
 * 
 *  Run this program with nothing connected to GPIO as random pins will rapidly change state.
 *  
 *  2022 @4n3m4i1
 */
#include "quickPins_328P.h"

#define TEST_PIN 13

#define ARR_LEN 20

void setup() {
  TCCR0A = 0x00;      // Timer 0 standard run mode (0-255)
  TCCR0B = 0x01;      // No prescalar, 16.00 MHz internal clk coupled to timer

  Serial.begin(115200);

  uint8_t offset = 0;

  uint8_t cycle_ct[ARR_LEN] = {0};

  TCNT0 = 0x00;
  cycle_ct[0] = TCNT0;
  offset = cycle_ct[0];
  
  /* Start Functions To Measure */
  // Testing with constant pin numbers
  TCNT0 = 0x00;
  pinMode(TEST_PIN, OUTPUT);
  cycle_ct[0] = TCNT0 - offset;

  quickMode(TEST_PIN, INPUT);       // Reset DDRn to 0
  
  TCNT0 = 0x00;
  quickMode(TEST_PIN, OUTPUT);
  cycle_ct[1] = TCNT0 - offset;

  TCNT0 = 0x00;
  digitalWrite(TEST_PIN, HIGH);
  cycle_ct[2] = TCNT0 - offset;

  quickWrite(TEST_PIN, LOW);        // Reset PORTn to 0

  TCNT0 = 0x00;
  quickWrite(TEST_PIN, HIGH);
  cycle_ct[3] = TCNT0 - offset;

  TCNT0 = 0x00;
  digitalWrite(TEST_PIN, LOW);
  cycle_ct[4] = TCNT0 - offset;

  quickWrite(TEST_PIN, HIGH);       // Reset PORTn to 1

  TCNT0 = 0x00;
  quickWrite(TEST_PIN, LOW);
  cycle_ct[5] = TCNT0 - offset;

  TCNT0 = 0x00;

  quickToggle(TEST_PIN);              // Toggle LOW to HIGH
  cycle_ct[6] = TCNT0 - offset;

  TCNT0 = 0x00;

  quickToggle(TEST_PIN);              // Toggle HIGH to LOW
  cycle_ct[7] = TCNT0 - offset;

  

  // Testing with variable pin numbers
  randomSeed(analogRead(0));
  uint8_t temp = random(20);    // Pick a pin between 0-19 ( 0 - A5 )
  
  TCNT0 = 0x00;
  pinMode(temp, OUTPUT);
  cycle_ct[8] = TCNT0 - offset;

  quickMode(temp, INPUT);       // Reset DDRn to 0
  
  TCNT0 = 0x00;
  quickMode(temp, OUTPUT);
  cycle_ct[9] = TCNT0 - offset;

  TCNT0 = 0x00;
  digitalWrite(temp, HIGH);
  cycle_ct[10] = TCNT0 - offset;

  quickWrite(temp, LOW);        // Reset PORTn to 0

  TCNT0 = 0x00;
  quickWrite(temp, HIGH);
  cycle_ct[11] = TCNT0 - offset;

  TCNT0 = 0x00;
  digitalWrite(temp, LOW);
  cycle_ct[12] = TCNT0 - offset;

  quickWrite(temp, HIGH);       // Reset PORTn to 1

  TCNT0 = 0x00;
  quickWrite(temp, LOW);
  cycle_ct[13] = TCNT0 - offset;

  TCNT0 = 0x00;

  quickToggle(temp);            // Toggle LOW to HIGH
  cycle_ct[14] = TCNT0 - offset;

  TCNT0 = 0x00;

  quickToggle(temp);            // Toggle HIGH to LOW
  cycle_ct[15] = TCNT0 - offset;



  // Testing with variable pin AND variable state to be added later

  // Bitwise pure test
  quickWrite(TEST_PIN, LOW);

  TCNT0 = 0x00;
  DDRD = 0x01;
  cycle_ct[16] = TCNT0 - offset;
  
  TCNT0 = 0x00;
  PORTD = 0x01;
  cycle_ct[17] = TCNT0 - offset;

  TCNT0 = 0x00;
  PIND = 0x01;
  cycle_ct[18] = TCNT0 - offset;

  TCNT0 = 0x00;
  bitwise_F_test();
  cycle_ct[19] = TCNT0 - offset;
  
  /* End Functions To Measure */
  printResults(cycle_ct, &offset, &temp);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void printResults(uint8_t *array_S, uint8_t *save_offset, uint8_t *v_pin){
  Serial.print("Array Save Offset: ");
  Serial.print(*save_offset);
  Serial.println(" cycles");

  Serial.println();
  
  Serial.println("Fixed Pin Number Results:");
  
  Serial.print("\tpinMode(): ");
  Serial.print(array_S[0]);
  Serial.println(" clock cycles");
  Serial.print("\tquickMode(): ");
  Serial.print(array_S[1]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[1] / (float)array_S[0]) * 100.f );

  Serial.println();
  
  Serial.print("\tdigitalWrite(HIGH): ");
  Serial.print(array_S[2]);
  Serial.println(" clock cycles");
  Serial.print("\tquickWrite(HIGH): ");
  Serial.print(array_S[3]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[3] / (float)array_S[2]) * 100.f );

  Serial.println();
  
  Serial.print("\tdigitalWrite(LOW): ");
  Serial.print(array_S[4]);
  Serial.println(" clock cycles");
  Serial.print("\tquickWrite(LOW): ");
  Serial.print(array_S[5]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[5] / (float)array_S[4]) * 100.f );

  Serial.println();

  Serial.print("\tquickToggle(LOW->HIGH): ");
  Serial.print(array_S[6]);
  Serial.println(" clock cycles");
  Serial.print("\tquickToggle(HIGH->LOW): ");
  Serial.print(array_S[7]);
  Serial.println(" clock cycles");

  Serial.println();

  Serial.print("Variable Pin Number (");
  Serial.print(*v_pin);
  Serial.println(") Results: ");

  Serial.print("\tpinMode(): ");
  Serial.print(array_S[8]);
  Serial.println(" clock cycles");
  Serial.print("\tquickMode(): ");
  Serial.print(array_S[9]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[9] / (float)array_S[8]) * 100.f );

  Serial.println();
  
  Serial.print("\tdigitalWrite(HIGH): ");
  Serial.print(array_S[10]);
  Serial.println(" clock cycles");
  Serial.print("\tquickWrite(HIGH): ");
  Serial.print(array_S[11]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[11] / (float)array_S[10]) * 100.f );

    Serial.println();
  
  Serial.print("\tdigitalWrite(LOW): ");
  Serial.print(array_S[12]);
  Serial.println(" clock cycles");
  Serial.print("\tquickWrite(LOW): ");
  Serial.print(array_S[13]);
  Serial.println(" clock cycles");
  Serial.print("\t% difference: ");
  Serial.println( ((float)array_S[13] / (float)array_S[12]) * 100.f );

  Serial.println();

  Serial.print("\tquickToggle(LOW->HIGH): ");
  Serial.print(array_S[14]);
  Serial.println(" clock cycles");
  Serial.print("\tquickToggle(HIGH->LOW): ");
  Serial.print(array_S[15]);
  Serial.println(" clock cycles");

  Serial.println();

  Serial.println("Pure DPM Reuslts:");
  Serial.print("\tDDRD set: ");
  Serial.print(array_S[16]);
  Serial.println(" cycles");

  Serial.print("\tPORTD set: ");
  Serial.print(array_S[17]);
  Serial.println(" cycles");

  Serial.print("\tPIND Toggle: ");
  Serial.print(array_S[18]);
  Serial.println("cycles");
  
  Serial.print("\tPIND Function: ");
  Serial.print(array_S[19]);
  Serial.println("cycles");
  
}

void bitwise_F_test(){
  PIND = 0x01;
}
