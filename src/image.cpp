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

#include "image.h"
#include "console.h"

Image::Image(const char* filename)
{
    // Load the texture
    texture = GPU_LoadImage(filename);
    
    // Error handling
    if(texture == nullptr){
        Console::Log(filename, ConsoleLineType::LoadError);
    }
    
    // Set image specs
    srcrect.w = texture->w;
    srcrect.h = texture->h;
    
    // Store globals pointer
    target = globals->window;    
}

Image::Image(const char* filename, GPU_Target* target)
{
    // Load the texture
    texture = GPU_LoadImage(filename);
    
    // Error handling
    if(texture == nullptr){
        Console::Log(filename, ConsoleLineType::LoadError);
    }
    
    // Set image specs
    srcrect.w = texture->w;
    srcrect.h = texture->h;
    
    // Store globals pointer
    this->target = target;    
}

Image::~Image()
{
    
}

void Image::Draw() {
    // Draw the texture using the stored variables
    GPU_Blit(texture, &srcrect, target, Position.x, Position.y);
}
