#ifndef CATAPULT_HPP
#define CATAPULT_HPP

namespace Catapult{
  extern bool Shoot;

  extern bool Charged;
  extern int ChargeSenseValue;
  extern int ChargeMaxValue;

  void catapultTaskChargeFire(void*CatapultTask);
}

#endif /* end of include guard: CATAPULT_HPP */
