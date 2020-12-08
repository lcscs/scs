#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] ram_restrictions_test : public lcscs::contract {
public:
   struct [[lcscs::table]] data {
      uint64_t           key;
      std::vector<char>  value;

      uint64_t primary_key() const { return key; }
   };

   typedef lcscs::multi_index<"tablea"_n, data> tablea;
   typedef lcscs::multi_index<"tableb"_n, data> tableb;

public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void noop();

   [[lcscs::action]]
   void setdata( uint32_t len1, uint32_t len2, lcscs::name payer );

   [[lcscs::action]]
   void notifysetdat( lcscs::name acctonotify, uint32_t len1, uint32_t len2, lcscs::name payer );

   [[lcscs::on_notify("tester2::notifysetdat")]]
   void on_notify_setdata( lcscs::name acctonotify, uint32_t len1, uint32_t len2, lcscs::name payer );

   [[lcscs::action]]
   void senddefer( uint64_t senderid, lcscs::name payer );

   [[lcscs::action]]
   void notifydefer( lcscs::name acctonotify, uint64_t senderid, lcscs::name payer );

   [[lcscs::on_notify("tester2::notifydefer")]]
   void on_notifydefer( lcscs::name acctonotify, uint64_t senderid, lcscs::name payer );

};
