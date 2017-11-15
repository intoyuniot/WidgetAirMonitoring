#ifndef WIDGET_AIR_MONITORING_H_
#define WIDGET_AIR_MONITORING_H_

#include "application.h"


class WidgetAirMonitoring
{
public:
    WidgetAirMonitoring(uint8_t ucItem = 0);
    ~WidgetAirMonitoring();
    void begin(void (*UserCallBack)(void) = NULL);
    void displayTemperature(float fTemperature);
    void displayHumidity(float fHumidity);
    void displayLightIntensity(float fLightIntensity);
    void displayPM25(int iPM25);
    
private:
    char pDataHumidityTopic[64];
    char pDataTemperatureTopic[64];
    char pDataLightIntensityTopic[64];
    char pDataPM25Topic[64];
    uint8_t _Item=0;         
};

#endif
