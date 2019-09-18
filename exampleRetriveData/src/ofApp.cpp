#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    ofAddListener(weatherLinkAPI.newData, this, &ofApp::newDataofxWeatherLinkAPI);
    weatherLinkAPI.setup("weatherlink_settings_demo.xml");
    weatherLinkAPI.requestAsyncDataFromAPI();   //async
    
}

void ofApp::newDataofxWeatherLinkAPI(ofxWeatherLinkAPI & weatherLinkAPI){
    cout << "newDataofxWeatherLinkAPI" << endl;
    weatherLinkAPI.getXmlData().save("data.xml");   //save to file
}

//--------------------------------------------------------------
void ofApp::update(){
    time_t currTime = time(0);
    
    //request new data every 60 secons
    if(weatherLinkAPI.isLoadedData() && currTime - weatherLinkAPI.getData().timeLastUpdate > weatherLinkAPI.getSuggestedPickupPeriod()){
        weatherLinkAPI.requestAsyncDataFromAPI();   //async
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    if(weatherLinkAPI.isLoadedData()){
        string observationTime = "Observation time: " + weatherLinkAPI.getXmlData().getValue("current_observation:observation_time", "");
        string lastUpdate = "Last update: " + ofToString(ctime(&weatherLinkAPI.getData().timeLastUpdate));
        string pressure = "Pressure mb: " +  ofToString(weatherLinkAPI.getData().pressureMb);
        string relativehumidity = "Relative humidity: " +  ofToString(weatherLinkAPI.getData().relativeHumidity);
        string tempc = "Temp C: " +  ofToString(weatherLinkAPI.getData().tempC);
        string winddegrees = "Wind degrees: " +  ofToString(weatherLinkAPI.getData().windDegrees);
        string windwmph = "Wind mph: " +  ofToString(weatherLinkAPI.getData().windMph);
        string reainRate = "Rain rate in per hr " +  ofToString(weatherLinkAPI.getData().rainRateInPerHr);
       
        ofDrawBitmapString(observationTime, 10, 60);
        ofDrawBitmapString(lastUpdate, 10, 80);
        ofDrawBitmapString(pressure, 10, 100);
        ofDrawBitmapString(relativehumidity, 10, 120);
        ofDrawBitmapString(tempc, 10, 140);
        ofDrawBitmapString(winddegrees, 10, 160);
        ofDrawBitmapString(windwmph, 10, 180);
        ofDrawBitmapString(reainRate, 10, 200);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
