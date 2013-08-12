//
//  ofxALSoftListener.h
//  ofApp
//
//  Created by Ali Nakipoglu on 12/08/2013.
//
//

#ifndef ofApp_ofxALSoftListener_h
#define ofApp_ofxALSoftListener_h

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "ofMain.h"

class ofxALSoftListener
{
    
public:
    
    ofxALSoftListener()
    {};
    
    ~ofxALSoftListener()
    {};
    
public:
    
    void setPosition( const ofVec3f &value )
    {
        position.set( value );
    };
    
    void setOrientation( const ofVec3f &value )
    {
        orientation.set( value );
    };
    
    void setUpVector( const ofVec3f &value )
    {
        upVector.set( value );
    };
    
    void setVelocity( const ofVec3f &value )
    {
        velocity.set( value );
    };
    
    const ofVec3f & getPosition() const
    {
        return position;
    };
    
    const ofVec3f & getOrientation() const
    {
        return orientation;
    };
    
    const ofVec3f & getUpVector() const
    {
        return upVector;
    };
    
    const ofVec3f & getVelocity() const
    {
        return velocity;
    };
    
    void allocate()
    {};
    
    void destroy()
    {};
    
    void update()
    {
        float orientationAndUpVector[6] =
        {
            orientation.x,
            orientation.y,
            orientation.z,
            upVector.x,
            upVector.y,
            upVector.z
        };
        
        alListenerfv( AL_POSITION, position.getPtr() );
        alListenerfv( AL_ORIENTATION, orientationAndUpVector );
        alListenerfv( AL_VELOCITY, velocity.getPtr() );
    };
    
private:
    
    ofVec3f     position;
    ofVec3f     orientation;
    ofVec3f     upVector;
    ofVec3f     velocity;
    
};


#endif
