/*
 * Copyright (c) 2000, 2010, Oracle and/or its affiliates. All rights reserved.
 * Copyright 2008, 2009, 2010 Red Hat, Inc.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_SHARK_SHARK_GLOBALS_HPP
#define SHARE_VM_SHARK_SHARK_GLOBALS_HPP

#include "runtime/globals.hpp"
#include "runtime/globals_shared.hpp"
#include "utilities/macros.hpp"
#ifdef TARGET_ARCH_zero
# include "shark_globals_zero.hpp"
#endif

#define SHARK_FLAGS(develop,                                                  \
                   develop_pd,                                                \
                   product,                                                   \
                   product_pd,                                                \
                   notproduct,                                                \
                   range,                                                     \
                   constraint)                                                \
                                                                              \
  product(intx, MaxNodeLimit, 65000,                                          \
          "Maximum number of nodes")                                          \
                                                                              \
  /* inlining */                                                              \
  product(intx, SharkMaxInlineSize, 32,                                       \
          "Maximum bytecode size of methods to inline when using Shark")      \
                                                                              \
  product(bool, EliminateNestedLocks, true,                                   \
          "Eliminate nested locks of the same object when possible")          \
                                                                              \
  product(ccstr, SharkOptimizationLevel, "Default",                           \
          "The optimization level passed to LLVM, possible values: None, Less, Default and Agressive") \
                                                                              \
  /* compiler debugging */                                                    \
  develop(ccstr, SharkPrintTypeflowOf, NULL,                                  \
          "Print the typeflow of the specified method")                       \
                                                                              \
  product(ccstr, SharkPrintBitcodeOf, NULL, DIAGNOSTIC,                       \
          "Print the LLVM bitcode of the specified method")                   \
                                                                              \
  product(ccstr, SharkPrintAsmOf, NULL, DIAGNOSTIC,                           \
          "Print the asm of the specified method")                            \
                                                                              \
  develop(bool, SharkTraceBytecodes, false,                                   \
          "Trace bytecode compilation")                                       \
                                                                              \
  product(bool, SharkTraceInstalls, false, DIAGNOSTIC,                        \
          "Trace method installation")                                        \
                                                                              \
  product(bool, SharkPerformanceWarnings, false, DIAGNOSTIC,                  \
          "Warn about things that could be made faster")                      \
                                                                              \
  develop(ccstr, SharkVerifyFunction, NULL,                                   \
          "Runs LLVM verify over LLVM IR")                                    \


  DECLARE_FLAGS(SHARK_FLAGS)
//SHARK_FLAGS(DECLARE_DEVELOPER_FLAG, DECLARE_PD_DEVELOPER_FLAG, DECLARE_PRODUCT_FLAG, DECLARE_PD_PRODUCT_FLAG, DECLARE_DIAGNOSTIC_FLAG, DECLARE_NOTPRODUCT_FLAG)

#endif // SHARE_VM_SHARK_SHARK_GLOBALS_HPP
