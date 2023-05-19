// Arduino c++ code

//

const int LDR_Pin = A0; // define the LDR sensor pin

const int LED_Pin = 13; // define the LED pin

const int buzzer = 12;

int LDR_Value; // variable to store the LDR sensor value

int Threshold_Value = 500; // set the threshold value for detecting sleep apnea

int Delay_Time = 5000; // set the delay time for each measurement in milliseconds

 

void setup() {

  pinMode(LED_Pin, OUTPUT);  // set the LED pin as an output

  pinMode(buzzer,OUTPUT);

  pinMode(LDR_Pin,INPUT);

 

  Serial.begin(9600); // initialize serial communication

}

 

void loop() {

  //LDR_Value=Serial.parseInt();// take substitute input value from user

  delay(Delay_Time); // wait for the delay time

  LDR_Value = analogRead(LDR_Pin); // read the LDR sensor value

  /*digitalWrite(LED_Pin, HIGH); // turn on the LED

  digitalWrite(buzzer,HIGH); //turn on buzzer

      delay(2000);//wait for 2000ms

  digitalWrite(buzzer,LOW);//turn off buzzer

  digitalWrite(LED_Pin, LOW); // turn off the LED

      delay(2000);//wait for 2000ms*/

 

  Serial.println(LDR_Value); // print the LDR sensor value to the serial monitor

 

  if (LDR_Value < Threshold_Value) { // if the LDR value is below the threshold, sleep apnea is detected

    Serial.println("Sleep apnea detected!");

    // trigger an alert mechanism here

      delay(10);

      digitalWrite(13,HIGH);

      digitalWrite(12,HIGH);

      delay(2000);//wait for 2000ms

      digitalWrite(12,LOW);

      digitalWrite(13,LOW);

      delay(2000);//wait for 2000ms

   

  }else{

    Serial.println("SAFE");

  }

 

  delay(Delay_Time); // wait for the delay time before the next measurement

}


