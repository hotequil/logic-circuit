#define playLed 6
#define playSwitch 0
#define frontLed 5
#define frontButton 7
#define rightLed 4
#define rightButton 8
#define backLed 3
#define backButton 9
#define leftLed 2
#define leftButton 10
#define fakeLed 9999

int leds[4] = {frontLed, rightLed, backLed, leftLed};

void setup(){
  	Serial.begin(9600);
  
  	pinMode(playLed, OUTPUT);
  	pinMode(playSwitch, INPUT);
  	pinMode(frontLed, OUTPUT);
  	pinMode(frontButton, INPUT_PULLUP);
    pinMode(rightLed, OUTPUT);
  	pinMode(rightButton, INPUT_PULLUP);
  	pinMode(backLed, OUTPUT);
  	pinMode(backButton, INPUT_PULLUP);
    pinMode(leftLed, OUTPUT);
  	pinMode(leftButton, INPUT_PULLUP);
}

void light(int led, bool lightPlay = true){
  	for(int index = 0; index <= (sizeof(leds) / sizeof(leds[0])); index++){
  		int currentLed = leds[index];
            
      	currentLed == led ? digitalWrite(led, HIGH) : digitalWrite(led, LOW);
  	}
  
	digitalWrite(playLed, lightPlay);
}

void loop(){
  	bool frontButtonPressed = digitalRead(frontButton) == LOW;
  	bool rightButtonPressed = digitalRead(rightButton) == LOW;
  	bool backButtonPressed = digitalRead(backButton) == LOW;
  	bool leftButtonPressed = digitalRead(leftButton) == LOW;
	bool pressedButtons[4] = {frontButtonPressed, rightButtonPressed, backButtonPressed, leftButtonPressed};
  	bool isPlayed = digitalRead(playSwitch);
  	int count = 0; 	
  
  	for(int index = 0; index < (sizeof(pressedButtons) / sizeof(pressedButtons[0])); index++){
      if(pressedButtons[index]) count++; 
  	}
  
  	if(isPlayed){
      	if(count == 0 || count > 1) light(fakeLed);
      	else if(frontButtonPressed) light(frontLed);
      	else if(rightButtonPressed) light(rightLed);
        else if(backButtonPressed) light(backLed);
        else if(leftButtonPressed) light(leftLed);
    } else light(fakeLed, false);
}
