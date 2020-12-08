#pragma once

#include <lcscs/lcscs.hpp>
#include <vector>

class [[lcscs::contract]] deferred_test : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void defercall( lcscs::name payer, uint64_t sender_id, lcscs::name contract, uint64_t payload );

   [[lcscs::action]]
   void delayedcall( lcscs::name payer, uint64_t sender_id, lcscs::name contract,
                     uint64_t payload, uint32_t delay_sec, bool replace_existing );

   [[lcscs::action]]
   void deferfunc( uint64_t payload );
   using deferfunc_action = lcscs::action_wrapper<"deferfunc"_n, &deferred_test::deferfunc>;

   [[lcscs::action]]
   void inlinecall( lcscs::name contract, lcscs::name authorizer, uint64_t payload );

   [[lcscs::action]]
   void fail();

   [[lcscs::on_notify("lcscs::onerror")]]
   void on_error( uint128_t sender_id, lcscs::ignore<std::vector<char>> sent_trx );
};
