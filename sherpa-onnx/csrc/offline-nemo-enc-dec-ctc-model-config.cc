// sherpa-onnx/csrc/offline-nemo-enc-dec-ctc-model-config.cc
//
// Copyright (c)  2023  Xiaomi Corporation

#include "sherpa-onnx/csrc/offline-nemo-enc-dec-ctc-model-config.h"

#include "sherpa-onnx/csrc/file-utils.h"
#include "sherpa-onnx/csrc/macros.h"

namespace sherpa_onnx {

void OfflineNemoEncDecCtcModelConfig::Register(ParseOptions *po) {
  po->Register("nemo-ctc-model", &model,
               "Path to model.onnx of Nemo EncDecCtcModel.");
}

bool OfflineNemoEncDecCtcModelConfig::Validate() const {
  if (!FileExists(model)) {
    SHERPA_ONNX_LOGE("%s does not exist", model.c_str());
    return false;
  }

  return true;
}

std::string OfflineNemoEncDecCtcModelConfig::ToString() const {
  std::ostringstream os;

  os << "OfflineNemoEncDecCtcModelConfig(";
  os << "model=\"" << model << "\")";

  return os.str();
}

}  // namespace sherpa_onnx
