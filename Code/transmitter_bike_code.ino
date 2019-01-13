/*
 * Transmitter remote code:
 * Upon powering on, every pin should be set to their repsective posistion. It will set the transmission indicator (LED) to the value of 0, and then begin receiving input from the user.  
 * Once a valid entry is selected, the LED will blink to notify the user that a signal is being sent. It will send the correspoding metadata to the motorcycle's receiving module for 
 * further processing.
 */
#include <VirtualWire.h>

//initialize pins for use
const char LED_PIN = 2;
const char LOCK_BUTTON = 3;
const char HORN_BUTTON = 4;
const char STOP_BUTTON = 5;
const char START_BUTTON = 6;
const char TRANSMIT_PIN = 7;

//number of times for the signal to be sent
const char REPEAT_NUMBER = 3;

//create the message arrays to be send from the transmitter.
const char LOCK[5] = {'l','o','c','k',' '};
const char HORN[5] = {'h','o','r','n',' '};
const char STOP[5] = {'s','t','o','p',' '};
const char START[5] = {'s','t','a','r','t'};




void setup() {  
  //setup the board for wireless communication.
  vw_setup(2000);
  vw_set_tx_pin(TRANSMIT_PIN);

  //set the pin to either be used as input, or output depending on their function.
  pinMode(LED_PIN, OUTPUT);
  pinMode(LOCK_BUTTON, INPUT);
  pinMode(HORN_BUTTON, INPUT);
  pinMode(STOP_BUTTON, INPUT);
  pinMode(START_BUTTON, INPUT);

  //set the indicator to 0 so there is no confusion of a signal being sent. Precautionary.
  digitalWrite(LED_PIN, LOW);
}

void loop() {

  //check to see if a button has been pressed.
  if(digitalRead(LOCK_BUTTON) == 1){
    //loop 3 times to ensure message delivery.
    for(char i = 0; i < REPEAT_NUMBER; i++){
      //flash a light to show transmission.
      digitalWrite(LED_PIN, HIGH); 
      //send the start message to be received by receiver.
      vw_send((uint8_t *)LOCK, 5);
      //wait for transmission completion.
      vw_wait_tx();
      //turn off led to notify of completion.
      digitalWrite(LED_PIN, LOW);
      delay(250);
      }
   }
   
   //check to see if a button has been pressed.
   if(digitalRead(HORN_BUTTON) == 1){
     //loop 3 times to ensure message delivery.
     for(char i = 0; i < REPEAT_NUMBER; i++){
       //flash a light to show transmission.
       digitalWrite(LED_PIN, HIGH); 
       //send the start message to be received by receiver.
       vw_send((uint8_t *)HORN, 5);
       //wait for transmission completion.
       vw_wait_tx();
       //turn off led to notify of completion.
       digitalWrite(LED_PIN, LOW);
       delay(250);
      }
   }
   
   //check to see if a button has been pressed.
   if(digitalRead(STOP_BUTTON) == 1){
     //loop 3 times to ensure message delivery.
     for(char i = 0; i < REPEAT_NUMBER; i++){
       //flash a light to show transmission.
       digitalWrite(LED_PIN, HIGH); 
       //send the start message to be received by receiver.
       vw_send((uint8_t *)STOP, 5);
       //wait for transmission completion.
       vw_wait_tx();
       //turn off led to notify of completion.
       digitalWrite(LED_PIN, LOW);
       delay(250);
      }
   }
   
   //check to see if a button has been pressed.
   if(digitalRead(START_BUTTON) == 1){
     //loop 3 times to ensure message delivery.
     for(char i = 0; i < REPEAT_NUMBER; i++){
       //flash a light to show transmission.
       digitalWrite(LED_PIN, HIGH); 
       //send the start message to be received by receiver.
       vw_send((uint8_t *)START, 5);
       //wait for transmission completion.
       vw_wait_tx();
       //turn off led to notify of completion.
       digitalWrite(LED_PIN, LOW);
       delay(250);
      }
   }
   
  
}
