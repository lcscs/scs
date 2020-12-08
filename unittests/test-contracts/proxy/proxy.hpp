#pragma once

#include <lcscs/lcscs.hpp>
#include <lcscs/singleton.hpp>
#include <lcscs/asset.hpp>

// Extacted from lcscs.token contract:
namespace lcscs {
   class [[lcscs::contract("lcscs.token")]] token : public lcscs::contract {
   public:
      using lcscs::contract::contract;

      [[lcscs::action]]
      void transfer( lcscs::name        from,
                     lcscs::name        to,
                     lcscs::asset       quantity,
                     const std::string& memo );
      using transfer_action = lcscs::action_wrapper<"transfer"_n, &token::transfer>;
   };
}

// This contract:
class [[lcscs::contract]] proxy : public lcscs::contract {
public:
   proxy( lcscs::name self, lcscs::name first_receiver, lcscs::datastream<const char*> ds );

   [[lcscs::action]]
   void setowner( lcscs::name owner, uint32_t delay );

   [[lcscs::on_notify("lcscs.token::transfer")]]
   void on_transfer( lcscs::name        from,
                     lcscs::name        to,
                     lcscs::asset       quantity,
                     const std::string& memo );

   [[lcscs::on_notify("lcscs::onerror")]]
   void on_error( uint128_t sender_id, lcscs::ignore<std::vector<char>> sent_trx );

   struct [[lcscs::table]] config {
      lcscs::name owner;
      uint32_t    delay   = 0;
      uint32_t    next_id = 0;

      scsLIB_SERIALIZE( config, (owner)(delay)(next_id) )
   };

   using config_singleton = lcscs::singleton< "config"_n,  config >;

protected:
   config_singleton _config;
};
