/*
 ***********************************************************************************************************************
 *
 *  Copyright (c) 2020-2021 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *
 **********************************************************************************************************************/
/**
 ***********************************************************************************************************************
 * @file  llpcSpirvLowerRayTracingIntrinsics.h
 * @brief LLPC header file: contains declaration of Llpc::SpirvLowerRayTracingIntrinsics
 ***********************************************************************************************************************
 */

#pragma once

#include "llpcSpirvLower.h"
#include "llvm/IR/InstVisitor.h"

namespace Llpc {
// =====================================================================================================================
// Represents the pass of SPIR-V lowering ray tracing intrinsics.
class SpirvLowerRayTracingIntrinsics : public LegacySpirvLower, public llvm::InstVisitor<SpirvLowerRayTracingIntrinsics> {
public:
  SpirvLowerRayTracingIntrinsics() : LegacySpirvLower(ID) {}
  SpirvLowerRayTracingIntrinsics(char &pid) : LegacySpirvLower(pid) {}
  virtual bool runOnModule(llvm::Module &module);

  static char ID; // ID of this pass

protected:
  void createLoadDwordAtAddr(llvm::Function *func, llvm::Type *loadPtrTy);
  void createConvertF32toF16(llvm::Function *func, unsigned roundingMode);

private:
  SpirvLowerRayTracingIntrinsics(const SpirvLowerRayTracingIntrinsics &) = delete;
  SpirvLowerRayTracingIntrinsics &operator=(const SpirvLowerRayTracingIntrinsics &) = delete;

  bool processIntrinsicsFuncion(llvm::Function *func);
};
} // namespace Llpc
