/******************************************************************************
 * Copyright 2017 The xies Authors. All Rights Reserved.
 *
 * 宏定义，单列模式
 * 
 *****************************************************************************/


#ifndef MODULES_COMMON_MACRO_H_
#define MODULES_COMMON_MACRO_H_

#include <iomanip>
#include <iostream>

#define DISALLOW_COPY_AND_ASSIGN(classname) \
 private:                                   \
  classname(const classname &);             \
  classname &operator=(const classname &);

#define DISALLOW_IMPLICIT_CONSTRUCTORS(classname) \
 private:                                         \
  classname();                                    \
  DISALLOW_COPY_AND_ASSIGN(classname);

#define DECLARE_SINGLETON(classname)        \
 public:                                    \
  static classname *instance() {            \
    static classname instance;              \
    return &instance;                       \
  }                                         \
  DISALLOW_IMPLICIT_CONSTRUCTORS(classname) \
 private:
#endif  // MODULES_COMMON_MACRO_H_
