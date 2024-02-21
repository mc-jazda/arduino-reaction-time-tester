#include <LiquidCrystal.h>

const int LCD1 = 14;
const int LCD2 = 15;
const int LCD3 = 16;
const int LCD4 = 17;
const int LCD5 = 18;
const int BUTTON = 19;

//LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
	Serial.begin(9600);

	// LEDs initialization
	pinMode(LCD1, OUTPUT);
	digitalWrite(LCD1, LOW);
	pinMode(LCD2, OUTPUT);
	digitalWrite(LCD2, LOW);
	pinMode(LCD3, OUTPUT);
	digitalWrite(LCD3, LOW);
	pinMode(LCD4, OUTPUT);
	digitalWrite(LCD4, LOW);
	pinMode(LCD5, OUTPUT);
	digitalWrite(LCD5, LOW);

	// Button initialization
	pinMode(BUTTON, INPUT_PULLUP);
	digitalWrite(BUTTON, HIGH);

	// LCD initialization
	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
	lcd.print("Press the button");
	lcd.setCursor(0, 1);
	lcd.print("to start!");
}

// Main loop
void loop()
{	
	if (digitalRead(BUTTON) == LOW) {	// Check if button was pressed
		lcd.clear();

		// Ligth up all LEDs
    	for (int i = LCD1; i <= LCD5; i++) {
			digitalWrite(i, HIGH);
			delay(700);
		}

		// Turn off LED after random time
		long randomTime = random(100, 2000);
		delay(randomTime);

		for (int i = LCD1; i <= LCD5; i++) {
			digitalWrite(i, LOW);
		}

		// Count how long it took to press button
		unsigned long startTime = millis();

		while(digitalRead(BUTTON) == HIGH) { ; }

		unsigned long elapsedTime = abs(millis() - startTime);

		// Display time after button was pressed
		lcd.clear();
		lcd.print("Reaction time:");
		lcd.setCursor(0, 1);
		lcd.print(elapsedTime);
		lcd.print(" ms");
		
		delay(500);
		while(digitalRead(BUTTON) == HIGH) { ; }
  	}
}