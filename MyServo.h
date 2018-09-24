// servo parameter
// サーボ信号の１サイクル 50Hz:20ms
#define LEDC_SERVO_FREQ     50
#define SERVO_MIN_WIDTH_MS  0.6
#define SERVO_MAX_WIDTH_MS  2.4
#define DEF_FL -10
#define DEF_FR 10
#define DEF_CL 0
#define DEF_CR 0
#define DEF_BL 10
#define DEF_BR -10

static int F_FLG = 0;
static int stretch_param = 0;
static const int d_time = 200;
static const int s_delay = 60;
// 端子番号 SERVO[0-19]
const int SERVO[] = {19, //0 LEGUP1
                     14, //1 LEGUP1
                      4, //2 LEGUP1
                     26, //3 LEGUP2
                      5, //4 LEGUP2
                     25, //5 LEGUP2
                     27, //6 LEGFL
                     12, //7 LEGCL
                     13, //8 LEGBL
                     18, //9 LEGFR
                     17, //10 LEGCR
                     16, //11 LEGBR
                     15, //12 TAIL1
                      2, //13 TAIL2
                     33, //14 SCISSORS_L1
                     32, //15 SCISSORS_L2
                     22, //16 SCISSORS_R1
                     23, //17 SCISSORS_R2
                     21, //18 reserve
                     0};//19 reserve

// pwmチャンネル番号　0 - 15
#define LEG_UP1			0
#define LEG_UP2			1
#define LEG_FL      	2
#define LEG_CL      	3
#define LEG_BL      	4
#define LEG_FR      	5
#define LEG_CR      	6
#define LEG_BR      	7
#define TAIL_1      	8
#define TAIL_2      	9
#define SCISSORS_L1     10
#define SCISSORS_L2     11
#define SCISSORS_R1     12
#define SCISSORS_R2     13
#define RESERVE1     	14
#define RESERVE2     	15

// 分解能 16bit
#define LEDC_TIMER_16_BIT   16

int servo_pwm_count(int v)
{
    float vv = (v + 90) / 180.0 ;
    return (int)(65536 * (SERVO_MIN_WIDTH_MS + vv * (SERVO_MAX_WIDTH_MS - SERVO_MIN_WIDTH_MS)) / 20.0) ;
}

void servo_move(int param, int ch)
{
    ledcWrite(ch, servo_pwm_count(param));
	delay(s_delay);
}

void servo_init()
{
    // RC SERVOの初期化
    ledcSetup(LEG_UP1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); 	// 16ビット精度で制御
    ledcSetup(LEG_UP2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); 	// 16ビット精度で制御
    ledcSetup(LEG_FL, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(LEG_CL, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(LEG_BL, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(LEG_FR, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(LEG_CR, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(LEG_BR, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(TAIL_1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(TAIL_2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  	// 16ビット精度で制御
    ledcSetup(SCISSORS_L1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(SCISSORS_L2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(SCISSORS_R1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(SCISSORS_R2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(RESERVE1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); 	// 16ビット精度で制御
    ledcSetup(RESERVE2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); 	// 16ビット精度で制御
    delay(1000);
	ledcAttachPin(SERVO[0], LEG_UP1) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[1], LEG_UP1) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[2], LEG_UP1) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[3], LEG_UP2) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[4], LEG_UP2) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[5], LEG_UP2) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[6], LEG_FL) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[7], LEG_CL) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[8], LEG_BL) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[9], LEG_FR) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[10], LEG_CR) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[11], LEG_BR) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[12], TAIL_1) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[13], TAIL_2) ; 	// CH3をRC SERVOに
    ledcAttachPin(SERVO[14], SCISSORS_L1) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[15], SCISSORS_L2) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[16], SCISSORS_R1) ; // CH3をRC SERVOに
    ledcAttachPin(SERVO[17], SCISSORS_R2) ; // CH3をRC SERVOに
	delay(1000);

}

