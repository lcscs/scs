#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] noop : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void anyaction( lcscs::name                       from,
                   const lcscs::ignore<std::string>& type,
                   const lcscs::ignore<std::string>& data );
};
