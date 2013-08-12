//
//  ofxALSoftContext.h
//  ofApp
//
//  Created by Ali Nakipoglu on 12/08/2013.
//
//

#ifndef ofApp_ofxALSoftContext_h
#define ofApp_ofxALSoftContext_h

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "ofMain.h"

class ofxALSoftContext
{
    
public:
    
    ofxALSoftContext()
    
    :device( NULL )
    ,context( NULL )
    
    {};
    
    
    ~ofxALSoftContext()
    {};
    
public:
    
    void allocate()
    {
        ALCint  contextAttr[]   = { ALC_FREQUENCY, 44100, 0 };
        
        device                  = alcOpenDevice( NULL );
        context                 = alcCreateContext( device, contextAttr );
        
        alcMakeContextCurrent( context );
        
        ofLog( OF_LOG_VERBOSE,  "Initialized OpenAL Soft Context" );
        ofLog( OF_LOG_VERBOSE,  alGetString(AL_VERSION) );
        ofLog( OF_LOG_VERBOSE,  alGetString(AL_RENDERER) );
    };
    
    void destroy()
    {
        alcDestroyContext( context );
        alcCloseDevice( device );
        
        context = NULL;
        device  = NULL;
    };
    
    void update()
    {};
    
    void setCurrent()
    {
        alcMakeContextCurrent( context );
    };
    
private:
    
    ALCdevice   *device;
    ALCcontext  *context;
};

#endif
