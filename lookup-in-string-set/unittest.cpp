#include <cstdio>
#include "hash.cpp.in"
#include "pext.cpp.in"
#include "generated/hash_ada-pred.cpp"
#include "generated/hash_ada-res.cpp"
#include "generated/hash_ada.cpp"
#include "generated/hash_adadefs.cpp"
#include "generated/hash_c.cpp"
#include "generated/hash_countries.cpp"
#include "generated/hash_cplusplus.cpp"
#include "generated/hash_cpp.cpp"
#include "generated/hash_go.cpp"
#include "generated/hash_gpc.cpp"
#include "generated/hash_irc.cpp"
#include "generated/hash_java.cpp"
#include "generated/hash_jscript.cpp"
#include "generated/hash_modula.cpp"
#include "generated/hash_modula2.cpp"
#include "generated/hash_modula3.cpp"
#include "generated/hash_pascal.cpp"
#include "generated/hash_sneller.cpp"
#include "generated/hash_snellerbuiltin.cpp"
#include "generated/hash_states.cpp"
#include "generated/pext_ada-pred.cpp"
#include "generated/pext_ada-res.cpp"
#include "generated/pext_ada.cpp"
#include "generated/pext_adadefs.cpp"
#include "generated/pext_c.cpp"
#include "generated/pext_countries.cpp"
#include "generated/pext_cplusplus.cpp"
#include "generated/pext_cpp.cpp"
#include "generated/pext_go.cpp"
#include "generated/pext_gpc.cpp"
#include "generated/pext_irc.cpp"
#include "generated/pext_java.cpp"
#include "generated/pext_jscript.cpp"
#include "generated/pext_modula.cpp"
#include "generated/pext_modula2.cpp"
#include "generated/pext_modula3.cpp"
#include "generated/pext_pascal.cpp"
#include "generated/pext_sneller.cpp"
#include "generated/pext_snellerbuiltin.cpp"
#include "generated/pext_states.cpp"

