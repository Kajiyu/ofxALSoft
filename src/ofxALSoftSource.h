//
//  ofxALSoftSource.h
//  ofApp
//
//  Created by Ali Nakipoglu on 12/08/2013.
//
//

#ifndef ofApp_ofxALSoftSource_h
#define ofApp_ofxALSoftSource_h

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "ofMain.h"

#include "ofxALSoftBuffer.h"

class ofxALSoftSource
{
    
public:
    
    ofxALSoftSource()
    
    :alSourceID( 0 )
    ,pitch( 1.0f )
    ,gain( 1.0f )
    ,isLooping( false )
    
    {};
    
    ~ofxALSoftSource()
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
    
    void setPitch( const float value )
    {
        pitch       = value;
    };
    
    void setGain( const float value )
    {
        gain        = value;
    };
    
    void setLooping( const bool value )
    {
        isLooping   = value;
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
    
    const float getPitch() const
    {
        return pitch;
    };
    
    const float getGain() const
    {
        return gain;
    };
    
    const bool getLooping() const
    {
        return isLooping;
    };
    
    const ALuint getALSourceID() const
    {
        return alSourceID;
    };
    
    void play()
    {
        alSourcePlay( alSourceID );
    };
    
    void pause()
    {
        alSourcePause( alSourceID );
    };
    
    void stop()
    {
        alSourceStop( alSourceID );
    };
    
    void allocate()
    {
        alGenSources( 1, &alSourceID );
    };
    
    void buffer( const ofxALSoftBuffer & buffer )
    {
        alSourcei( alSourceID, AL_BUFFER, buffer.getALBufferID() );
    };
    
    void destroy()
    {
        alDeleteSources( 1, &alSourceID );
        
        alSourceID  = 0;
    };
    
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
        
        alSourcefv( alSourceID, AL_POSITION, position.getPtr() );
        alSourcefv( alSourceID, AL_ORIENTATION, orientationAndUpVector );
        alSourcefv( alSourceID, AL_VELOCITY, velocity.getPtr() );
        
        alSourcef( alSourceID, AL_PITCH, pitch );
        alSourcef( alSourceID, AL_GAIN, gain );
        alSourcei( alSourceID, AL_LOOPING, isLooping ? AL_TRUE : AL_FALSE );
    };
    
private:
    
    ALuint      alSourceID;
    
    ofVec3f     position;
    ofVec3f     orientation;
    ofVec3f     upVector;
    ofVec3f     velocity;
    
    float       pitch;
    float       gain;
    
    bool        isLooping;
    
};

#endif
