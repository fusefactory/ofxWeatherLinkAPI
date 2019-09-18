//
//  ofxWeatherLinkAPIData.cpp
//  example
//
//  Created by Matteo on 18/09/2019.
//

#include "ofxWeatherLinkAPIData.h"

ofxWeatherLinkAPIData::ofxWeatherLinkAPIData(){
    timeLastUpdate = -1;
    pressureMb = 0;
    relativeHumidity = 0;
    tempC = 0;
    windDegrees = 0;
    windMph = 0;
    rainRateInPerHr = 0;
}
