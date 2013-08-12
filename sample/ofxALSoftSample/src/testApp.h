#pragma once

#include <map>
#include <vector>

#include "ofMain.h"

#include "ofxALSoft.h"

#define SOUND_FILE      "Crow.raw"

class testApp : public ofBaseApp
{
    
public:
    
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
private:
    
private:
    
    ofxALSoftContext                context;
    ofxALSoftListener               listener;
    ofxALSoftBuffer                 buffer;
    ofxALSoftSource                 source;
    
};
