//
//  ofxALSoftRAWLoader.h
//  ofApp
//
//  Created by Ali Nakipoglu on 12/08/2013.
//
//

#ifndef ofApp_ofxALSoftRAWLoader_h
#define ofApp_ofxALSoftRAWLoader_h

#include <string>
#include <stdlib.h>
#include <stdio.h>

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "ofMain.h"

class ofxALSoftRAWLoader
{
    
public:
    
    ofxALSoftRAWLoader()
    
    :data( NULL )
    ,size( 0 )
    
    {};
    
    ~ofxALSoftRAWLoader()
    {};
    
public:
    
    const void * getData() const
    {
        return data;
    };
    
    const long & getSize() const
    {
        return size;
    };
    
    void load( const std::string & filePath )
    {
        FILE    *filePointer    = fopen( filePath.c_str(), "rb" );
        
        fseek( filePointer, 0L, SEEK_END );
        
        size                    = ftell( filePointer );
        data                    = malloc( size );
        
        rewind( filePointer );
        
        fread( data, 1, size, filePointer );
        fclose( filePointer );
    };
    
private:
    
    void*   data;
    long    size;
    
};


#endif
