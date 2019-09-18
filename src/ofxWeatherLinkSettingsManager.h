//
//  WeatherLinkManager.hpp
//  WeatherLinkExample
//
//  Created by Matteo on 17/09/2019.
//

#ifndef WeatherLinkManager_hpp
#define WeatherLinkManager_hpp

#include <stdio.h>
#include "ofxXmlSettings.h"

class ofxWeatherLinkSettingsManager{
public:
    void loadSettings(string filename);
    string getXmlUrl();
    string getJsonUrl();
    string getUser();
    string getPass();
    string getApiToken();
    
private:
    ofxXmlSettings xmlSettings;
};
#endif /* WeatherLinkManager_hpp */
