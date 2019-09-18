//
//  WeatherLinkAPI.cpp
//  WeatherLinkExample
//
//  Created by Matteo on 17/09/2019.
//

#include "ofxWeatherLinkAPI.h"

ofxWeatherLinkAPI::ofxWeatherLinkAPI(){
    bLoadedData = false;
    bRequestData = false;
}

void ofxWeatherLinkAPI::setup(string settingsXml){
    ofxWeatherLinkSettingsManager weatherLinkSettingsManager;
    weatherLinkSettingsManager.loadSettings(settingsXml);
    
    string url = weatherLinkSettingsManager.getXmlUrl();
    string user = weatherLinkSettingsManager.getUser();
    string pass = weatherLinkSettingsManager.getPass();
    string apiToken = weatherLinkSettingsManager.getApiToken();

    setup(url, user, pass, apiToken);
}

void ofxWeatherLinkAPI::setup(string url, string user, string pass, string apiToken){
    ofxWeatherLinkAPI::url = url;
    ofxWeatherLinkAPI::user = user;
    ofxWeatherLinkAPI::pass = pass;
    ofxWeatherLinkAPI::apiToken = apiToken;
    
    fullUrl = url + "user=" + user + "&pass=" + pass;
    if(apiToken.size() > 1) fullUrl += "&apiToken=" + apiToken;
    
    ofRegisterURLNotification(this);
}

void ofxWeatherLinkAPI::requestAsyncDataFromAPI(){
    if(! bRequestData){
        bRequestData = true;
        ofLoadURLAsync(fullUrl, "weatherLinkAPI");
    }
}

void ofxWeatherLinkAPI::urlResponse(ofHttpResponse &httpResponse){
    if(httpResponse.status == 200 ){  // i.e is it ok
        //load response
        string response = httpResponse.data.getText();
        xmlData.loadFromBuffer(response);
        
        //get time for pickup
        suggestedPickupPeriod = xmlData.getValue("current_observation:suggested_pickup_period", 60);
        bLoadedData = true;

        //update data
        ofxWeatherLinkDataManager::updateData(xmlData, data);
        
        
        
        ofxWeatherLinkAPI &sender = *this;
        ofNotifyEvent(newData, sender, this);
    }
    else{
        cout << "ofxWeatherLink error retriving new data" << endl;
    }
    
    bRequestData = false;
}
