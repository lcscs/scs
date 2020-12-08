#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] asserter : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void procassert( int8_t condition, std::string message );

   [[lcscs::action]]
   void provereset();
};
