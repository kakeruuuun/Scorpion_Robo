#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiMulti.h>
#include "MyId.h"

#define READ_SIZE   2

#define AP_MODE     0
#define CL_MODE     1

// wifi parameter
const int localPort  = 10000;           // local ポート番号
const int remotePort = 10001;           // remoteポート番号

const IPAddress ap_ip(192, 168, 30, 1);   // IPアドレス(ゲートウェイも兼ねる)
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク
const IPAddress cl_ip(192, 168, 42, 101);      // クライアントモード時のIPアドレス
const IPAddress cl_gateway(192, 168, 42, 1);      // クライアントモード時のゲートウェイ

IPAddress remoteIP;
WiFiUDP udp;
WiFiMulti wifiMulti;

int udp_init()
{
    WiFi.softAP(Myssid, Mypass);                    // SSIDとパスの設定
    delay(100);                                     //このdelayを入れないと失敗する場合がある
    WiFi.softAPConfig(ap_ip, ap_ip, subnet);     // IPアドレス、ゲートウェイ、サブネットマスクの設定
    Serial.print("AP IP address: ");
    IPAddress myIP = WiFi.softAPIP();
    Serial.println(myIP);

    Serial.println("Starting UDP");
    udp.begin(localPort);    // UDP通信の開始(引数はポート番号)

    Serial.print("Local port: ");
    Serial.println(localPort);
    return 0;
	
}

int udp_init(int md)
{
    if(md == AP_MODE)
    {
        WiFi.softAP(Myssid, Mypass);                    // SSIDとパスの設定
        delay(100);                                     //このdelayを入れないと失敗する場合がある
        WiFi.softAPConfig(ap_ip, ap_ip, subnet);     // IPアドレス、ゲートウェイ、サブネットマスクの設定
        Serial.print("AP IP address: ");
        IPAddress myIP = WiFi.softAPIP();
        Serial.println(myIP);
    }
    else if(md == CL_MODE)
    {
        
        WiFi.disconnect(true);
        delay(1000);
        wifiMulti.addAP(cl_ssid, cl_pass);
        WiFi.config(cl_ip, cl_gateway, subnet);
        while(wifiMulti.run() != WL_CONNECTED);
        delay(500);
        Serial.println("Connected!");
    }

    Serial.println("Starting UDP");
    udp.begin(localPort);    // UDP通信の開始(引数はポート番号)
    Serial.print("Local port: ");
    Serial.println(localPort);
    return 0;
}

void udp_rw(char read_buf[]) {
    int PackektSize;
    int i;
	while(1)	//パケットが送られてくるまでループ
	{
		if (PackektSize = udp.parsePacket()) {
			remoteIP = udp.remoteIP();
			udp.beginPacket(remoteIP, remotePort);
			udp.read(read_buf, READ_SIZE);

			for(i = 0; i < READ_SIZE;i++){
				udp.write(read_buf[i]);
				udp.flush();
			}
			udp.endPacket();
			Serial.print("size:");
			Serial.println(PackektSize);
			break;
		}
	}
}