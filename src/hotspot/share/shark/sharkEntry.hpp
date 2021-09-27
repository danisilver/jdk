/*
 * Copyright (c) 1999, 2010, Oracle and/or its affiliates. All rights reserved.
 * Copyright 2008, 2009 Red Hat, Inc.
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

#ifndef SHARE_SHARK_SHARKENTRY_HPP
#define SHARE_SHARK_SHARKENTRY_HPP

#include "shark/llvmHeaders.hpp"
#include "entry_zero.hpp"

class SharkContext;

class SharkEntry : public ZeroEntry {
 private:
  address         _code_limit;
  SharkContext*   _context;
  llvm::Function* _function;
  llvm::orc::ResourceTrackerSP _rt;

 public:
  address code_start() const {
    return entry_point();
  }
  address code_limit() const {
    return _code_limit;
  }
  SharkContext* context() const {
    return _context;
  }
  llvm::Function* function() const {
    return _function;
  }
  llvm::orc::ResourceTrackerSP get_RT() {
    return _rt;
  }

 public:
  void set_code_limit(address code_limit) {
    _code_limit = code_limit;
  }
  void set_context(SharkContext* context) {
    _context = context;
  }
  void set_function(llvm::Function* function) {
    _function = function;
  }
  void set_RT(llvm::orc::ResourceTrackerSP RT) {
    _rt = RT;
  }
};

#endif // SHARE_SHARK_SHARKENTRY_HPP
