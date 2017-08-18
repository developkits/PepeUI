/*
 * Copyright (c) 2017 Anas Youssef Idiab candfa2660@gmail.com
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#ifndef GLOBALS_H
#define GLOBALS_H

// Includes
#include "includes.h"
#include "enums.h"


// Capture struct
struct CaptureInfo{
    const char* drawableID;
    bool        useTextInput;
    bool        mouseCaptured;
};

// Global variable structure
struct Globals {
    SDL_Color       BackgroundColor     = {40,40,40,255};
    std::string     WindowTitle         = "Dank Music Machine";
    bool            shouldQuit          = false;
    GPU_Target*     window;
    bool            shouldRefresh       = true;

    std::vector<CaptureInfo> CaptureStack = std::vector<CaptureInfo>();
};

// Application context that includes pointers to relevant information
/*struct ApplicationContext {
    Globals*    globals;
    GPU_Target* target;
};*/

#endif // GLOBALS_H
