//
//  ofxALSoftBuffer.h
//  ofApp
//
//  Created by Ali Nakipoglu on 12/08/2013.
//
//

#ifndef ofApp_ofxALSoftBuffer_h
#define ofApp_ofxALSoftBuffer_h

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "ofMain.h"

class ofxALSoftBuffer
{
    
public:
    
    ofxALSoftBuffer()
    
    :alBufferID( 0 )
    ,dataSize( 0 )
    ,format( 0 )
    ,frequency( 0 )
    
    {};
    
    ~ofxALSoftBuffer()
    {};
    
public:
    
    const ALuint & getALBufferID() const
    {
        return alBufferID;
    };
    
    const long & getSize() const
    {
        return dataSize;
    };
    
    const ALenum & getFormat() const
    {
        return format;
    };
    
    const int & getFrequency() const
    {
        return frequency;
    };
    
    void allocate()
    {
        alGenBuffers( 1, &alBufferID );
    };
    
    void buffer( const ALvoid * data, const long dataSize_, const ALenum format_, const int frequency_ )
    {
        dataSize        = dataSize_;
        format          = format_;
        frequency       = frequency_;
        
        alBufferData( alBufferID, format_, data, dataSize_, frequency_ );
    };
    
    void destroy()
    {
        alDeleteBuffers( 1, &alBufferID );
        
        alBufferID  = 0;
    };

private:
    
    ALuint  alBufferID;
    
    long    dataSize;
    ALenum  format;
    int     frequency;

};

#endif
