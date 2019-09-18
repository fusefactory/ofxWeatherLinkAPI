//
//  WeatherLinkManager.cpp
//  WeatherLinkExample
//
//  Created by Matteo on 17/09/2019.
//

#include "ofxWeatherLinkSettingsManager.h"

void ofxWeatherLinkSettingsManager::loadSettings(string filename){
    xmlSettings.load(filename);
}

string ofxWeatherLinkSettingsManager::getXmlUrl(){
    return xmlSettings.getAttribute("weatherlink:url", "xml", "");
}

string ofxWeatherLinkSettingsManager::getJsonUrl(){
    return xmlSettings.getAttribute("weatherlink:url", "json", "");
}

string ofxWeatherLinkSettingsManager::getUser(){
    return xmlSettings.getAttribute("weatherlink:authentication", "user", "");
}

string ofxWeatherLinkSettingsManager::getPass(){
    return xmlSettings.getAttribute("weatherlink:authentication", "pass", "");
}

string ofxWeatherLinkSettingsManager::getApiToken(){
    return xmlSettings.getAttribute("weatherlink:authentication", "apiToken", "");
}
