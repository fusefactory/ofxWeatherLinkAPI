//
//  ofxWeatherLinkAPIBasicData.hpp
//  example
//
//  Created by Matteo on 18/09/2019.
//

#ifndef ofxWeatherLinkAPIBasicData_hpp
#define ofxWeatherLinkAPIBasicData_hpp

#include <stdio.h>
#include <ctime>

class ofxWeatherLinkAPIData {
public:
    ofxWeatherLinkAPIData();
    
    time_t timeLastUpdate;
    float pressureMb;
    float relativeHumidity;
    float tempC;
    float windDegrees;
    float windMph;
    float rainRateInPerHr;
};

#endif /* ofxWeatherLinkAPIBasicData_hpp */
