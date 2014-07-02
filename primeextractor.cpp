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

#include "primeextractor.h"
#include <iostream>
#include <math.h>
PrimeExtractor::PrimeExtractor()
{

}



PrimeExtractor::PrimeExtractor(long stop)
{
  this->stop = stop;
  this->primeCand.resize(stop + 1);
  this->stopSqrt = (long)floor(sqrt(stop));
  for(long i = 0; i < this->primeCand.size()  ; i = i + 2) {
    this->primeCand[i] = false;
    this->primeCand[i + 1] = true;
  }
  this->primeCand[2] = true;
}

void PrimeExtractor::extract()
{
    //std::cout << 2 << std::endl;
    long step = this->findNextStep(2);

    do {
      //std::cout << step << std::endl;
      this->iterateVector(step);
      step = this->findNextStep(step);
    } while (step > 0 && step <= this->stopSqrt);
    
    for(long i = 2; i < this->primeCand.size() ; i++) {
      if (this->primeCand[i] == true) {
	  std::cout << i << std::endl;
      } 
	
    }
}


long PrimeExtractor::findNextStep(long lastStep)
{
  for (long i = lastStep + 1; i < this->primeCand.size(); i++) {
    if (this->primeCand[i] == true) {
      return i;
    } 
  }
  return 0;
}

 
void PrimeExtractor::iterateVector(long step)
{
  for(long i = step + step  ; i < this->primeCand.size(); i = i + step) {
    this->primeCand[i] = false;
  }
  
}




PrimeExtractor::PrimeExtractor(const PrimeExtractor& other)
{

}

PrimeExtractor::~PrimeExtractor()
{
  this->primeCand.clear();
 
}




