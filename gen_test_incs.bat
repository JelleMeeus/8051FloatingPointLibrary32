@echo off
fpcalc -5e6 5e6 + p 20>test_inc\f32_asmd_add_test.inc
fpcalc -5e6 5e6 - p 20>test_inc\f32_asmd_sub_test.inc
fpcalc -5e6 5e6 x p 20>test_inc\f32_asmd_mul_test.inc
fpcalc -5e6 5e6 / p 20>test_inc\f32_asmd_div_test.inc

fpcalc -5e6 5e6 + a 20>test_inc\f32_asmd_test.inc