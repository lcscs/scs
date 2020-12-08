#pragma once

#include <lcscs/lcscs.hpp>

class [[lcscs::contract]] test_api_multi_index : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action("s1g")]]
   void idx64_general();

   [[lcscs::action("s1store")]]
   void idx64_store_only();

   [[lcscs::action("s1check")]]
   void idx64_check_without_storing();

   [[lcscs::action("s1findfail1")]]
   void idx64_require_find_fail();

   [[lcscs::action("s1findfail2")]]
   void idx64_require_find_fail_with_msg();

   [[lcscs::action("s1findfail3")]]
   void idx64_require_find_sk_fail();

   [[lcscs::action("s1findfail4")]]
   void idx64_require_find_sk_fail_with_msg();

   [[lcscs::action("s1pkend")]]
   void idx64_pk_iterator_exceed_end();

   [[lcscs::action("s1skend")]]
   void idx64_sk_iterator_exceed_end();

   [[lcscs::action("s1pkbegin")]]
   void idx64_pk_iterator_exceed_begin();

   [[lcscs::action("s1skbegin")]]
   void idx64_sk_iterator_exceed_begin();

   [[lcscs::action("s1pkref")]]
   void idx64_pass_pk_ref_to_other_table();

   [[lcscs::action("s1skref")]]
   void idx64_pass_sk_ref_to_other_table();

   [[lcscs::action("s1pkitrto")]]
   void idx64_pass_pk_end_itr_to_iterator_to();

   [[lcscs::action("s1pkmodify")]]
   void idx64_pass_pk_end_itr_to_modify();

   [[lcscs::action("s1pkerase")]]
   void idx64_pass_pk_end_itr_to_erase();

   [[lcscs::action("s1skitrto")]]
   void idx64_pass_sk_end_itr_to_iterator_to();

   [[lcscs::action("s1skmodify")]]
   void idx64_pass_sk_end_itr_to_modify();

   [[lcscs::action("s1skerase")]]
   void idx64_pass_sk_end_itr_to_erase();

   [[lcscs::action("s1modpk")]]
   void idx64_modify_primary_key();

   [[lcscs::action("s1exhaustpk")]]
   void idx64_run_out_of_avl_pk();

   [[lcscs::action("s1skcache")]]
   void idx64_sk_cache_pk_lookup();

   [[lcscs::action("s1pkcache")]]
   void idx64_pk_cache_sk_lookup();

   [[lcscs::action("s2g")]]
   void idx128_general();

   [[lcscs::action("s2store")]]
   void idx128_store_only();

   [[lcscs::action("s2check")]]
   void idx128_check_without_storing();

   [[lcscs::action("s2autoinc")]]
   void idx128_autoincrement_test();

   [[lcscs::action("s2autoinc1")]]
   void idx128_autoincrement_test_part1();

   [[lcscs::action("s2autoinc2")]]
   void idx128_autoincrement_test_part2();

   [[lcscs::action("s3g")]]
   void idx256_general();

   [[lcscs::action("sdg")]]
   void idx_double_general();

   [[lcscs::action("sldg")]]
   void idx_long_double_general();

};
