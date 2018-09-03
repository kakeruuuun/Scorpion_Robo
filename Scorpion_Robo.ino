// motion macro
#define LEG_FORWARD 0b10000000
#define LEG_BACK    0b11000000


#include <string.h>
#include "MyUDP.h"
#include "MyServo.h"

int angle[20] = {0};
int pwm_sw_val;

void pwm_test();

void setup() {
    Serial.begin(115200);
    //サーボモータ初期化
    servo_init();
    if(udp_init(AP_MODE) != 0)
    {
        Serial.println("connection failed...");
        while(1);
    }
    pwm_test();
}



void pwm_test()
{
    ledcAttachPin(SERVO[0], LEDC_CHANNEL_0) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[1], LEDC_CHANNEL_1) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[2], LEDC_CHANNEL_2) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[3], LEDC_CHANNEL_3) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[4], LEDC_CHANNEL_4) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[5], LEDC_CHANNEL_5) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[6], LEDC_CHANNEL_6) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[7], LEDC_CHANNEL_7) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[8], LEDC_CHANNEL_8) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[9], LEDC_CHANNEL_9) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[10], LEDC_CHANNEL_10) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[11], LEDC_CHANNEL_8) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[12], LEDC_CHANNEL_9) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[13], LEDC_CHANNEL_11) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[14], LEDC_CHANNEL_12) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[15], LEDC_CHANNEL_13) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[16], LEDC_CHANNEL_14) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[17], LEDC_CHANNEL_15) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[18], LEDC_CHANNEL_14) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[19], LEDC_CHANNEL_0) ; // CH3をRC SERVOに
    servo_move(-90, LEDC_CHANNEL_1);
    servo_move(-75, LEDC_CHANNEL_2);
    servo_move(-60, LEDC_CHANNEL_3);
    servo_move(-45, LEDC_CHANNEL_4);
    servo_move(-30, LEDC_CHANNEL_5);
    servo_move(-15, LEDC_CHANNEL_6);
    servo_move(0, LEDC_CHANNEL_7);
    servo_move(15, LEDC_CHANNEL_8);
    servo_move(30, LEDC_CHANNEL_9);
    servo_move(45, LEDC_CHANNEL_10);
    servo_move(60, LEDC_CHANNEL_11);
    servo_move(75, LEDC_CHANNEL_12);
    servo_move(90, LEDC_CHANNEL_13);
    servo_move(50, LEDC_CHANNEL_14);
    servo_move(0, LEDC_CHANNEL_15);
}

void loop() {
    char param[READ_SIZE];
    udp_rw(param);
    switch(param[0]){
        case LEG_FORWARD :
            forward();
			break;
		case LEG_BACK :
			back();
            break;
        case 0 :
            break;
        default :
            angle[FRONT_LEG_R_1] =  50;
    }
}