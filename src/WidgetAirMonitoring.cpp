
#include "WidgetAirMonitoring.h"


WidgetAirMonitoring::WidgetAirMonitoring(uint8_t ucItem)
{
    _Item = ucItem;
    memset(pDataHumidityTopic,0,sizeof(pDataHumidityTopic));
    memset(pDataTemperatureTopic,0,sizeof(pDataTemperatureTopic));
    memset(pDataLightIntensityTopic,0,sizeof(pDataLightIntensityTopic));
    memset(pDataPM25Topic,0,sizeof(pDataPM25Topic));

    sprintf(pDataHumidityTopic,"channel/airMonitoring_%d/data/airHumidity",_Item);
    sprintf(pDataTemperatureTopic,"channel/airMonitoring_%d/data/airTemp",_Item);
    sprintf(pDataLightIntensityTopic,"channel/airMonitoring_%d/data/illumination",_Item);
    sprintf(pDataPM25Topic,"channel/airMonitoring_%d/data/concentration",_Item);
}

WidgetAirMonitoring::~WidgetAirMonitoring()
{
    
}

void WidgetAirMonitoring::begin(void (*UserCallBack)(void))
{

}

void WidgetAirMonitoring::displayTemperature(float fTemperature)
{
	IntoRobot.publish(pDataTemperatureTopic,fTemperature);
}

void WidgetAirMonitoring::displayHumidity(float fHumidity)
{
	IntoRobot.publish(pDataHumidityTopic,fHumidity);
}

void WidgetAirMonitoring::displayLightIntensity(float fLightIntensity)
{
	IntoRobot.publish(pDataLightIntensityTopic,fLightIntensity);
}

void WidgetAirMonitoring::displayPM25(int iPM25)
{
	IntoRobot.publish(pDataPM25Topic,iPM25);
}





