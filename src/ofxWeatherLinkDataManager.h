//
//  ofxWeatherLinkDataManager.hpp
//  example
//
//  Created by Matteo on 18/09/2019.
//

#ifndef ofxWeatherLinkDataManager_hpp
#define ofxWeatherLinkDataManager_hpp

#include <stdio.h>
#include "ofxXmlSettings.h"
#include "ofxWeatherLinkAPIData.h"

class ofxWeatherLinkDataManager {

public:
    static void updateData(ofxXmlSettings &xml, ofxWeatherLinkAPIData &data);
    static float getPressureMb(ofxXmlSettings &xml);
    static float getRelativeHumidity(ofxXmlSettings &xml);
    static float getTempC(ofxXmlSettings &xml);
    static float getWindDegrees(ofxXmlSettings &xml);
    static float getWindMph(ofxXmlSettings &xml);
    static float getRainRateInPerHr(ofxXmlSettings &xml);
};
#endif /* ofxWeatherLinkDataManager_hpp */
