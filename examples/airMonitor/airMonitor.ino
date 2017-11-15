/*
************************************************************************
* 作者:  IntoRobot Team 
* 版本:  V1.0.0
* 时间:  03-30-15
************************************************************************
功能描述：
空气检测仪：检测空气温度、湿度、灰尘浓度以及光照强度

所需器件:
1. DHT11 温湿度传感器模块
2. GY30  光照传感器模块
3. GP2Y10 PM2.5灰尘传感器模块

接线说明
DHT11          核心板      
VCC            3V3       
GND            GND       
DATA           D3        

GY30                 
VCC            3V3       
GND            GND       
SDA            I2C(Wire组)的SDA        
SCL            I2C(Wire组)的SCL        

GP2Y10               
VCC	           3V3       
GND            GND       
LED            D0        
OUT            A0     

说明：带有“D”的为数字管脚，带有“A”的为模拟管脚，接线时请确认核心板引脚，避免接线错误。 
请注意核心板I2C引脚区别，避免接线错误
*/

#include <gy30.h> 
#include <IntoRobot_DHT.h>
#include <gp2y10.h>
#include <WidgetAirMonitoring.h>

#define DHT_TYPE   DHT11
#define DHT11_PIN D3
#define GP2Y10_LED_PIN D0
#define GP2Y10_OUT_PIN A0

IntoRobot_DHT dht11(DHT11_PIN,DHT_TYPE);
GP2Y10 gp2y10 = GP2Y10(GP2Y10_OUT_PIN,GP2Y10_LED_PIN);  
GY30 gy30;  

WidgetAirMonitoring airMoitor = WidgetAirMonitoring();

void setup()
{
	//初始化
	dht11.begin(); 
	gp2y10.begin(); 
	gy30.begin(); 
}

void loop()
{
	airMoitor.displayTemperature(dht11.getTempCelcius());//上送温度
	airMoitor.displayHumidity(dht11.getHumidity());//上送湿度
	airMoitor.displayLightIntensity(gy30.Read());//上送光照强度
	airMoitor.displayPM25(gp2y10.CalculatedConcentration());//上送PM2.5值
	delay(3000);
}
