#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] payloadless : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void doit();
};
