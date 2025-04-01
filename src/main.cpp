#include <Arduino.h>

#define RUN_PIN 3
#define DIR_PIN 2
#define PWM_PIN 5

String run_state = "STOPPED";   // Track motor state
String direction = "CW";        // Track motor direction
int pwm_value = 255;            // Track last PWM duty cycle

unsigned long lastCommandMillis = 0;       // Tracks the last time we received a command
const unsigned long commandTimeout = 20000; // 20 seconds in milliseconds

void setup() {
  Serial.begin(9600);

  pinMode(PWM_PIN, OUTPUT);
  pinMode(RUN_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Default states
  digitalWrite(RUN_PIN, HIGH);  // Motor stopped
  digitalWrite(DIR_PIN, HIGH);  // CW direction
  analogWrite(PWM_PIN, 255);    // Full duty cycle by default

  run_state = "STOPPED";
  direction = "CW";
  pwm_value = 255;

  Serial.println("Motor Controller Ready.");
}

void loop() {
  // Read single-char commands:
  while (Serial.available() > 0) {
    char input = Serial.read();
    // Record time command was received
    lastCommandMillis = millis();

    switch (input) {
      case 'L':  // CW direction
        digitalWrite(DIR_PIN, HIGH);
        direction = "CW";
        Serial.println("Direction set to CW");
        break;

      case 'R':  // CCW direction
        digitalWrite(DIR_PIN, LOW);
        direction = "CCW";
        Serial.println("Direction set to CCW");
        break;

      case 'O':  // Stop motor
        digitalWrite(RUN_PIN, HIGH);
        run_state = "STOPPED";
        Serial.println("Stopping Motor");
        break;

      case 'S':  // Start motor
        digitalWrite(RUN_PIN, LOW);
        run_state = "RUNNING";
        Serial.println("Starting Motor");
        break;

      case '0':
        pwm_value = 25;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 25");
        break;

      case '1':
        pwm_value = 50;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 50");
        break;

      case '2':
        pwm_value = 75;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 75");
        break;

      case '3':
        pwm_value = 100;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 100");
        break;

      case '4':
        pwm_value = 125;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 125");
        break;

      case '5':
        pwm_value = 150;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 150");
        break;

      case '6':
        pwm_value = 175;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 175");
        break;

      case '7':
        pwm_value = 200;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 200");
        break;

      case '8':
        pwm_value = 225;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 225");
        break;

      case '9':
        pwm_value = 255;
        analogWrite(PWM_PIN, pwm_value);
        Serial.println("PWM set to 255");
        break;

      case '?':  // Return current status
        Serial.print(run_state);
        Serial.print(",");
        Serial.print(direction);
        Serial.print(",");
        Serial.println(pwm_value);
        break;

      default:
        // Unknown command
        Serial.println("Unknown command.");
        break;
    }
  }

  // Check for command timeout
  if (millis() - lastCommandMillis >= commandTimeout) {
    // Time out condition met: stop the motor if not already stopped
    if (run_state == "RUNNING") {
      digitalWrite(RUN_PIN, HIGH);
      run_state = "STOPPED";
      Serial.println("Timeout: Stopping Motor");
    }
  }
}