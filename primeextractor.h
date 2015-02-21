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

#ifndef PRIMEEXTRACTOR_H
#define PRIMEEXTRACTOR_H
#include <vector>

class PrimeExtractor
{
  public:
    PrimeExtractor();
    PrimeExtractor(long stop);
    PrimeExtractor(const PrimeExtractor& other);
    ~PrimeExtractor();
    void extract();
  

  private:
    long findNextStep();
    void iterateVector(long step = 3); 
    
    long lastStep;
    long stop;
    long stopSqrt;
    std::vector<bool> primeCand;

};

#endif // PRIMEEXTRACTOR_H
