#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] restrict_action_test : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void noop( );

   [[lcscs::action]]
   void sendinline( lcscs::name authorizer );

   [[lcscs::action]]
   void senddefer( lcscs::name authorizer, uint32_t senderid );


   [[lcscs::action]]
   void notifyinline( lcscs::name acctonotify, lcscs::name authorizer );

   [[lcscs::action]]
   void notifydefer( lcscs::name acctonotify, lcscs::name authorizer, uint32_t senderid );

   [[lcscs::on_notify("testacc::notifyinline")]]
   void on_notify_inline( lcscs::name acctonotify, lcscs::name authorizer );

   [[lcscs::on_notify("testacc::notifydefer")]]
   void on_notify_defer( lcscs::name acctonotify, lcscs::name authorizer, uint32_t senderid );
};