void forward()
{
    if(F_FLG == 0)	//ステップ1
    {
		//足を上げる
		servo_move(-40 + stretch_param, LEG_UP1);
		delay(50);
		//足を後ろに出す
		servo_move(DEF_CL, LEG_CL);
		servo_move(DEF_FR, LEG_FR);
		servo_move(DEF_BR, LEG_BR);
		delay(50);
		//足を前に出す
		servo_move(DEF_CR, LEG_CR);
		servo_move(DEF_FL, LEG_FL);
		servo_move(DEF_BL, LEG_BL);
		delay(50);

		//足を後ろに出す
		servo_move(-10 + DEF_CL, LEG_CL);
		servo_move(10 + DEF_FR, LEG_FR);
		servo_move(10 + DEF_BR, LEG_BR);
		delay(50);
		//足を前に出す
		servo_move(-10 + DEF_CR, LEG_CR);
		servo_move(10 + DEF_FL, LEG_FL);
		servo_move(10 + DEF_BL, LEG_BL);
		delay(50);
		//足を下げる
		servo_move(0 + stretch_param, LEG_UP1);
		delay(d_time);
    }
	else			//ステップ2
	{
		//足を上げる
		servo_move(-40 + stretch_param, LEG_UP2);
		//足を後ろに出す
		servo_move(DEF_CR, LEG_CR);
		servo_move(DEF_FL, LEG_FL);
		servo_move(DEF_BL, LEG_BL);
		//足を前に出す
		servo_move(DEF_CL, LEG_CL);
		servo_move(DEF_FR, LEG_FR);
		servo_move(DEF_BR, LEG_BR);
		delay(50);

		//足を後ろに出す
		servo_move(10 + DEF_CR, LEG_CR);
		servo_move(-10 + DEF_FL, LEG_FL);
		servo_move(-10 + DEF_BL, LEG_BL);
		//足を前に出す
		servo_move(10 + DEF_CL, LEG_CL);
		servo_move(-10 + DEF_FR, LEG_FR);
		servo_move(-10 + DEF_BR, LEG_BR);
		//足を下げる
		servo_move(0 + stretch_param, LEG_UP2);
		delay(d_time);
	}
	if(F_FLG == 0)  F_FLG = 1;
	else            F_FLG = 0;
}

void back()
{
    if(F_FLG == 1)	//ステップ1
    {
		//足を上げる
		servo_move(-40 + stretch_param, LEG_UP1);
		//足を前に出す
		servo_move(DEF_CL, LEG_CL);
		servo_move(DEF_FR, LEG_FR);
		servo_move(DEF_BR, LEG_BR);
		//足を後ろに下げる
		servo_move(DEF_CR, LEG_CR);
		servo_move(DEF_FL, LEG_FL);
		servo_move(DEF_BL, LEG_BL);
		delay(50);

		//足を前に出す
		servo_move(10 + DEF_CL, LEG_CL);
		servo_move(-10 + DEF_FR, LEG_FR);
		servo_move(-10 + DEF_BR, LEG_BR);
		//足を後ろに下げる
		servo_move(10 + DEF_CR, LEG_CR);
		servo_move(-10 + DEF_FL, LEG_FL);
		servo_move(-10 + DEF_BL, LEG_BL);
		//足を下げる
		servo_move(0 + stretch_param, LEG_UP1);
		delay(d_time);
    }
	else			//ステップ2
	{
		//足を上げる
		servo_move(-40 + stretch_param, LEG_UP2);
		delay(50);
		//足を前に出す
		servo_move(DEF_CR, LEG_CR);
		servo_move(DEF_FL, LEG_FL);
		servo_move(DEF_BL, LEG_BL);
		//足を後ろに下げる
		servo_move(DEF_CL, LEG_CL);
		servo_move(DEF_FR, LEG_FR);
		servo_move(DEF_BR, LEG_BR);
		delay(50);

		//足を前に出す
		servo_move(-10 + DEF_CR, LEG_CR);
		servo_move(10 + DEF_FL, LEG_FL);
		servo_move(10 + DEF_BL, LEG_BL);
		delay(50);
		//足を後ろに下げる
		servo_move(-10 + DEF_CL, LEG_CL);
		servo_move(10 + DEF_FR, LEG_FR);
		servo_move(10 + DEF_BR, LEG_BR);
		//足を下げる
		servo_move(0 + stretch_param, LEG_UP2);
		delay(d_time);
    }

	if(F_FLG == 0)  F_FLG = 1;
	else            F_FLG = 0;
}


void stretch(int md)
{
	if(md == 1)	stretch_param += 1;
	else		stretch_param -= 1;

	if(stretch_param > 40)			stretch_param = 40;
	else if(stretch_param < -20)	stretch_param = -20;
	servo_move(0 + stretch_param, LEG_UP1);
	servo_move(0 + stretch_param, LEG_UP2);
}

void default_pos()
{
	servo_move(stretch_param, LEG_UP1);
	servo_move(stretch_param, LEG_UP2);
	servo_move(DEF_FL, LEG_FL);
	servo_move(DEF_FR,  LEG_FR);
	servo_move(DEF_CL), LEG_CL);
	servo_move(DEF_CR, LEG_CR);
	servo_move(DEF_BL,  LEG_BL);
	servo_move(DEF_BR, LEG_BR);
}