/*
 * Copyright 2014 Stefan Dörig sdoerig@bluewin.ch
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */


#include <iostream>
#include <stdlib.h>
#include "primeextractor.h"
using namespace std;




int main(int argc, char **argv) {
    
    char * pEnd;
    long range = strtol(argv[1], &pEnd, 10);
  
    PrimeExtractor * pe = new PrimeExtractor(range);
    pe->extract();
    
    delete pe;
    return 0;
    
}

