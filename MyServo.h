// servo parameter
// サーボ信号の１サイクル 50Hz:20ms
#define LEDC_SERVO_FREQ     50
#define SERVO_MIN_WIDTH_MS  0.6
#define SERVO_MAX_WIDTH_MS  2.4

static int F_FLG = 0;

// 端子番号 SERVO[0-19]
const int SERVO[] = {15, //0
                      2,  //1
                      0,  //2
                      4,  //3
                      16, //4
                      17, //5
                      5,  //6
                      18, //7
                      19, //8
                      21, //9
                      22, //10
                      23, //11
                      32, //12
                      33, //13
                      25, //14
                      26, //15
                      27, //16
                      14, //17
                      12, //18
                      13};//19

// pwmチャンネル番号　0 - 15
#define LEDC_CHANNEL_0      0
#define LEDC_CHANNEL_1      1
#define LEDC_CHANNEL_2      2
#define LEDC_CHANNEL_3      3
#define LEDC_CHANNEL_4      4
#define LEDC_CHANNEL_5      5
#define LEDC_CHANNEL_6      6
#define LEDC_CHANNEL_7      7
#define LEDC_CHANNEL_8      8
#define LEDC_CHANNEL_9      9
#define LEDC_CHANNEL_10     10
#define LEDC_CHANNEL_11     11
#define LEDC_CHANNEL_12     12
#define LEDC_CHANNEL_13     13
#define LEDC_CHANNEL_14     14
#define LEDC_CHANNEL_15     15

// 分解能 16bit
#define LEDC_TIMER_16_BIT   16

enum Servo_num {
    FRONT_LEG_R_1 ,
    FRONT_LEG_R_2 ,
    FRONT_LEG_L_1 ,
    FRONT_LEG_L_2 ,
    CENTER_LEG_R_1 ,
    CENTER_LEG_R_2 ,
    CENTER_LEG_L_1 ,
    CENTER_LEG_L_2 ,
    REAR_LEG_R_1 ,
    REAR_LEG_R_2 ,
    REAR_LEG_L_1 ,
    REAR_LEG_L_2 ,

    SCISSORS_R_1 ,
    SCISSORS_R_2 ,
    SCISSORS_R_3 ,
    SCISSORS_L_1 ,
    SCISSORS_L_2 ,
    SCISSORS_L_3 ,

    TAIL_1 ,
    TAIL_2
};

void servo_init()
{
    // RC SERVOの初期化
    ledcSetup(LEDC_CHANNEL_0, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_1, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_2, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_3, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_4, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_5, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_6, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_7, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_8, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_9, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT);  // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_10, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_11, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_12, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_13, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_14, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    ledcSetup(LEDC_CHANNEL_15, LEDC_SERVO_FREQ, LEDC_TIMER_16_BIT); // 16ビット精度で制御
    delay(1000);
}

int servo_pwm_count(int v)
{
    float vv = (v + 90) / 180.0 ;
    return (int)(65536 * (SERVO_MIN_WIDTH_MS + vv * (SERVO_MAX_WIDTH_MS - SERVO_MIN_WIDTH_MS)) / 20.0) ;
}

void servo_move(int param, int ch)
{
    ledcWrite(ch, servo_pwm_count(param)) ; 
}

void forward()
{
    if(F_FLG == 0)
    {
		servo_move(20 , LEDC_CHANNEL_0);
    }
	else
	{
		servo_move(-20, LEDC_CHANNEL_0);
    }
	delay(500);
	
	if(F_FLG == 0)  F_FLG = 1;
	else            F_FLG = 0;
}

void back()
{
    if(F_FLG == 0)
    {
		servo_move(40 , LEDC_CHANNEL_0);
    }
	else
	{
		servo_move(-40, LEDC_CHANNEL_0);
    }
	delay(500);

	if(F_FLG == 0)  F_FLG = 1;
	else            F_FLG = 0;
}