#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] integration_test : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void store( lcscs::name from, lcscs::name to, uint64_t num );

   struct [[lcscs::table("payloads")]] payload {
      uint64_t              key;
      std::vector<uint64_t> data;

      uint64_t primary_key()const { return key; }

      scsLIB_SERIALIZE( payload, (key)(data) )
   };

   using payloads_table = lcscs::multi_index< "payloads"_n,  payload >;

};
