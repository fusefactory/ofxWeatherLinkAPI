//
//  WeatherLinkAPI.hpp
//  WeatherLinkExample
//
//  Created by Matteo on 17/09/2019.
//

#ifndef WeatherLinkAPI_hpp
#define WeatherLinkAPI_hpp

#include "ofxWeatherLinkSettingsManager.h"
#include "ofxWeatherLinkAPIData.h"
#include "ofxWeatherLinkDataManager.h"

#include <stdio.h>
#include "ofMain.h"
#include "ofxXmlSettings.h"

class ofxWeatherLinkAPI{
    
public:
    ofxWeatherLinkAPI();
    
    ofEvent<ofxWeatherLinkAPI> newData;
    
    void setup(string settingsXml);
    void setup(string url, string user, string pass, string apiToken);
    void requestAsyncDataFromAPI(); 
    
    ofxWeatherLinkAPIData &getData(){return data;}
    ofxXmlSettings &getXmlData(){return xmlData;}
    bool isLoadedData(){return bLoadedData;}
    bool isRequestData(){return bRequestData;}
    float getSuggestedPickupPeriod(){return suggestedPickupPeriod;}
    
    void urlResponse(ofHttpResponse &httpResponse);
private:
    bool bLoadedData, bRequestData;
    string fullUrl;
    string url;
    string user;
    string pass;
    string apiToken;
    
    int suggestedPickupPeriod = 60;
    
    ofxWeatherLinkAPIData data;
    ofxXmlSettings xmlData;
};

#endif /* WeatherLinkAPI_hpp */
