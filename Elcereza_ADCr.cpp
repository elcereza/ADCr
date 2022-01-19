/*  -----------------------------------------------------------------------------
    MIT License

    Copyright (c) 2022 Elcereza

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
    -----------------------------------------------------------------------------
*/

#include "Elcereza_ADCr.h"

ADCr::ADCr(bool j = false, int _rsADC = 0){
    if(_rsADC != 0)
    {
        int _ADC = 0;
        if(_rsADC < 256){
            _ADC = pow(2, _rsADC) - 1;
        }
        else
        {
            _ADC = _rsADC;
            if(_rsADC == 256) _ADC = _rsADC -1;
            else if(_rsADC == 1024) _ADC = _rsADC -1;
            else if(_rsADC == 2048) _ADC = _rsADC -1;
            else if(_rsADC == 4096) _ADC = _rsADC -1;
            else if(_rsADC == 65536) _ADC = _rsADC -1;
            else if(_rsADC == 16777216) _ADC = _rsADC -1;
        }
        if(_ADC != 0 && _ADC != rsADC){
            rsADC = _ADC;
        }
    }
}

int ADCr::reverse(int ad)
{
    double rADC = (ad - (rsADC - ((2 / (rsADC + 1))) * ad)) * -1;
    if(rADC < 0)
      rADC = 0;
    return int(rADC);
}