void check_all() {
    puts("checking check_ada_pred_hash1");
    check_ada_pred_hash1();
    puts("checking check_ada_pred_hash2");
    check_ada_pred_hash2();
    puts("checking check_ada_pred_hash3");
    check_ada_pred_hash3();
    puts("checking check_ada_pred_hash_sum0");
    check_ada_pred_hash_sum0();
    puts("checking check_ada_pred_hash_sumN");
    check_ada_pred_hash_sumN();
    puts("checking check_ada_pred_hash_djb2");
    check_ada_pred_hash_djb2();
    puts("checking check_ada_pred_hash_sdb");
    check_ada_pred_hash_sdb();
    puts("checking check_ada_res_hash1");
    check_ada_res_hash1();
    puts("checking check_ada_res_hash2");
    check_ada_res_hash2();
    puts("checking check_ada_res_hash3");
    check_ada_res_hash3();
    puts("checking check_ada_res_hash_sum0");
    check_ada_res_hash_sum0();
    puts("checking check_ada_res_hash_sumN");
    check_ada_res_hash_sumN();
    puts("checking check_ada_res_hash_djb2");
    check_ada_res_hash_djb2();
    puts("checking check_ada_res_hash_sdb");
    check_ada_res_hash_sdb();
    puts("checking check_ada_hash1");
    check_ada_hash1();
    puts("checking check_ada_hash2");
    check_ada_hash2();
    puts("checking check_ada_hash3");
    check_ada_hash3();
    puts("checking check_ada_hash_sum0");
    check_ada_hash_sum0();
    puts("checking check_ada_hash_sumN");
    check_ada_hash_sumN();
    puts("checking check_ada_hash_djb2");
    check_ada_hash_djb2();
    puts("checking check_ada_hash_sdb");
    check_ada_hash_sdb();
    puts("checking check_adadefs_hash1");
    check_adadefs_hash1();
    puts("checking check_adadefs_hash2");
    check_adadefs_hash2();
    puts("checking check_adadefs_hash3");
    check_adadefs_hash3();
    puts("checking check_adadefs_hash_sum0");
    check_adadefs_hash_sum0();
    puts("checking check_adadefs_hash_sumN");
    check_adadefs_hash_sumN();
    puts("checking check_adadefs_hash_djb2");
    check_adadefs_hash_djb2();
    puts("checking check_adadefs_hash_sdb");
    check_adadefs_hash_sdb();
    puts("checking check_c_hash1");
    check_c_hash1();
    puts("checking check_c_hash2");
    check_c_hash2();
    puts("checking check_c_hash3");
    check_c_hash3();
    puts("checking check_c_hash_sum0");
    check_c_hash_sum0();
    puts("checking check_c_hash_sumN");
    check_c_hash_sumN();
    puts("checking check_c_hash_djb2");
    check_c_hash_djb2();
    puts("checking check_c_hash_sdb");
    check_c_hash_sdb();
    puts("checking check_countries_hash1");
    check_countries_hash1();
    puts("checking check_countries_hash2");
    check_countries_hash2();
    puts("checking check_countries_hash3");
    check_countries_hash3();
    puts("checking check_countries_hash_sum0");
    check_countries_hash_sum0();
    puts("checking check_countries_hash_sumN");
    check_countries_hash_sumN();
    puts("checking check_countries_hash_djb2");
    check_countries_hash_djb2();
    puts("checking check_countries_hash_sdb");
    check_countries_hash_sdb();
    puts("checking check_cplusplus_hash1");
    check_cplusplus_hash1();
    puts("checking check_cplusplus_hash2");
    check_cplusplus_hash2();
    puts("checking check_cplusplus_hash3");
    check_cplusplus_hash3();
    puts("checking check_cplusplus_hash_sum0");
    check_cplusplus_hash_sum0();
    puts("checking check_cplusplus_hash_sumN");
    check_cplusplus_hash_sumN();
    puts("checking check_cplusplus_hash_djb2");
    check_cplusplus_hash_djb2();
    puts("checking check_cplusplus_hash_sdb");
    check_cplusplus_hash_sdb();
    puts("checking check_cpp_hash1");
    check_cpp_hash1();
    puts("checking check_cpp_hash2");
    check_cpp_hash2();
    puts("checking check_cpp_hash3");
    check_cpp_hash3();
    puts("checking check_cpp_hash_sum0");
    check_cpp_hash_sum0();
    puts("checking check_cpp_hash_sumN");
    check_cpp_hash_sumN();
    puts("checking check_cpp_hash_djb2");
    check_cpp_hash_djb2();
    puts("checking check_cpp_hash_sdb");
    check_cpp_hash_sdb();
    puts("checking check_go_hash1");
    check_go_hash1();
    puts("checking check_go_hash2");
    check_go_hash2();
    puts("checking check_go_hash3");
    check_go_hash3();
    puts("checking check_go_hash_sum0");
    check_go_hash_sum0();
    puts("checking check_go_hash_sumN");
    check_go_hash_sumN();
    puts("checking check_go_hash_djb2");
    check_go_hash_djb2();
    puts("checking check_go_hash_sdb");
    check_go_hash_sdb();
    puts("checking check_gpc_hash1");
    check_gpc_hash1();
    puts("checking check_gpc_hash2");
    check_gpc_hash2();
    puts("checking check_gpc_hash3");
    check_gpc_hash3();
    puts("checking check_gpc_hash_sum0");
    check_gpc_hash_sum0();
    puts("checking check_gpc_hash_sumN");
    check_gpc_hash_sumN();
    puts("checking check_gpc_hash_djb2");
    check_gpc_hash_djb2();
    puts("checking check_gpc_hash_sdb");
    check_gpc_hash_sdb();
    puts("checking check_irc_hash1");
    check_irc_hash1();
    puts("checking check_irc_hash2");
    check_irc_hash2();
    puts("checking check_irc_hash3");
    check_irc_hash3();
    puts("checking check_irc_hash_sum0");
    check_irc_hash_sum0();
    puts("checking check_irc_hash_sumN");
    check_irc_hash_sumN();
    puts("checking check_irc_hash_djb2");
    check_irc_hash_djb2();
    puts("checking check_irc_hash_sdb");
    check_irc_hash_sdb();
    puts("checking check_java_hash1");
    check_java_hash1();
    puts("checking check_java_hash2");
    check_java_hash2();
    puts("checking check_java_hash3");
    check_java_hash3();
    puts("checking check_java_hash_sum0");
    check_java_hash_sum0();
    puts("checking check_java_hash_sumN");
    check_java_hash_sumN();
    puts("checking check_java_hash_djb2");
    check_java_hash_djb2();
    puts("checking check_java_hash_sdb");
    check_java_hash_sdb();
    puts("checking check_jscript_hash1");
    check_jscript_hash1();
    puts("checking check_jscript_hash2");
    check_jscript_hash2();
    puts("checking check_jscript_hash3");
    check_jscript_hash3();
    puts("checking check_jscript_hash_sum0");
    check_jscript_hash_sum0();
    puts("checking check_jscript_hash_sumN");
    check_jscript_hash_sumN();
    puts("checking check_jscript_hash_djb2");
    check_jscript_hash_djb2();
    puts("checking check_jscript_hash_sdb");
    check_jscript_hash_sdb();
    puts("checking check_modula_hash1");
    check_modula_hash1();
    puts("checking check_modula_hash2");
    check_modula_hash2();
    puts("checking check_modula_hash3");
    check_modula_hash3();
    puts("checking check_modula_hash_sum0");
    check_modula_hash_sum0();
    puts("checking check_modula_hash_sumN");
    check_modula_hash_sumN();
    puts("checking check_modula_hash_djb2");
    check_modula_hash_djb2();
    puts("checking check_modula_hash_sdb");
    check_modula_hash_sdb();
    puts("checking check_modula2_hash1");
    check_modula2_hash1();
    puts("checking check_modula2_hash2");
    check_modula2_hash2();
    puts("checking check_modula2_hash3");
    check_modula2_hash3();
    puts("checking check_modula2_hash_sum0");
    check_modula2_hash_sum0();
    puts("checking check_modula2_hash_sumN");
    check_modula2_hash_sumN();
    puts("checking check_modula2_hash_djb2");
    check_modula2_hash_djb2();
    puts("checking check_modula2_hash_sdb");
    check_modula2_hash_sdb();
    puts("checking check_modula3_hash1");
    check_modula3_hash1();
    puts("checking check_modula3_hash2");
    check_modula3_hash2();
    puts("checking check_modula3_hash3");
    check_modula3_hash3();
    puts("checking check_modula3_hash_sum0");
    check_modula3_hash_sum0();
    puts("checking check_modula3_hash_sumN");
    check_modula3_hash_sumN();
    puts("checking check_modula3_hash_djb2");
    check_modula3_hash_djb2();
    puts("checking check_modula3_hash_sdb");
    check_modula3_hash_sdb();
    puts("checking check_pascal_hash1");
    check_pascal_hash1();
    puts("checking check_pascal_hash2");
    check_pascal_hash2();
    puts("checking check_pascal_hash3");
    check_pascal_hash3();
    puts("checking check_pascal_hash_sum0");
    check_pascal_hash_sum0();
    puts("checking check_pascal_hash_sumN");
    check_pascal_hash_sumN();
    puts("checking check_pascal_hash_djb2");
    check_pascal_hash_djb2();
    puts("checking check_pascal_hash_sdb");
    check_pascal_hash_sdb();
    puts("checking check_sneller_hash1");
    check_sneller_hash1();
    puts("checking check_sneller_hash2");
    check_sneller_hash2();
    puts("checking check_sneller_hash3");
    check_sneller_hash3();
    puts("checking check_sneller_hash_sum0");
    check_sneller_hash_sum0();
    puts("checking check_sneller_hash_sumN");
    check_sneller_hash_sumN();
    puts("checking check_sneller_hash_djb2");
    check_sneller_hash_djb2();
    puts("checking check_sneller_hash_sdb");
    check_sneller_hash_sdb();
    puts("checking check_snellerbuiltin_hash1");
    check_snellerbuiltin_hash1();
    puts("checking check_snellerbuiltin_hash2");
    check_snellerbuiltin_hash2();
    puts("checking check_snellerbuiltin_hash3");
    check_snellerbuiltin_hash3();
    puts("checking check_snellerbuiltin_hash_sum0");
    check_snellerbuiltin_hash_sum0();
    puts("checking check_snellerbuiltin_hash_sumN");
    check_snellerbuiltin_hash_sumN();
    puts("checking check_snellerbuiltin_hash_djb2");
    check_snellerbuiltin_hash_djb2();
    puts("checking check_snellerbuiltin_hash_sdb");
    check_snellerbuiltin_hash_sdb();
    puts("checking check_states_hash1");
    check_states_hash1();
    puts("checking check_states_hash2");
    check_states_hash2();
    puts("checking check_states_hash3");
    check_states_hash3();
    puts("checking check_states_hash_sum0");
    check_states_hash_sum0();
    puts("checking check_states_hash_sumN");
    check_states_hash_sumN();
    puts("checking check_states_hash_djb2");
    check_states_hash_djb2();
    puts("checking check_states_hash_sdb");
    check_states_hash_sdb();
    puts("checking check_ada_pred_pext");
    check_ada_pred_pext();
    puts("checking check_ada_res_pext");
    check_ada_res_pext();
    puts("checking check_ada_pext");
    check_ada_pext();
    puts("checking check_adadefs_pext");
    check_adadefs_pext();
    puts("checking check_c_pext");
    check_c_pext();
    puts("checking check_countries_pext");
    check_countries_pext();
    puts("checking check_cplusplus_pext");
    check_cplusplus_pext();
    puts("checking check_cpp_pext");
    check_cpp_pext();
    puts("checking check_go_pext");
    check_go_pext();
    puts("checking check_gpc_pext");
    check_gpc_pext();
    puts("checking check_irc_pext");
    check_irc_pext();
    puts("checking check_java_pext");
    check_java_pext();
    puts("checking check_jscript_pext");
    check_jscript_pext();
    puts("checking check_modula_pext");
    check_modula_pext();
    puts("checking check_modula2_pext");
    check_modula2_pext();
    puts("checking check_modula3_pext");
    check_modula3_pext();
    puts("checking check_pascal_pext");
    check_pascal_pext();
    puts("checking check_sneller_pext");
    check_sneller_pext();
    puts("checking check_snellerbuiltin_pext");
    check_snellerbuiltin_pext();
    puts("checking check_states_pext");
    check_states_pext();
    puts("All OK");
}

int main() {
	check_all();
}
