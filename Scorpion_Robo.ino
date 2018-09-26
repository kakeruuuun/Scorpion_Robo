// motion macro
#define LEG_FORWARD		'F'
#define LEG_BACK		'B'
#define TURN_L			'L'
#define TURN_R			'R'
#define STRETCH_UP		'U'
#define STRETCH_DOWN	'D'
#define NEUTRAL			'N'

#include <string.h>
#include "MyUDP.h"
#include "MyServo.h"

int angle[19] = {0};
char param[READ_SIZE] = {'0', '0'};
int pwm_sw_val;

void pwm_test();

void setup() {
    Serial.begin(115200);
    //サーボモータ初期化
    if(udp_init(AP_MODE) != 0)
    {
        Serial.println("connection failed...");
        while(1);
    }
    servo_init();
	default_pos();
}

void loop() {
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
		case TURN_L :
			turn_left();
			break;
		case TURN_R :
			turn_right();
			break;
		case STRETCH_UP :
			stretch(1);
			break;
		case STRETCH_DOWN :
			stretch(2);
			break;
		case NEUTRAL :
			default_pos();
			param[0] = '0';
			break;
        case 0 :
            break;
        default :
            break;
    }
}