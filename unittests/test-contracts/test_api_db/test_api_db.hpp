#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] test_api_db : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action("pg")]]
   void primary_i64_general();

   [[lcscs::action("pl")]]
   void primary_i64_lowerbound();

   [[lcscs::action("pu")]]
   void primary_i64_upperbound();

   [[lcscs::action("s1g")]]
   void idx64_general();

   [[lcscs::action("s1l")]]
   void idx64_lowerbound();

   [[lcscs::action("s1u")]]
   void idx64_upperbound();

   [[lcscs::action("tia")]]
   void test_invalid_access( lcscs::name code, uint64_t val, uint32_t index, bool store );

   [[lcscs::action("sdnancreate")]]
   void idx_double_nan_create_fail();

   [[lcscs::action("sdnanmodify")]]
   void idx_double_nan_modify_fail();

   [[lcscs::action("sdnanlookup")]]
   void idx_double_nan_lookup_fail( uint32_t lookup_type );

   [[lcscs::action("sk32align")]]
   void misaligned_secondary_key256_tests();

};
