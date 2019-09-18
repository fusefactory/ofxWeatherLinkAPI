//
//  ofxWeatherLinkDataManager.cpp
//  example
//
//  Created by Matteo on 18/09/2019.
//

#include "ofxWeatherLinkDataManager.h"
#include <ctime>

void ofxWeatherLinkDataManager::updateData(ofxXmlSettings &xml, ofxWeatherLinkAPIData &data){
    data.pressureMb = getPressureMb(xml);
    data.relativeHumidity = getRelativeHumidity(xml);
    data.tempC = getTempC(xml);
    data.windDegrees = getWindDegrees(xml);
    data.windMph = getWindMph(xml);
    data.rainRateInPerHr = getRainRateInPerHr((xml));
    data.timeLastUpdate = time(0);
}

float ofxWeatherLinkDataManager::getPressureMb(ofxXmlSettings &xml){
    return xml.getValue("current_observation:pressure_mb", 0.0f);
}

float ofxWeatherLinkDataManager::getRelativeHumidity(ofxXmlSettings &xml){
    return xml.getValue("current_observation:relative_humidity", 0.0f);
}

float ofxWeatherLinkDataManager::getTempC(ofxXmlSettings &xml){
    return xml.getValue("current_observation:temp_c", 0.0f);
}

float ofxWeatherLinkDataManager::getWindDegrees(ofxXmlSettings &xml){
    return xml.getValue("current_observation:wind_degrees", 0.0f);
}

float ofxWeatherLinkDataManager::getWindMph(ofxXmlSettings &xml){
    return xml.getValue("current_observation:wind_mph", 0.0f);
}

float ofxWeatherLinkDataManager::getRainRateInPerHr(ofxXmlSettings &xml){
    return xml.getValue("current_observation:davis_current_observation:rain_rate_in_per_hr", 0.0f);
}

