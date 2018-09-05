// motion macro
#define LEG_FORWARD 	'F'
#define LEG_BACK    	'B'
#define STRETCH_UP		'U'
#define STRETCH_DOWN	'D'
#define NEUTRAL			'N'

#include <string.h>
#include "MyUDP.h"
#include "MyServo.h"

int angle[19] = {0};
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
}

void pwm_test()
{
    ledcAttachPin(SERVO[0], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[1], LEG_CR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[2], LEG_BR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[3], LEG_FL) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[4], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[5], LEG_CR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[6], LEG_BR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[7], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[8], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[9], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[10], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[11], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[12], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[13], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[14], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[15], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[16], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[17], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[18], LEG_FR) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[19], LEG_FR) ; // CH3をRC SERVOに
    servo_move(-90, LEG_FR);
    servo_move(-75, LEG_FR);
    servo_move(-60, LEG_FR);
    servo_move(-45, LEG_FR);
    servo_move(-30, LEG_FR);
    servo_move(-15, LEG_FR);
    servo_move(0, LEG_FR);
    servo_move(15, LEG_FR);
    servo_move(30, LEG_FR);
    servo_move(45, LEG_FR);
    servo_move(60, LEG_FR);
    servo_move(75, LEG_FR);
    servo_move(90, LEG_FR);
    servo_move(50, LEG_FR);
    servo_move(0, LEG_FR);
}

void loop() {
    char param[READ_SIZE];
    udp_rw(param);
	//パラメータを16進数で表示する
	Serial.print("param:");
	Serial.print(param[0]);
	Serial.print(" ");
	Serial.println(param[1]);
    switch(param[0]){
        case LEG_FORWARD :
            forward();
			break;
		case LEG_BACK :
			back();
            break;
		case STRETCH_UP :
			stretch(1);
			break;
		case STRETCH_DOWN :
			stretch(2);
			break;
		case NEUTRAL :
			udp.begin(localPort);	//udpバッファを破棄するために必要
			break;
        case 0 :
            break;
        default :
            break;
    }
}