#include <pigpio.h>
#include <unistd.h>
#define IN1_GPIO_NO 18
#define IN2_GPIO_NO 19

#define PWM_FREQ 60

import time
# Import the PCA9685 module.
import Adafruit_PCA9685
import RPi.GPIO as GPIO
# Initialise the PCA9685 using the default address (0x40).
pwm = Adafruit_PCA9685.PCA9685()
 
servo_pin = 15 #  servo connect to PWM 15

RIGHT = 465 #Steer servo car turn right
CENTER= 425 #Steer servo car go forward
LEFT = 385 #Steer servo car turn left

# Alternatively specify a different address and/or bus:
#pwm = Adafruit_PCA9685.PCA9685(address=0x41, busnum=2)

#define move_speed 4000  // Max pulse length out of 4096 //

# Set frequency to 60hz, good for servos.
pwm.set_pwm_freq(60)
pwm.set_pwm(servo_pin, 0, LEFT)
time.sleep(1)
pwm.set_pwm(servo_pin, 0, RIGHT)
time.sleep(1)
pwm.set_pwm(servo_pin, 0, CENTER)


GPIO.setmode(GPIO.BCM) # GPIO number  in BCM mode
GPIO.setwarnings(False)
#define L298N(Model-Pi motor drive board) GPIO pins
IN1 = 23  #right motor direction pin
IN2 = 24  #right motor direction pin
IN3 = 27  #left motor direction pin
IN4 = 22  #left motor direction pin
ENA = 0  #Right motor speed PCA9685 port 0
ENB = 1  #Left motor speed PCA9685 port 1

#define motor control  pins as output
GPIO.setup(IN1, GPIO.OUT)   
GPIO.setup(IN2, GPIO.OUT) 
GPIO.setup(IN3, GPIO.OUT)   
GPIO.setup(IN4, GPIO.OUT) 



int changespeed(speed){
	pwm.set_pwm(ENA, 0, speed);
	pwm.set_pwm(ENB, 0, speed);
	}

int stopcar(void){
	GPIO.output(IN1, GPIO.LOW);
	GPIO.output(IN2, GPIO.LOW);
	GPIO.output(IN3, GPIO.LOW);
	GPIO.output(IN4, GPIO.LOW);
	changespeed(0);
	}

int forward(void){
	GPIO.output(IN1, GPIO.HIGH);
	GPIO.output(IN2, GPIO.LOW);
	GPIO.output(IN3, GPIO.HIGH);
	GPIO.output(IN4, GPIO.LOW);
	changespeed(move_speed);
	}
 
	#following two lines can be removed if you want car make continuous movement without pause
	#time.sleep(0.25)  
	#stopcar()
	
int backward(void){
	GPIO.output(IN1, GPIO.LOW);
	GPIO.output(IN2, GPIO.HIGH);
	GPIO.output(IN3, GPIO.LOW);
	GPIO.output(IN4, GPIO.HIGH);
	changespeed(move_speed);
	}
	
	#following two lines can be removed if you want car make continuous movement without pause
	#time.sleep(0.25)  
	#stopcar()
	
int steer(angle){
	if angle>RIGHT :
		angle=RIGHT
	if angle<LEFT :
		angle=LEFT
	pwm.set_pwm(servo_pin, 0, angle)
	}



int main(void)
{
	int ret = gpioInitialise();
	steer(CENTER);
	forward();
	time.sleep(2);
	stopcar();
	time.sleep(0.25);

	backward();
	time.sleep(2);
	stopcar();
	time.sleep(0.25);

	steer(LEFT);
	forward();
	time.sleep(2);
 
	steer(RIGHT);
	forward();
	time.sleep(2);  

	backward();
	time.sleep(2);  

	steer(LEFT);
	backward();
	time.sleep(2);  
	stopcar();
	steer(CENTER);
	
	time.sleep(2);
	pwm.set_pwm(15, 0, 0);

	return 0;
}
