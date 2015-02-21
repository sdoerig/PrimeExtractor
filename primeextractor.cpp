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
  /**
   * The internal data structure consists of a vector of booleans.
   * Given a stop count indicating running until reaching this stop. The binary
   * vector size is just half of the stop count - since half of the numbers are
   * even and therefore not prime. So this leads considerung the iterations to
   * the example tables below. Under the title iterateVector are
   * - index within the vector
   * - value of that index
   * natural stands for the number represended by this index.
   * 
   * Init:
   * iterateVector  natural
   *  0    false        1
   *  1    true         3
   *  2    true         5
   *  3    true         7
   *  4    true         9
   *  5    true        11 
   *  6    true        13
   *  7    true        15
   *  8    true        17
   *  9    true        19
   * 10    true        21
   * 11    true        23
   * 12    true        25
   *
   * First interation:
   * findNextStep returns 1 * 2 + 1 = 3
   * iterateVector  natural
   *  0    false        1
   *  1    true         3
   *  2    true         5
   *  3    true         7
   *  4    false        9
   *  5    true        11 
   *  6    true        13
   *  7    false       15
   *  8    true        17
   *  9    true        19
   * 10    false       21
   * 11    true        23
   * 12    true        25
   *
   * Second iteration:
   * findNextStep returns 2 * 2 +1 = 5
   * iterateVector  natural
   *  0    false        1
   *  1    true         3
   *  2    true         5
   *  3    true         7
   *  4    false        9
   *  5    true        11 
   *  6    true        13
   *  7    false       15
   *  8    true        17
   *  9    true        19
   * 10    false       21
   * 11    true        23
   * 12    false       25
   *
   **/
  long stop_limited = stop / 2 + 1;
  
  this->stop = stop ;
  this->primeCand.resize(stop_limited + 1);
  this->stopSqrt = (long)ceil(sqrt(stop));
  for(long i = 0; i < this->primeCand.size()  ; i++) {
    this->primeCand[i] = true;
  }
  this->primeCand[1] = true;
}

void PrimeExtractor::extract()
{
    long step = this->findNextStep();
    
    do {
      this->iterateVector(step);
      step = this->findNextStep();
    } while (step > 0 && step <= this->stopSqrt);
    if (this->stop >=2) {
      /**
       * Note: with the procedure described above 2 will never be 
       * calculated but it's prime.
       **/
      std::cout << 2 << std::endl;
    }
    for(long i = 1; i < this->primeCand.size() ; i++) {
      if (this->primeCand[i] == true) {
	  std::cout << i * 2 + 1 << std::endl;
      } 
	
    }
}


long PrimeExtractor::findNextStep()
{
  for (long i = this->lastStep +1; i < this->primeCand.size(); i++) {
    if (this->primeCand[i] == true) {
      this->lastStep = i;
      return i*2+1 ;
    } 
  }
  return 0;
}

 
void PrimeExtractor::iterateVector(long step)
{
  for(long i = this->lastStep + step; i < this->primeCand.size(); i = i + step) {
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




