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
    if(udp_init(CL_MODE) != 0)
    {
        Serial.println("connection failed...");
        while(1);
    }
    servo_init();
	pwm_test();
}

void pwm_test()
{
	servo_move(0, LEG_UP1);
	delay(1000);
	servo_move(0, LEG_UP2);
	delay(1000);
	servo_move(0, LEG_FL);
	servo_move(0, LEG_FR);
	delay(500);
	servo_move(0, LEG_CL);
	servo_move(0, LEG_CR);
	delay(500);
	servo_move(0, LEG_BL);
	servo_move(0, LEG_BR);
	delay(500);

	/*servo_move(0, TAIL_1);
	servo_move(0, TAIL_2);
	delay(500);
	servo_move(0, SCISSORS_L1);
	servo_move(0, SCISSORS_L2);
	delay(500);
	servo_move(0, SCISSORS_R1);
	servo_move(0, SCISSORS_R2);
	delay(500);
	*/
	delay(1000);
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