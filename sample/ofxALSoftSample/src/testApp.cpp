#include "testApp.h"


void testApp::setup()
{
    ofEnableSmoothing();
    
    context.allocate();
    listener.allocate();
    buffer.allocate();
    source.allocate();
    
    ofxALSoftRAWLoader  rawLoader;
    
    rawLoader.load( ofToDataPath( SOUND_FILE ) );
    
    buffer.buffer( rawLoader.getData(), rawLoader.getSize(), AL_FORMAT_MONO16, 44100 );
    
    source.buffer( buffer );
    
    source.play();
    
    source.setReferenceDistance( 50.0f );
    source.setLooping( true );
    
    listener.setPosition( ofVec3f( ofGetWidth() * 0.5f, ofGetHeight() * 0.5f, 0.0f ) );
    listener.setOrientation( ofVec3f( 0, 0, -1 ) );
    listener.setUpVector( ofVec3f( 0, 1, 0 ) );
}

void testApp::update()
{
    context.update();
    listener.update();
    
    source.setPosition( ofVec3f( ofGetMouseX(), ofGetMouseY(), 0 ) );
    source.update();
}

void testApp::draw()
{
    ofClear( 0 );
    
    ofSetColor( ofColor::red );
    
    ofDrawSphere( source.getPosition(), 10.0f );
    
    ofSetColor( ofColor::yellow );
    
    ofDrawSphere( listener.getPosition(), 10.0f );
}

void testApp::keyPressed(int key)
{
    if( key == 'f' )
    {
        ofToggleFullscreen();
    }
}

void testApp::windowResized(int w, int h)
{
    listener.setPosition( ofVec3f( ofGetWidth() * 0.5f, ofGetHeight() * 0.5f, 0.0f ) );
}

void testApp::keyReleased(int key){}

void testApp::mouseMoved(int x, int y ){}

void testApp::mouseDragged(int x, int y, int button){}

void testApp::mousePressed(int x, int y, int button){}

void testApp::mouseReleased(int x, int y, int button){}

void testApp::exit()
{
    buffer.destroy();
    source.destroy();
    listener.destroy();
    context.destroy();
}