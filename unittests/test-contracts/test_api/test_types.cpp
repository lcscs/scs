#include <lcscslib/lcscs.hpp>

#include "test_api.hpp"

void test_types::types_size() {

   lcscs_assert( sizeof(int64_t)   ==  8, "int64_t size != 8"   );
   lcscs_assert( sizeof(uint64_t)  ==  8, "uint64_t size != 8"  );
   lcscs_assert( sizeof(uint32_t)  ==  4, "uint32_t size != 4"  );
   lcscs_assert( sizeof(int32_t)   ==  4, "int32_t size != 4"   );
   lcscs_assert( sizeof(uint128_t) == 16, "uint128_t size != 16");
   lcscs_assert( sizeof(int128_t)  == 16, "int128_t size != 16" );
   lcscs_assert( sizeof(uint8_t)   ==  1, "uint8_t size != 1"   );

   lcscs_assert( sizeof(lcscs::name) ==  8, "name size !=  8");
}

void test_types::char_to_symbol() {

   lcscs_assert( lcscs::name::char_to_value('1') ==  1, "lcscs::char_to_symbol('1') !=  1" );
   lcscs_assert( lcscs::name::char_to_value('2') ==  2, "lcscs::char_to_symbol('2') !=  2" );
   lcscs_assert( lcscs::name::char_to_value('3') ==  3, "lcscs::char_to_symbol('3') !=  3" );
   lcscs_assert( lcscs::name::char_to_value('4') ==  4, "lcscs::char_to_symbol('4') !=  4" );
   lcscs_assert( lcscs::name::char_to_value('5') ==  5, "lcscs::char_to_symbol('5') !=  5" );
   lcscs_assert( lcscs::name::char_to_value('a') ==  6, "lcscs::char_to_symbol('a') !=  6" );
   lcscs_assert( lcscs::name::char_to_value('b') ==  7, "lcscs::char_to_symbol('b') !=  7" );
   lcscs_assert( lcscs::name::char_to_value('c') ==  8, "lcscs::char_to_symbol('c') !=  8" );
   lcscs_assert( lcscs::name::char_to_value('d') ==  9, "lcscs::char_to_symbol('d') !=  9" );
   lcscs_assert( lcscs::name::char_to_value('e') == 10, "lcscs::char_to_symbol('e') != 10" );
   lcscs_assert( lcscs::name::char_to_value('f') == 11, "lcscs::char_to_symbol('f') != 11" );
   lcscs_assert( lcscs::name::char_to_value('g') == 12, "lcscs::char_to_symbol('g') != 12" );
   lcscs_assert( lcscs::name::char_to_value('h') == 13, "lcscs::char_to_symbol('h') != 13" );
   lcscs_assert( lcscs::name::char_to_value('i') == 14, "lcscs::char_to_symbol('i') != 14" );
   lcscs_assert( lcscs::name::char_to_value('j') == 15, "lcscs::char_to_symbol('j') != 15" );
   lcscs_assert( lcscs::name::char_to_value('k') == 16, "lcscs::char_to_symbol('k') != 16" );
   lcscs_assert( lcscs::name::char_to_value('l') == 17, "lcscs::char_to_symbol('l') != 17" );
   lcscs_assert( lcscs::name::char_to_value('m') == 18, "lcscs::char_to_symbol('m') != 18" );
   lcscs_assert( lcscs::name::char_to_value('n') == 19, "lcscs::char_to_symbol('n') != 19" );
   lcscs_assert( lcscs::name::char_to_value('o') == 20, "lcscs::char_to_symbol('o') != 20" );
   lcscs_assert( lcscs::name::char_to_value('p') == 21, "lcscs::char_to_symbol('p') != 21" );
   lcscs_assert( lcscs::name::char_to_value('q') == 22, "lcscs::char_to_symbol('q') != 22" );
   lcscs_assert( lcscs::name::char_to_value('r') == 23, "lcscs::char_to_symbol('r') != 23" );
   lcscs_assert( lcscs::name::char_to_value('s') == 24, "lcscs::char_to_symbol('s') != 24" );
   lcscs_assert( lcscs::name::char_to_value('t') == 25, "lcscs::char_to_symbol('t') != 25" );
   lcscs_assert( lcscs::name::char_to_value('u') == 26, "lcscs::char_to_symbol('u') != 26" );
   lcscs_assert( lcscs::name::char_to_value('v') == 27, "lcscs::char_to_symbol('v') != 27" );
   lcscs_assert( lcscs::name::char_to_value('w') == 28, "lcscs::char_to_symbol('w') != 28" );
   lcscs_assert( lcscs::name::char_to_value('x') == 29, "lcscs::char_to_symbol('x') != 29" );
   lcscs_assert( lcscs::name::char_to_value('y') == 30, "lcscs::char_to_symbol('y') != 30" );
   lcscs_assert( lcscs::name::char_to_value('z') == 31, "lcscs::char_to_symbol('z') != 31" );

   for(unsigned char i = 0; i<255; i++) {
      if( (i >= 'a' && i <= 'z') || (i >= '1' || i <= '5') ) continue;
      lcscs_assert( lcscs::name::char_to_value((char)i) == 0, "lcscs::char_to_symbol() != 0" );
   }
}

void test_types::string_to_name() {
   return;
   lcscs_assert( lcscs::name("a") == "a"_n, "lcscs::string_to_name(a)" );
   lcscs_assert( lcscs::name("ba") == "ba"_n, "lcscs::string_to_name(ba)" );
   lcscs_assert( lcscs::name("cba") == "cba"_n, "lcscs::string_to_name(cba)" );
   lcscs_assert( lcscs::name("dcba") == "dcba"_n, "lcscs::string_to_name(dcba)" );
   lcscs_assert( lcscs::name("edcba") == "edcba"_n, "lcscs::string_to_name(edcba)" );
   lcscs_assert( lcscs::name("fedcba") == "fedcba"_n, "lcscs::string_to_name(fedcba)" );
   lcscs_assert( lcscs::name("gfedcba") == "gfedcba"_n, "lcscs::string_to_name(gfedcba)" );
   lcscs_assert( lcscs::name("hgfedcba") == "hgfedcba"_n, "lcscs::string_to_name(hgfedcba)" );
   lcscs_assert( lcscs::name("ihgfedcba") == "ihgfedcba"_n, "lcscs::string_to_name(ihgfedcba)" );
   lcscs_assert( lcscs::name("jihgfedcba") == "jihgfedcba"_n, "lcscs::string_to_name(jihgfedcba)" );
   lcscs_assert( lcscs::name("kjihgfedcba") == "kjihgfedcba"_n, "lcscs::string_to_name(kjihgfedcba)" );
   lcscs_assert( lcscs::name("lkjihgfedcba") == "lkjihgfedcba"_n, "lcscs::string_to_name(lkjihgfedcba)" );
   lcscs_assert( lcscs::name("mlkjihgfedcba") == "mlkjihgfedcba"_n, "lcscs::string_to_name(mlkjihgfedcba)" );
}
